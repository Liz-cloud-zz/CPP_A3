#include "PGMimageProcessor.h"
#include <string>

int main(){


     return 0;
}
// int main(int argc , char *argv[]){
//      std::string filename;
//      int max_val;
//      int min_val;
//      int threshold;



//     int arguments=0;
//     filename=argv[argc-1];//last array element is the pgm file to be edited
//     while (arguments<argc-2){
//         if((std::string(argv[arguments]))=="-s"){
//             min_val=std::stoi(argv[arguments+1]);//minimum valid component size
//             max_val=std::stoi(argv[arguments+2]);//maximum valid component size
//             arguments+=2;// increment to get next options

//         }
//         else if((std::string(argv[arguments]))=="-t"){
//             //get dimensions of frame
//             threshold=std::stoi(argv[arguments+1]);
//             arguments+=1;
//         }
//         else if((std::string(argv[arguments]))=="-p"){
//             //get the instruction and file name
//             std::cout<<"print out all the component data:"<<std::endl;
//             arguments+=1;
//         }
//         else if ((std::string(argv[arguments]))=="-w")
//         {
//             std::string out_filename;
//             std::cout<<"write out all retained components in file {enter file name}"<<std::endl;
//             std::cin>>out_filename;
//             arguments+=1;
//         }
//         arguments++;
//     }
//  return 0;
// }