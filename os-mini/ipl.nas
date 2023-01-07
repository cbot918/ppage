; hello-os
; TAB=4


CYLS	EQU		10				; define const (cyls = cylinders)

		ORG		0x7c00			; program put in 0x7c00, google "osdev bios"

; point out standard FAT12 Floppy Disk
		JMP		entry
		DB		0x90
		DB		"HELLOIPL"		; �u�[�g�Z�N�^�̖��O�����R�ɏ����Ă悢�i8�o�C�g�j
		DW		512				; 1�Z�N�^�̑傫���i512�ɂ��Ȃ���΂����Ȃ��j
		DB		1				; �N���X�^�̑傫���i1�Z�N�^�ɂ��Ȃ���΂����Ȃ��j
		DW		1				; FAT���ǂ�����n�܂邩�i���ʂ�1�Z�N�^�ڂ���ɂ���j
		DB		2				; FAT�̌��i2�ɂ��Ȃ���΂����Ȃ��j
		DW		224				; ���[�g�f�B���N�g���̈�̑傫���i���ʂ�224�G���g���ɂ���j
		DW		2880			; ���̃h���C�u�̑傫���i2880�Z�N�^�ɂ��Ȃ���΂����Ȃ��j
		DB		0xf0			; ���f�B�A�̃^�C�v�i0xf0�ɂ��Ȃ���΂����Ȃ��j
		DW		9				; FAT�̈�̒����i9�Z�N�^�ɂ��Ȃ���΂����Ȃ��j
		DW		18				; 1�g���b�N�ɂ����̃Z�N�^�����邩�i18�ɂ��Ȃ���΂����Ȃ��j
		DW		2				; �w�b�h�̐��i2�ɂ��Ȃ���΂����Ȃ��j
		DD		0				; �p�[�e�B�V�������g���ĂȂ��̂ł����͕K��0
		DD		2880			; ���̃h���C�u�傫����������x����
		DB		0,0,0x29		; �悭�킩��Ȃ����ǂ��̒l�ɂ��Ă����Ƃ����炵��
		DD		0xffffffff		; ���Ԃ�{�����[���V���A���ԍ�
		DB		"HELLO-OS   "	; �f�B�X�N�̖��O�i11�o�C�g�j
		DB		"FAT12   "		; �t�H�[�}�b�g�̖��O�i8�o�C�g�j
		RESB	18				; �Ƃ肠����18�o�C�g�����Ă���

; main program

entry:
		MOV		AX,0			; initial register
		MOV		SS,AX
		MOV		SP,0x7c00
		MOV		DS,AX

		; MOV		ES,AX
		; MOV		SI,msg

; 讀磁盤, 讀入 10 x 2 x 18 x 512 = 184320 byte = 180KB
; 放到記憶體 0x08200 ~ 0x34fff 內
		MOV		AX,0x0820
		MOV		ES,AX
		MOV		CH,0			; 柱面0
		MOV		DH,0			; 磁頭0
		MOV		CL,2			; 扇區2

readloop:
		MOV		SI,0			; 紀錄失敗次數

; 如果出錯, 就重置A驅動器
retry:
		MOV		AH,0x02			; AH=0x02 : 讀盤
		MOV		AL,1			; 1個扇區
		MOV		BX,0
		MOV		DL,0x00			; A驅動器
		INT		0x13			; 調用磁盤BIOS(disk access)
		JNC		next			; 沒出錯的話跳到next (jump if not carry)
		ADD		SI,1			; 往SI加1
		CMP		SI,5			; 比較SI跟5
		JAE		error			; SI >= 5時, 跳轉到error (jump if above equal)
		MOV		AH,0x00			
		MOV		DL,0x00			; A驅動器
		INT		0x13			; 重置驅動器
		JMP		retry
		
next:
		MOV		AX,ES			; 內存地址往後0x200
		ADD		AX,0x0020		; ES加上0x0020 相當於地址往後0x200
		MOV		ES,AX			; 與前兩行為了做 ADD ES,0x020 繞彎一下
		ADD		CL,1			; 往CL裡+1
		CMP		CL,18			; 比較CL與18
		JBE		readloop		; 如果CL <= 18, 跳到readloop (jump if below or equal)
		MOV		CL,1
		MOV		DH,1
		CMP		DH,2
		JB		readloop		; 如果DH < 2, 則跳到readloop
		MOV		DH,0
		ADD		CH,1
		CMP		CH,CYLS
		JB		readloop		; 如果CH < CYLS, 則跳到readloop (jump if below)

putloop:
		MOV		AL,[SI]
		ADD		SI,1			; SI += 1
		CMP		AL,0
		JE		fin
		MOV		AH,0x0e			; display one char, google "osdev bios" 
		MOV		BX,15			; char color
		INT		0x10			; INTERRUPT to BIOS VGA, google "osdev bios"
		JMP		putloop			; loop



error:
		MOV		SI,msg

fin:
		HLT						; cpu halt until user interrupt
		JMP		fin				; loop

msg:
		DB		0x0a, 0x0a		; newline, newline
		DB		"hello, world"
		DB		0x0a			; newline
		DB		0

		RESB	0x7dfe-$		; fill to 512 byte

		DB		0x55, 0xaa
