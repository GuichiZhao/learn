nasm -f elf -d ELF_TYPE  asm_io.asm
nasm -f elf first.asm
gcc -m32  first.o driver.c asm_io.o  -o first
./first
# echo $?