CC = g++
SRC_FILES = ../bin/die.cpp ../bin/dice.cpp ../bin/ScoreCard.cpp ../bin/game.cpp


all: INCLUDE = -I../bin
all: TARGET = yahtzee
all: SRC = ../src/main.cpp

tests: INCLUDE = -I../bin -I../tests
tests: TARGET = tests
tests: SRC = ../tests/tests.cpp ../tests/ScorecardTests.cpp ../tests/dieTest.cpp ../tests/diceTest.cpp ../tests/gameTests.cpp

all:
	$(CC) $(SRC) $(INCLUDE) $(SRC_FILES) -o $(TARGET)

tests:
	$(CC) $(SRC) $(INCLUDE) $(SRC_FILES) -o $(TARGET)

clean:
	rm yahtzee tests -f
