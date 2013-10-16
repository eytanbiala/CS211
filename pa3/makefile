COMPILER = gcc

all: mysFunc

mysFunc: mysFunc.o mystery.o
	$(COMPILER) -o mysFunc mysFunc.o mystery.o

mystery.o: mystery.c mystery.h
	$(COMPILER) -c mystery.c mystery.h

mysFunc.o: mysFunc.c
	$(COMPILER) -c mysFunc.c

clean:
	rm -f mysFunc *.o
