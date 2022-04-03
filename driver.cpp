#include "ConnectedComponent.h"
#include "PGMimageProcessor.h"
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <memory>
#include <utility>


// int main(){
//     MFNLIN003::PGMimageProcessor pgmiP("/home/linda/Desktop/C++/A3/examples/chess.pgm");
//     int number_of_components=pgmiP.extractComponents(128,3);
//     std::cout<<"number of components before filtering: "<<number_of_components<<std::endl;
//     // int new_comp_size=pgmiP.filterComponentsBySize(3,pgmiP.columns*pgmiP.rows);
//     // std::cout<<"number of components after filtering: "<<new_comp_size<<std::endl;
//     // std::cout<<"Smallest component size is : "<<pgmiP.getSmallestSize()<<std::endl;
//     // std::cout<<"Largest component size is: "<<pgmiP.getLargestSize()<<std::endl;

 
// }
int main(int argc , char *argv[]){
     std::string filename;
     int max_val;
     int min_val;
     unsigned char threshold;



    int arguments=0;
    filename=argv[argc-1];//last array element is the pgm file to be edited
    MFNLIN003::PGMimageProcessor pgmiP(filename);
    while (arguments<argc-2){
        if((std::string(argv[arguments]))=="-s"){
            min_val=std::stoi(argv[arguments+1]);//minimum valid component size
            max_val=std::stoi(argv[arguments+2]);//maximum valid component size
            arguments+=2;// increment to get next options

        }
        else if((std::string(argv[arguments]))=="-t"){
            //get dimensions of frame
            threshold= (unsigned char) (argv[arguments+1]);
            arguments+=1;
        }

       if((std::string(argv[arguments]))=="-p"){
            //get the instruction and file name
            std::cout<<"print out all the component data:"<<std::endl;
            arguments+=1;

            int number_of_components=pgmiP.extractComponents(threshold,min_val);
            std::cout<<"number of components before filtering: "<<number_of_components<<std::endl;
            int new_comp_size=pgmiP.filterComponentsBySize(min_val,max_val);
            std::cout<<"number of components after filtering: "<<new_comp_size<<std::endl;
            std::cout<<"Smallest component size is : "<<pgmiP.getSmallestSize()<<std::endl;
            std::cout<<"Largest component size is: "<<pgmiP.getLargestSize()<<std::endl;

//need to find a way to access the vector of connected components unique pointers
            // for(const auto & container : pgmiP.concomp_vector){
            //     auto conncomp=container.get();
            //     pgmiP.printComponentData(conncomp);

            // }

        }
        else if ((std::string(argv[arguments]))=="-w")
        {
            std::string out_filename;
            std::cout<<"write out all retained components in file {enter file name}"<<std::endl;
            std::cin>>out_filename;
            arguments+=1;

            if(pgmiP.writeComponents(out_filename)){
                std::cout<<"Writting success! :)"<<std::endl;

            }
            else{std::cout<<"Writting unsuccessful:("<<std::endl;}
        }
        arguments++;
    }
 return 0;
}

