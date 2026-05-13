all: build run

build:
	nasm -f elf32 boot/boot.asm -o boot.o

	gcc -m32 -ffreestanding \
	-c kernel/kernel.c -o kernel.o

	gcc -m32 -ffreestanding \
	-c kernel/screen.c -o screen.o

	ld -m elf_i386 \
	-T linker.ld \
	-o kernel.bin \
	boot.o kernel.o screen.o

	cp kernel.bin iso/boot/kernel.bin

	grub-mkrescue -o myos.iso iso

run:
	qemu-system-x86_64 -cdrom myos.iso

clean:
	rm -f *.o *.bin *.iso