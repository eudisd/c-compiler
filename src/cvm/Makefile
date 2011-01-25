# C Virtual Machine Makefile

# By Eudis Duran

CC    := gcc
LIBS  := -lm
FLAGS := -Wall -O2

OBJS := cvm.o

TARGET:=cvm

$(TARGET) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(TARGET) $(LIBS)
	@echo 
	@echo "Done Building C Virtual Machine."
	@-rm *.o
	@-mv $(TARGET) ../../bin  
	@echo	

cvm.o : cvm.c cvm.h
	@echo "(Modified) Compiling Translation Unit: cvm.c + cvm.h"
	$(CC) -c cvm.c -o cvm.o
