# These are the variables that will be used for compiling the code
CC=g++
CCFLAGS=-std=c++2a

findComp.exe: ConnectedComponent.o PGMimageProcessor.o findComp.o
	$(CC) ConnectedComponent.o PGMimageProcessor.o findComp.o -o findComp.exe $(CCFLAGS)

ConnectedComponent.o: ConnectedComponent.cpp
	$(CC) -c ConnectedComponent.cpp -o ConnectedComponent.o $(CCFLAGS)

PGMimageProcessor.o: PGMimageProcessor.cpp
	$(CC) -c PGMimageProcessor.cpp -o PGMimageProcessor.o $(CCFLAGS)

findComp.o: findComp.cpp
	$(CC) -c findComp.cpp -o findComp.o $(CCFLAGS)

run:
	./findcomp.exe -s 3 1000 -t 128 -p -w output.pgm examples/chess.pgm

UnitTestCases.exe: UnitTestCases.cpp
	$(CC) UnitTestCases.cpp -o UnitTestCases.exe $(CCFLAGS)

clean:
	rm *.o *.exe *.pgm