CC = g++
SRC_FILES = ../bin/die.cpp

all: INCLUDE = -I../bin
all: TARGET = yahtzee
all: SRC = ../src/main.cpp

tests: INCLUDE = -I../bin -I../tests
tests: TARGET = tests
tests: SRC = ../tests/tests.cpp

all:
	$(CC) $(SRC) $(INCLUDE) $(SRC_FILES) -o $(TARGET)

tests:
	$(CC) $(SRC) $(INCLUDE) $(SRC_FILES) -o $(TARGET) ../tests/gameTests.cpp

clean:
	rm yahtzee tests -f
