#include "PGMimageProcessor.h"

 //constructors
 /**
  * @brief Construct a new MFNLIN003::PGMimageProcessor::PGMimageProcessor object
  * 
  */
MFNLIN003::PGMimageProcessor::PGMimageProcessor(){}

/**
 * @brief Destroy the MFNLIN003::PGMimageProcessor::PGMimageProcessor object
 * 
 */
MFNLIN003::PGMimageProcessor::~PGMimageProcessor(){

    std::cout << "Destructor for PGMiP"<<std::endl;
    MFNLIN003::PGMimageProcessor::concomp_vector.clear();
}

/**
 * @brief Copy MFNLIN003::PGMimageProcessor::PGMimageProcessor object
 * 
 * @param pgmip 
 */
MFNLIN003::PGMimageProcessor::PGMimageProcessor(const PGMimageProcessor & pgmip){
      std::cout << "Copy Constructor for PGMiP"<<std::endl;
      MFNLIN003::PGMimageProcessor::columns=pgmip.columns;
      MFNLIN003::PGMimageProcessor::rows=pgmip.rows;
      MFNLIN003::PGMimageProcessor::comment=pgmip.comment;
      MFNLIN003::PGMimageProcessor::max=pgmip.max;
      MFNLIN003::PGMimageProcessor::version=pgmip.version;
      MFNLIN003::PGMimageProcessor::concomp_vector=pgmip.concomp_vector;
}

/**
 * @brief Move MFNLIN003::PGMimageProcessor::PGMimageProcessor object
 * 
 * @param pgmip 
 */
MFNLIN003::PGMimageProcessor::PGMimageProcessor(PGMimageProcessor && pgmip){
      std::cout << "Move Constructor for PGMiP"<<std::endl;
      MFNLIN003::PGMimageProcessor::concomp_vector=std::move(pgmip.concomp_vector);
      MFNLIN003::PGMimageProcessor::columns=pgmip.columns;
      MFNLIN003::PGMimageProcessor::rows=pgmip.rows;
      MFNLIN003::PGMimageProcessor::comment=pgmip.comment;
      MFNLIN003::PGMimageProcessor::max=pgmip.max;
      MFNLIN003::PGMimageProcessor::version=pgmip.version;
}

unsigned char * MFNLIN003::PGMimageProcessor::readFile(std::string filename){
    int x = 0, y = 0;//intialise coordinate

    std::stringstream ss;
    std::ifstream infile(filename, std::ios::binary);
    std::string inputLine="";
    if(!infile){
        std::cout <<"Cannot open file! File does not exist"<<std::endl;
        return nullptr;
    }
    else{
        getline(infile,inputLine);//read file line
        //check if the file is in correct version
        if(inputLine.compare("P5")!=0) std::cerr << "Version error"<<std::endl;
        MFNLIN003::PGMimageProcessor::version=inputLine;
        std::cout<<"Version: "<<MFNLIN003::PGMimageProcessor::version<<std::endl;

        getline(infile,inputLine);//read file line
        //get comment starting with "#" char
        while(inputLine.find("#")!=std::string::npos) {
            MFNLIN003::PGMimageProcessor::comment+=inputLine; 
           
            getline(infile,inputLine);//read file line
        } 
        std::cout<<"Comment: "<<MFNLIN003::PGMimageProcessor::comment<<std::endl;
        
        // ss << inputLine;//read in dimesions
        // ss >> columns >> rows;
        int space = inputLine.find(" ");
        MFNLIN003::PGMimageProcessor::columns = std::stoi(inputLine.substr(0, space));
        MFNLIN003::PGMimageProcessor::rows = std::stoi(inputLine.substr(space + 1));
        std::cout << "image is: "<< MFNLIN003::PGMimageProcessor::columns <<" x "<<MFNLIN003::PGMimageProcessor::rows <<std::endl;
            
        getline(infile,inputLine);//read file line
        MFNLIN003::PGMimageProcessor::max=std::stoi(inputLine);
        std::cout <<"Maximum intensity is "<<max<<std::endl;

        //intialise 1D Array
        unsigned char *image0=(unsigned char *) new unsigned char [MFNLIN003::PGMimageProcessor::rows*MFNLIN003::PGMimageProcessor::columns];
        infile.read(reinterpret_cast<char *>(image0),(MFNLIN003::PGMimageProcessor::rows*MFNLIN003::PGMimageProcessor::columns)*sizeof(unsigned char));//read in image data 
        infile.close();
        
        return image0;
    }
}