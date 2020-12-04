CPP=g++
CFLAGS:=-O3 -Wall -Wextra -std=c++17 -pthread
ifdef DEBUG
	CFLAGS+=-DDEBUG -Og -g -rdynamic
endif

objects = message.o

all: ${objects} main.o
	${CPP} ${CFLAGS} -o curl_example.x main.o ${objects} -lcurl

%.o: %.cpp
	${CPP} ${CFLAGS} -c $< -o $@

.PHONY.: clean
clean:
	rm -f *.o *.x
