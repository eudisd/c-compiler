# C - Compiler Makefile

CC    := gcc
LIBS  := -lm
FLAGS := -Wall -O2 -g

OBJS := main.o error.o parser.o scanner.o symbol.o preprocessor.o semantic.o  utils.o stack.o

TARGET:=c

$(TARGET) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(TARGET) $(LIBS)
	@echo 
	@echo "Done Building C Compiler."
	@-rm *.o
	@-cp ./$(TARGET) ../../bin  
	@-cp ./$(TARGET) ../../examples/bin
	@echo	
	
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
	
preprocessor.o : preprocessor.c preprocessor.h
	@echo "(Modified) Compiling Translation Unit: preprocessor.c + preprocessor.h"
	$(CC) -c preprocessor.c -o preprocessor.o
	
utils.o : utils.c utils.h
	@echo "(Modified) Compiling Translation Unit: utils.c + utils.h"
	$(CC) -c utils.c -o utils.o

stack.o : stack.c stack.h
	@echo "(Modified) Compiling Translation Unit: stack.c + stack.h"
	$(CC) -c stack.c -o stack.o
	
	
