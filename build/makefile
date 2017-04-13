CC = g++
SRC_FILES = ../include/die.cpp

all: INCLUDE = -I../include
all: TARGET = yahtzee
all: SRC = ../src/main.cpp

tests: INCLUDE = -I../include -I../tests
tests: TAGRET = tests
tests: SRC = ../tests/tests.cpp

all:
	$(CC) $(SRC) $(INCLUDE) $(SRC_FILES) -o $(TARGET)

tests:
	$(CC) $(SRC) $(INCLUDE) $(SRC_FILES) -o $(TARGET)

clean:
	rm yahtzee tests -f
