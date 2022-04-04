# CSC3022F_A3
#Image processing with connected components

Folder contents:-> 2 header file(ConnectedComponent.h, PGMimageProcessor.h), 3 cpp files(driver.cpp, ConnectedComponent.cpp, PGMimageProcessor.cpp, UnitTesting.cpp), 1 Makefile, examples folder,git folder

Problem statement:->    The user supplies options [-t, -s, -w -p] and the pgm file to be  munipulated. The program will read the file based on input.From pgm image connected contents are extracted when a foreground pixels is encountered during the search and either dispayed to screen with their details or stored to output pgm file based on user options

ConnectedComponent.h:-> This is the header file for our reading and parsing methods, parameters(which
            are defined in ConnectedComponents.cpp), ConnectedComponent class , destructors & constructors defined

ConnectedComponent.cpp:-> This contains the definition of our parameters, destructors and constructors. These methods will be used in the
               PGMimageProcessor file when a COnnectedComponent object is made

PGMimageProcessor.h:-> This is the header file for our reading and parsing methods, parameters(which
            are defined in PGMimageProcessor.cpp), PGMimageProcessor class , destructors & constructors defined

PGMimageProcessor.cpp:-> This contains the definition of our parameters, destructors and constructors. These methods will be used in the
               driver file


driver.cpp:-> Contains the main method and prompts user to enter the pgm file to be  munipulated , options [-t, -s, -w, -p ]
	    options:
		  * "-t"-> set threshold for component detection
		  * "-s"-> set minimum and maximum valid component size
		  * "-w"-> write output all retained componets
		  * "-p"-> print out all the component data (entries do not have to be sorted) as well 
		  as the total component number and the sizes of the smallest and largest components
UnitTesting.cpp:-> Used for unit testing of the PGMimageProcessor class by testing its constructors

Makefile:-> compiles UnitTesting.cpp ConnectedComponent.cpp PGMimageProcessor.cpp and driver.cpp into object files then proceeds
           link them to create an executable file called "findcomp.exe"

Examples(folder):-> contains example pgm files that can be used to
                   test program.

git:-> contains git repository of project.


Testing:-> type "make" in command line to generate executable file and object files
	        type "make run" in command line, to test the extraction of connected components from given file with given min, max values, threshold val and writeoutput to given filename and print connented components details to screen
            type "make clean" in commandline , to delete the object files, pgm out images and executable file

Conclusion:-> the image output was'nt correct most probably the error is comming from the extraction process that was not done correctly.
