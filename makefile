# These are the variables that will be used for compiling the code
CC=g++
CCFLAGS=-std=c++2a

findComp.exe: ConnectedComponent.o PGMimageProcessor.o driver.o
	$(CC) ConnectedComponent.o PGMimageProcessor.o driver.o -o findComp.exe $(CCFLAGS)

ConnectedComponent.o: ConnectedComponent.cpp
	$(CC) -c ConnectedComponent.cpp -o ConnectedComponent.o $(CCFLAGS)

PGMimageProcessor.o: PGMimageProcessor.cpp
	$(CC) -c PGMimageProcessor.cpp -o PGMimageProcessor.o $(CCFLAGS)

driver.o: driver.cpp
	$(CC) -c driver.cpp -o driver.o $(CCFLAGS)

run:
	./findcomp -s 3 1000 -t 128 -p -w output.pgm examples/chess.pgm

UnitTestCases.exe: UnitTestCases.cpp
	$(CC) UnitTestCases.cpp -o UnitTestCases.exe $(CCFLAGS)

clean:
	rm *.o *.exe *.pgm