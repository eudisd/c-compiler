# C Virtual Machine - Makefile
# By Eudis Duran

TARGET := bin/cvm.exe
CC := gcc
LIBS := -lm
FLAGS := -Wall -O2

FILES := cvm.c cvm.h

.IGNORE:
.SILENT:

msg1:
	@echo 
	@echo "Building C Virtual Machine..."
	make $(TARGET)
	
$(TARGET) : cvm.o
	$(CC) $(FLAGS) cvm.o -o $(TARGET) $(LIBS)
	-rm *.o
	@echo "Done Building C VM."
	
cvm.o : cvm.c cvm.h
	@echo "(Modified) Compiling Translation Unit: cvm/cvm.c + cvm/cvm.h"
	$(CC) -c cvm.c -o cvm.o
	
	

