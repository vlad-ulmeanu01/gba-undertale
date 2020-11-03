set path=C:\devkitadv\bin;%path%
gcc -o undertale.elf undertale.c -lm
objcopy -O binary undertale.elf undertale.gba
pause
