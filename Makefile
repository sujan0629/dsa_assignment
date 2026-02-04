# Makefile for DSA Assignment 2

CC = gcc
CFLAGS = -Wall -Wextra -g
TARGETS = prog_1 prog_2 prog_3 prog_4 prog_5 prog_6 prog_7 prog_8

all: $(TARGETS)

prog_1: prog_1.c
$(CC) $(CFLAGS) prog_1.c -o prog_1

prog_2: prog_2.c
$(CC) $(CFLAGS) prog_2.c -o prog_2

prog_3: prog_3.c
$(CC) $(CFLAGS) prog_3.c -o prog_3

prog_4: prog_4.c
$(CC) $(CFLAGS) prog_4.c -o prog_4

prog_5: prog_5.c
$(CC) $(CFLAGS) prog_5.c -o prog_5

prog_6: prog_6.c
$(CC) $(CFLAGS) prog_6.c -o prog_6

prog_7: prog_7.c
$(CC) $(CFLAGS) prog_7.c -o prog_7

prog_8: prog_8.c
$(CC) $(CFLAGS) prog_8.c -o prog_8

clean:
rm -f $(TARGETS) *.o *.exe *.out

run_%: prog_%
./prog_$*

.PHONY: all clean
