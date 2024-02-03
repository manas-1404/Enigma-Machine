# Makefile for rotorMachine program
# Compiler
CC = g++

# Compiler flags (Wall: Enable most warning messages, g: Generate debugging information)
CFLAGS = -Wall -g

# The default target 'all' specifies that 'rotorMachine' should be built when 'make' is invoked without a target. It depends on 'rotorMachine' target.
all: rotorMachine

# The 'rotorMachine' target depends on 'rotorMachine.o' and 'srinivasgowda_manas_assn3.o' targets.It links the object files to create the executable 'rotorMachine'.
rotorMachine: rotorMachine.o srinivasgowda_manas_assn3.o
	$(CC) $(CFLAGS) $^ -o $@

# The 'rotorMachine.o' target depends on 'rotorMachine.c' and 'rotorMachine.h' files. It compiles 'rotorMachine.c' to create 'rotorMachine.o'.
rotorMachine.o: rotorMachine.c rotorMachine.h
	$(CC) $(CFLAGS) -c $<

# The 'srinivasgowda_manas_assn3.o' target depends on 'srinivasgowda_manas_assn3.c' and 'rotorMachine.h' files. It compiles 'srinivasgowda_manas_assn3.c' to create 'srinivasgowda_manas_assn3.o'.
srinivasgowda_manas_assn3.o: srinivasgowda_manas_assn3.c rotorMachine.h
	$(CC) $(CFLAGS) -c $<

# The 'clean' target removes the 'rotorMachine' executable and all object files.
clean:
	rm -f rotorMachine *.o