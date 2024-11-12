CC=arm-none-eabi-gcc
OBJ=arm-none-eabi-objcopy
MACH=cortex-m33
CFLAGS= -c -mcpu=$(MACH) -std=gnu11 -mthumb -Wall -O0
LFLAGS= -nostdlib -T linker.ld -Wl,-Map=final.map

all:
	make clean
	make link
	make hex

main.o: main.c
	$(CC) $(CFLAGS) -o $@ $^

isr_vector.o: isr_vector.s
	$(CC) $(CFLAGS) -o $@ $^

final.elf: isr_vector.o main.o
	$(CC) $(LFLAGS) -o $@ $^

clean:
	rm -f $(wildcard *.o)
	rm -f $(wildcard *.elf)
	rm -f $(wildcard *.uf2)
	rm -f $(wildcard *.map)
	rm -f $(wildcard *.hex)

link: final.elf

uf2: 
	~/pico/elf2uf2/elf2uf2 final.elf final.uf2

hex:
	$(OBJ) -O ihex final.elf final.hex 
