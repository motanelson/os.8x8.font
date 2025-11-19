
printf "\033c\033[43;30m\n"
riscv64-linux-gnu-gcc -lgcc -c  kernel.c -o kernel.o 
riscv64-linux-gnu-as -c entry.S -o entry.o 
riscv64-linux-gnu-ld -T linker.ld -nostdlib kernel.o entry.o -o kernel.elf 
qemu-system-riscv64 -machine virt -bios none -kernel kernel.elf -serial mon:stdio 