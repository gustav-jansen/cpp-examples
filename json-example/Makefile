CPP=g++
CFLAGS:=-O3 -Wall -Wextra -std=c++17 -pthread
ifdef DEBUG
	CFLAGS+=-DDEBUG -Og -g -rdynamic
endif

INCLUDE = -I${RAPIDJSON_DIR}/include

CFLAGS += ${INCLUDE}

objects = message.o main.o

all: ${objects}
	${CPP} ${CFLAGS} -o json_example.x ${objects}

%.o: %.cpp
	${CPP} ${CFLAGS} -c $< -o $@

.PHONY.: clean
clean:
	rm -f *.o *.x

message.o : DecompConfig.hpp FWBufferConfig.hpp ConductorConfig.hpp EventBuilderConfig.hpp

main.o : message.hpp DecompConfig.hpp FWBufferConfig.hpp ConductorConfig.hpp EventBuilderConfig.hpp
