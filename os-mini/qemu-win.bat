@REM @set SDL_VIDEODRIVER=windib
@REM @set QEMU_AUDIO_DRV=none
@REM @set QEMU_AUDIO_LOG_TO_MONITOR=0
@REM .\tools\qemu.exe -L . -m 32 -localtime -std-vga -fda helloos.img
.\tools\qemu.exe -L . -std-vga helloos.img