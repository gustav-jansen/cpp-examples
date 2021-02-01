CPP=g++
CFLAGS:=-O3 -Wall -Wextra -std=c++11 -pthread
ifdef DEBUG
	CFLAGS+=-DDEBUG -Og -g -rdynamic
endif

all: ${objects} main.o
	${CPP} ${CFLAGS} -o getopt_example.x main.o ${objects}

%.o: %.cpp
	${CPP} ${CFLAGS} -c $< -o $@

.PHONY.: clean
clean:
	rm -f *.o *.x
