CPP=g++
CFLAGS:=-O3 -Wall -Wextra -std=c++17 -pthread
ifdef DEBUG
	CFLAGS+=-DDEBUG -Og -g -rdynamic
endif

objects = main.o

all: ${objects}
	${CPP} ${CFLAGS} -o manipulate.x ${objects}

%.o: %.cpp
	${CPP} ${CFLAGS} -c $< -o $@

.PHONY.: clean
clean:
	rm -f *.o *.x
