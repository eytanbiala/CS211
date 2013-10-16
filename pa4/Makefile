COMPILER = gcc

all: cachesize cacheblock

cachesize: cachesize.o
	$(COMPILER) -o cachesize cachesize.o

cacheblock: cacheblock.o
	$(COMPILER) -o cacheblock cacheblock.o

cachesize.o: cachesize.c cachesize.h
	$(COMPILER) -c cachesize.c cachesize.h

cacheblock.o: cacheblock.c cacheblock.h
	$(COMPILER) -c cacheblock.c cacheblock.h

clean:
	rm *.o *.h.gch