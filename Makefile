all:
		nasm -f elf white.asm
		nasm -f elf yellow.asm
		nasm -f elf cyan.asm
		nasm -f elf green.asm
		nasm -f elf magenta.asm
		nasm -f elf red.asm
		nasm -f elf blue.asm
		nasm -f elf black.asm
		gcc -Wall main.c white.o yellow.o cyan.o green.o magenta.o red.o blue.o black.o
