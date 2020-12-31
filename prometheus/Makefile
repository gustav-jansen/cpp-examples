CPP=g++
CFLAGS:=-O3 -Wall -Wextra -std=c++17 -pthread
ifdef DEBUG
	CFLAGS+=-DDEBUG -Og -g -rdynamic
endif

CFLAGS += ${INCLUDE}

objects = main.o

all: ${objects}
	${CPP} ${CFLAGS} -o prometheus_example.x ${objects} -lprometheus-cpp-pull -lprometheus-cpp-core

%.o: %.cpp
	${CPP} ${CFLAGS} -c $< -o $@

.PHONY.: clean
clean:
	rm -f *.o *.x
