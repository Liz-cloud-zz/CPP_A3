# This is a Makefile comment
driver.exe: ConnectedComponent.o  PGMimageProcessor.o driver.o
	g++ ConnectedComponent.o PGMimageProcessor.o driver.o -o findcomp.exe -std=c++2a

methods.o: ConnectedComponent.cpp ConnectedComponent.h
	g++ -c ConnectedComponent.cpp -o ConnectedComponent.o -std=c++2a

methods2.o: PGMimageProcessor.cpp PGMimageProcessor.h
    g++ -c PGMimageProcessor.cpp -o PGMimageProcessor.o -std=c++2a

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o -std=c++2a

run:
	./findcomp.exe -s 3 1000 -t 128 -p -w output.pgm examples/sloan_image.pgm

clean:
	rm *.o extractor.exe *.pgm