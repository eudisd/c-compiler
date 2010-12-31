# C Compiler Makefile
# By Eudis Duran


TARGET := bin/c.exe
CC := gcc
LIBS := -lm
FLAGS := -Wall -O2

FILES := main.c main.h error.c error.h parser.c parser.h scanner.c scanner.h symbol.c symbol.h

OBJS := main.o error.o parser.o scanner.o symbol.o

.SILENT:
.IGNORE:

msg1:
	@echo "Working..."
	make $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(TARGET) $(LIBS)
	@echo 
	@echo "Done "
	
	
main.o : main.c main.h
	@echo "(Modified) Compiling Translation Unit: main.c + main.h"
	$(CC) -c main.c -o main.o

error.o : error.c error.h
	@echo "(Modified) Compiling Translation Unit: error.c + error.h"
	$(CC) -c error.c -o error.o
	
parser.o : parser.c parser.h
	@echo "(Modified) Compiling Translation Unit: parser.c + parser.h"
	$(CC) -c parser.c -o parser.o
	
scanner.o : scanner.c scanner.h
	@echo "(Modified) Compiling Translation Unit: scanner.c + scanner.h"
	$(CC) -c scanner.c -o scanner.o
	
symbol.o : symbol.c symbol.h
	@echo "(Modified) Compiling Translation Unit: symbol.c + symbol.h"
	$(CC) -c symbol.c -o symbol.o
	
.PHONE : clean

clean :
	make -f Makefile
	-rm *.o
	@echo 

