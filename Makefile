all: kernel link iso

kernel:
	@nasm -f elf64 ./src/boot.asm -o ./build/boot.asm.o
	@nasm -f elf64 ./src/multiboot_header.asm -o ./build/multiboot_header.asm.o
	@gcc -m64 -c ./src/kernel.c -o ./build/kernel.c.o
link:
	ld -m elf_x86_64 -T ./src/link.ld -o ./build/isofiles/boot/kernel  ./build/multiboot_header.asm.o ./build/boot.asm.o ./build/kernel.c.o

iso:
	grub-mkrescue -o os.iso ./build/isofiles