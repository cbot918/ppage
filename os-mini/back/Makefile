ipl.bin: ipl.nas Makefile
	./tools/nask.exe ipl.nas ipl.bin ipl.lst

helloos.img: ipl.bin Makefile
	./tools/edimg.exe imgin:./tools/fdimg0at.tek \
		wbinimg src:ipl.bin len:512 from:0 to:0 imgout:helloos.img

run: helloos.img
	./tools/qemu.exe -L . -std-vga helloos.img