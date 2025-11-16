# A simple Makefile
# Defines the C compiler to use
CC=gcc
# Sets compiler flags: -Wall enables all warnings, which is good practice
CFLAGS=-Wall

# A variable holding all the final executable files we want to create
TARGETS=build/01-catch-sigint build/02-ignore-signal build/sender build/receiver

# This is the default target. Running 'make' or 'make all' will run this.
# It tells make that 'all' depends on the files listed in the TARGETS variable.
all: $(TARGETS)

# This is a build rule for the first target.
# It says: to make 'build/01-catch-sigint', you need 'src/01-catch-sigint.c'
# The command 'gcc -Wall -o build/01-catch-sigint src/01-catch-sigint.c' is run.
# '$@' is a special variable meaning "the target name" (build/01-catch-sigint)
# '$^' is a special variable meaning "all the prerequisites" (src/01-catch-sigint.c)
build/01-catch-sigint: src/01-catch-sigint.c
	$(CC) $(CFLAGS) -o $@ $^

# Build rule for the second target
build/02-ignore-signal: src/02-ignore-signal.c
	$(CC) $(CFLAGS) -o $@ $^

# Build rule for the sender
build/sender: src/03-ipc-demo/sender.c
	$(CC) $(CFLAGS) -o $@ $^

# Build rule for the receiver
build/receiver: src/03-ipc-demo/receiver.c
	$(CC) $(CFLAGS) -o $@ $^

# This is a "phony" target. It's not a file, just a command name.
# It's used to clean up the compiled files from the build/ directory.
clean:
	rm -f build/*

# This line tells 'make' that 'clean' and 'all' are not files.
# It's good practice.
.PHONY: all clean
