CPP=g++
CFLAGS:=-O3 -Wall -Wextra -std=c++17 -pthread
ifdef DEBUG
	CFLAGS+=-DDEBUG -Og -g -rdynamic
endif

INCLUDE = -I${RAPIDJSON_DIR}/include

CFLAGS += ${INCLUDE}

objects = message.o

all: ${objects} main.o
	${CPP} ${CFLAGS} -o json_example.x main.o ${objects}

%.o: %.cpp
	${CPP} ${CFLAGS} -c $< -o $@

.PHONY.: clean
clean:
	rm -f *.o *.x
