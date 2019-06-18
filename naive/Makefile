CCC=g++

TARGET=sm_naive

all: src/${TARGET}.cpp
	$(CCC) -g -Wall -o ${TARGET} src/${TARGET}.cpp

${TARGET}: src/${TARGET}.cpp
	$(CCC) -g -Wall -o ${TARGET} src/${TARGET}.cpp

clean:
	rm --force ${TARGET}
