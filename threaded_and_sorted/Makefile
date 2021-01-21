CPP=g++
CFLAGS:=-O3 -Wall -Wextra -std=c++17 -pthread
ifdef DEBUG
	CFLAGS+=-DDEBUG -Og -g -rdynamic
endif

objects = TimestampedItem.o ThreadedAndSortedTimestamps.o

all: ${objects} main.o
	${CPP} ${CFLAGS} -o threaded_and_sorted.x main.o ${objects}

%.o: %.cpp
	${CPP} ${CFLAGS} -c $< -o $@

.PHONY.: clean
clean:
	rm -f *.o *.x

ThreadedAndSortedTimestamps.o: TimestampedItem.hpp
