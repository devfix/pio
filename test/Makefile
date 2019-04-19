#	avr-gcc -S -DF_CPU=16000000 -mmcu=atmega16 -DPIO_DISABLE_I2C main.c -O1 && mv main.s main.asm
#	avr-gcc -E -DF_CPU=16000000 -mmcu=atmega16 -DPIO_DISABLE_I2C main.c -O1

# Name: Makefile
# Project: PIO
# Author: Tristan Krause
# Creation Date: 2019-04-18

# Environment
COMPILER_PATH = avr-gcc

# Optionen
OUTPUT     = main.elf
MCU	       = atmega16
CFLAGS     = -Wall -Wextra -std=c11 -O0 -mmcu=$(MCU) -DF_CPU=8000000
LDFLAGS    = 
OBJECTS    = main.o ext.o


COMPILE = $(COMPILER_PATH) $(CFLAGS)

main: $(OBJECTS)
	@echo "Linking..."
	$(COMPILE) $(OBJECTS) -o $(OUTPUT) $(LDFLAGS)

help:
	@echo "This Makefile has the following rules:"
	@echo "make main .... to compile (default)"
	@echo "make clean ... to delete objects, elf and hex file"
	
clean:
	@echo "Cleaning..."
	rm -f $(OBJECTS) $(OUTPUT) *.asm *.o.c

.c.o:
	$(COMPILE) -c $< -o $@
	$(COMPILE) -E $< -o $@.c
	$(COMPILE) -S $< -o $@.asm
