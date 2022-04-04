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

int main(int argc , char *argv[]){
     std::string filename;//filename to be read
    std::string out_filename;//output file name
     int max_val;//maximum pixel
     int min_val;//minimum pixel
     char threshold;//threshold for pixel
     bool write=false;//write flag
     bool print =false;//print flag

    std::cout<<argc<<std::endl;
    int arguments=1;
    filename=std::string(argv[argc-1]);//last array element is the pgm file to be edited
    while (arguments<argc-1){
        std::cout<<arguments<<" : "<<argv[arguments]<<std::endl;

        if((std::string(argv[arguments]))=="-s"){
            std::cout<<"set min max"<<std::endl;
            min_val=std::stoi(argv[arguments+1]);//minimum valid component size
            max_val=std::stoi(argv[arguments+2]);//maximum valid component size
            arguments+=2;// increment to get next options
           
        }
        else if((std::string(argv[arguments]))=="-t"){
            std::cout<<"set threshold"<<std::endl;
            threshold= reinterpret_cast<unsigned char &>(argv[arguments+1]);
            arguments+=1;
        }
        else if ((std::string(argv[arguments]))=="-w")
        {   
            std::cout<<"write"<<std::endl;
            out_filename=std::string(argv[arguments+1]);
            write=true;
            arguments+=1;
        }
        else if((std::string(argv[arguments]))=="-p"){
            std::cout<<"print"<<std::endl;
            print=true;
        }
        arguments++;
        std::cout<<"increment"<<std::endl;
    }
    std::cout<<"Creating PGMimgae"<<std::endl;

    MFNLIN003::PGMimageProcessor pgmiP(filename);
    int number_of_components=pgmiP.extractComponents(threshold,min_val);
    std::cout<<"number of components before filtering: "<<number_of_components<<std::endl;
    int new_comp_size=pgmiP.filterComponentsBySize(min_val,max_val);
    std::cout<<"number of components after filtering: "<<new_comp_size<<std::endl;
    if(print){
        std::vector<std::shared_ptr<MFNLIN003::ConnectedComponent>> vector=pgmiP.getVector();
        for(int i=0 ;i<vector.size();++i){
            const auto cc =&vector[i];
            pgmiP.printComponentData(**cc);
        }
        std::cout<<"Smallest component size is : "<<pgmiP.getSmallestSize()<<std::endl;
        std::cout<<"Largest component size is: "<<pgmiP.getLargestSize()<<std::endl;
    }
    if (write){
        if(pgmiP.writeComponents(out_filename)){
            std::cout<<"Writting success! :)"<<std::endl;
        }
        else{std::cout<<"Writting unsuccessful:("<<std::endl;}
    }

    
 return 0;
}

