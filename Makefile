# $@ = target file
# $< = first dependency
# $^ = all dependencies

export SOURCE_DIR = $(abspath src)
export BUILD_DIR = $(abspath build)

C_SOURCES = $(wildcard kernel/*.cpp drivers/*.cpp)
HEADERS = $(wildcard kernel/*.h drivers/*.h)
# Nice syntax for file extension replacement
OBJ = ${C_SOURCES:.cpp=.o}

# Change this if your cross-compiler is somewhere else
CC = i686-elf-g++
GDB = i686-elf-gdb
# -g: Use debugging symbols in gcc
CFLAGS = -g

# First rule is run by default
osis.bin: bootloader/bootsect.bin kernel.bin
	cat $^ > osis.bin

# '--oformat binary' deletes all symbols as a collateral, so we don't need
# to 'strip' them manually on this case
kernel.bin: bootloader/kernel_entry.o ${OBJ}
	i686-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary

# Used for debugging purposes
kernel.elf: bootloader/kernel_entry.o ${OBJ}
	i686-elf-ld -o $@ -Ttext 0x1000 $^ 

run: osis.bin
	qemu-system-i386 -fda osis.bin

# Open the connection to qemu and load our kernel-object file with symbols
debug: osis.bin kernel.elf
	qemu-system-i386 -s -fda osis.bin &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"

# Generic rules for wildcards
# To make an object, always compile from its .c
%.o: %.cpp ${HEADERS}
	${CC} ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm -rf *.bin *.dis *.o osis.bin *.elf
	rm -rf kernel/*.o boot/*.bin drivers/*.o boot/*.o
