# C Virtual Machine - Makefile
# By Eudis Duran

TARGET := cvm.exe
CC := gcc
LIBS := -lm
FLAGS := -Wall -O2

FILES := cvm.c cvm.h

$(TARGET) : cvm.o
	$(CC) $(FLAGS) cvm.o -o $(TARGET) $(LIBS)
	
cvm.o : cvm.c cvm.o
	@echo "(Modified) Compiling Translation Unit: cvm.c + cvm.h"
	$(CC) -c cvm.c -o cmv.o
	

