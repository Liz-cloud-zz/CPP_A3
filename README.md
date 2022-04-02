# CSC3022F_A3
Image processing with connected components

Folder contents:-> 2 header file(ConnectedComponent.h, PGMimageProcessor.h), 3 cpp files(driver.cpp, onnectedComponent.cpp, PGMimageProcessor.cpp), 1 Makefile, examples folder,git folder

Problem statement:->    The user supplies the pgm file to be  munipulated , options [-t, -s, -w ] ,extraction points (start & end coordinates) , frame dimensions, output file name (to display pgm frame manipulated), munipulation option [none, invert,reverse, revinvert]. The program will extract frames of size dimensions from extration points range and manipulate them based on given options and store the result pgm frame image in output file name suplied.

framesequence.h:-> This is the header file for our reading and parsing methods(which
            are defined in framesequence.cpp), FrameSequence class , destructors & constructors defined

methods.cpp:-> This contains the definition of our methods, destructors and constructors. These methods will be used in the
               driver.cpp file

driver.cpp:-> Contains the main method and prompts user to enter the pgm file to be  munipulated , options [-t, -s, -w ], extraction points (start & end coordinates) , frame diamensions, output file name (to display pgm frame manipulated), munipulation option [none, invert,reverse, revinvert].
	    Munipulation options:
		  * "none"-> no modification
		  * "invert"-> invert frames
		  * "reverse"-> reverse frames
		  * "revinvert"-> reverse and invert frames
		  * else option is invalid
Makefile:-> compiles framesequence.cpp and driver.cpp into object files then proceeds
           link them to create an executable file called "extractor.exe"

Examples(folder):-> contains example pgm files that can be used to
                   test program.

git:-> contains git repository of project.


Testing:-> type "make" in command line to generate executable file and object files
	        type "make run" in command line, to test the extraction and munipulation of the sloan_image.pgm from point(0,10) to (1000,1000) frames of size 300x200 then print out inverted frames and frames not modified
            type "make clean" in commandline , to delete the object files, pgm frame images and executable file

Conclusion:-> 
