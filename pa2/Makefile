######################################
# CS211 sample makefile
######################################

COMPILER = gcc
# CCFLAGS  = -ansi -pedantic -Wall
all: dataConverter

debug:
	make DEBUG=TRUE

prefixStat: prefixStat.o
	$(COMPILER) $(CCFLAGS) -o dataConverter dataConverter.o
prefixStat.o: prefixStat.c prefixStat.h
	$(COMPILER) $(CCFLAGS) -c dataConverter.c dataConverter.h

ifeq ($(DEBUG), TRUE)
 CCFLAGS += -g
endif

clean:
	rm -f dataConverter
	rm -f *.o