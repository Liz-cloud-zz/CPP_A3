#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <memory>
#include "PGMimageProcessor.h"
#include <bits/stdc++.h>

 //constructors
/**
 * @brief Construct a new MFNLIN003::PGMimageProcessor::PGMimageProcessor object
 * 
 */
 MFNLIN003::PGMimageProcessor::PGMimageProcessor(){
     MFNLIN003::PGMimageProcessor::rows=0;
     MFNLIN003::PGMimageProcessor::columns=0;
     MFNLIN003::PGMimageProcessor::comment="";
     MFNLIN003::PGMimageProcessor::filename="";
     MFNLIN003::PGMimageProcessor::max=0;
 }

 /**
  * @brief Construct a new MFNLIN003::PGMimageProcessor::PGMimageProcessor object
  * 
  */
MFNLIN003::PGMimageProcessor::PGMimageProcessor(std::string fil_n){
    MFNLIN003::PGMimageProcessor::filename=fil_n;
}

/**
 * @brief Destroy the MFNLIN003::PGMimageProcessor::PGMimageProcessor object
 * 
 */
MFNLIN003::PGMimageProcessor::~PGMimageProcessor(){

    // std::cout << "Destructor for PGMiP"<<std::endl;
    if(!this->concomp_vector.empty() ){//check if it is empty
        MFNLIN003::PGMimageProcessor::concomp_vector.clear();

    }
 }

/**
 * @brief Copy MFNLIN003::PGMimageProcessor::PGMimageProcessor object
 * 
 * @param pgmip 
 */
MFNLIN003::PGMimageProcessor::PGMimageProcessor(const PGMimageProcessor & pgmip){
    //   std::cout << "Copy Constructor for PGMiP"<<std::endl;
      this->columns=pgmip.columns;
      this->rows=pgmip.rows;
      this->comment=pgmip.comment;
      this->max=pgmip.max;
      this->version=pgmip.version;

     if(!pgmip.concomp_vector.empty()){//check if it is empty
         for(const auto &  up: pgmip.concomp_vector){
             this->concomp_vector.push_back(up);
         }
     } 
}

/**
 * @brief Move MFNLIN003::PGMimageProcessor::PGMimageProcessor object
 * 
 * @param pgmip 
 */
MFNLIN003::PGMimageProcessor::PGMimageProcessor(PGMimageProcessor && pgmip){
    //   std::cout << "Move Constructor for PGMiP"<<std::endl;
      //if(this!= & pgmip){//checks to make sure that we are not doing self assignment 
        this->columns=pgmip.columns;
        this->rows=pgmip.rows;
        this->comment=pgmip.comment;
        this->max=pgmip.max;
        this->version=pgmip.version;
        this->concomp_vector=std::move(pgmip.concomp_vector);
}

/**
 * @brief COPY Assignment for PGMimage Processor
 * 
 * @param pgmip 
 * @return MFNLIN003::PGMimageProcessor& 
 */
MFNLIN003::PGMimageProcessor& MFNLIN003::PGMimageProcessor::operator=(const MFNLIN003::PGMimageProcessor & pgmip){
    //   std::cout << "Copy assignment PGMiP"<<std::endl;
      if(this!= & pgmip){//checks to make sure that we are not doing self assignment 
        this->columns=pgmip.columns;
        this->rows=pgmip.rows;
        this->comment=pgmip.comment;
        this->max=pgmip.max;
        this->version=pgmip.version;

        if(!this->concomp_vector.empty()){
            this->concomp_vector.clear(); //'this' may already be managing a bit of memory so we must release it to prevent any memory leaks.

        }
        if (!pgmip.concomp_vector.empty()){
            for(const auto &  up: pgmip.concomp_vector){
               this->concomp_vector.push_back(up);
            }
        }
      }
      return *this;
}

/**
 * @brief Move assignment PGMiP
 * 
 * @param pgmip 
 * @return MFNLIN003::PGMimageProcessor& 
 */
MFNLIN003::PGMimageProcessor& MFNLIN003::PGMimageProcessor::operator=( MFNLIN003::PGMimageProcessor && pgmip){
    //   std::cout << "Move assignment PGMiP"<<std::endl;
      if(this!= & pgmip){//checks to make sure that we are not doing self assignment 
        this->columns=pgmip.columns;
        this->rows=pgmip.rows;
        this->comment=pgmip.comment;
        this->max=pgmip.max;
        this->version=pgmip.version;

        if(!this->concomp_vector.empty()){
            this->concomp_vector.clear(); //'this' may already be managing a bit of memory so we must release it to prevent any memory leaks.

        }
        if (!pgmip.concomp_vector.empty()){
             this->concomp_vector=std::move(pgmip.concomp_vector);
        }
      }
      return *this;
}

/**
 * @brief read the file contans and return a 1d array of image contents
 * 
 * @return unsigned char* 
 */
unsigned char * MFNLIN003::PGMimageProcessor::readFile(){
    int x = 0, y = 0;//intialise coordinate

    std::stringstream ss;
    std::ifstream infile(MFNLIN003::PGMimageProcessor::filename, std::ios::binary);
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

/**
 * @brief create a new PGM file which contains all current components
          (255=component pixel, 0 otherwise) and write this to outFileName as a
          valid PGM. the return value indicates success of operation
 * @param outFileName 
 * @return true 
 * @return false 
 */
bool MFNLIN003::PGMimageProcessor::writeComponents(const std::string & outFileName){
    std::cout<<"output connected components image"<<std::endl;
    std::ofstream ofstream;
    int image[MFNLIN003::PGMimageProcessor::rows][MFNLIN003::PGMimageProcessor::columns]={0};//initialise it zero
        //Loop thru cointainer and write 255 as pixel and coordinate
    for(const auto & container : MFNLIN003::PGMimageProcessor::concomp_vector){
        // auto conncomp=container.get();
        // for(const auto & point :conncomp->coordinates ){
        //     image[point.first][point.second]=255;
        // }
           for(const auto & point :container.coordinates){
            image[point.first][point.second]=255;
        }
    }

    //write the first 4 lines
    ofstream.open(outFileName.c_str(),std::ios::out | std::ios::binary);
    ofstream <<MFNLIN003::PGMimageProcessor::version<<std::endl;
    ofstream <<MFNLIN003::PGMimageProcessor::comment<<std::endl;
    ofstream <<MFNLIN003::PGMimageProcessor::columns <<" "<<MFNLIN003::PGMimageProcessor::rows<<std::endl;
    ofstream <<MFNLIN003::PGMimageProcessor::max <<std::endl;

    //loop thru 2d image and write to pixels to image
    for(int i=0;i<MFNLIN003::PGMimageProcessor::rows;++i){
        for(int j=0;j<MFNLIN003::PGMimageProcessor::columns;++j){
            ofstream<<image[i][j];
        }
        ofstream<<std::endl;
    }
    ofstream.close();
 
    //check if file not empty:
    std::ifstream infile(outFileName, std::ios::binary);
    if (infile.peek() == std::ifstream::traits_type::eof() )
    {
        return false;

    }
    return true;
}  

/**
 * @brief check if the charcter follows the size creteria and if it is a foreground pixel
 * 
 * @param character 
 * @param threshold 
 * @param minValidSize 
 * @return true 
 * @return false 
 */
bool MFNLIN003::PGMimageProcessor::checkForeGround(unsigned char character,unsigned char threshold, int minValidSize){
       std::queue<std::pair<int,int>> temp_q;//stores connected components neighbours
    //does the charcter follow the size creteria and is it a foreground pixel
    return ((float)character>minValidSize)&&(character>threshold);

}

/**
 * @brief iterate - with an iterator - though your container of connected
          components and filter out (remove) all the components which do not
          obey the size criteria pass as arguments. The number remaining
          after this operation should be returned.
 * 
 * @param threshold 
 * @param minValidSize 
 * @return int 
 */
int MFNLIN003::PGMimageProcessor::extractComponents(unsigned char threshold, int minValidSize){
      std::cout<<"extract components"<<std::endl;
      unsigned char* image0=readFile();
    //   std::cout <<"read file"<<std::endl;
      size_t num_of_comp=0;//num of components

  
      //covert 1d array to 2d
      unsigned char ** image=new unsigned char *[MFNLIN003::PGMimageProcessor::rows];
      for(size_t i=0;i<MFNLIN003::PGMimageProcessor::rows;++i){
          image[i]=new unsigned char [MFNLIN003::PGMimageProcessor::columns];
     }
    // std::cout <<"Convert 1d to 2d"<<std::endl;

    //populate array with 1D Array contents
      int counter=0;
      for(size_t y=0;y<MFNLIN003::PGMimageProcessor::rows;++y){
        for(size_t x=0;x<MFNLIN003::PGMimageProcessor::columns;++x){
              image[y][x]=image0[counter];
                // std::cout<<image[x][y]<<std::endl;
              counter++;
        }
      }
      delete[] image0;//clear memory
    //   std::cout <<"done populating array"<<std::endl;
    //make a corresponding 2d array that marks the points checked in the 2d image
      bool visited_comp[MFNLIN003::PGMimageProcessor::rows][MFNLIN003::PGMimageProcessor::columns]={{false}};
    //   std::cout <<"Created corresponding bool 2d array"<<std::endl;
        //Extract components
        int id=0;//unique id for component
        

         //push it’s non-tested N/S/E/W neighbour
        //coordinates onto a queue (initially empty)
        std::queue<std::pair<int,int>>temp_q;
        for(size_t y=0;y<MFNLIN003::PGMimageProcessor::rows;++y){
            for(size_t x=0;x<MFNLIN003::PGMimageProcessor::columns;++x){
                std::pair<int, int>pair=std::make_pair(y,x);
                if((float)image[y][x]==0 || (visited_comp[y][x])){//check if char has been visited
                    continue;//go to next point
                }

                if(MFNLIN003::PGMimageProcessor::checkForeGround(image[y][x],threshold,minValidSize)){//check if point is foreground
                     //make a connected component
                    MFNLIN003::ConnectedComponent cc(id,1);
                    cc.coordinates.push_back(std::make_pair(y,x));
                    for(size_t i=y-1;i<y+2;++i){
                        for(size_t j=x-1;j<x+2;++j){
                            //check for index out of bounds errors:
                            if(i>MFNLIN003::PGMimageProcessor::rows-1 || i<0){
                                continue;
                            }
                            if(j>MFNLIN003::PGMimageProcessor::columns ||j<0){
                                continue;
                            }

                            if((float)image[i][j]==255){//check if neighbour is 255
                                if(visited_comp[i][j]){//check if neighbour not yet processed
                                    continue;
                                }
                                else{
                                    //add neighbour to connected component
                                    cc.num_pixels++;
                                    cc.coordinates.push_back(std::make_pair(i,i));

                                    for(size_t y_c=i-1;y_c<i+2;++y_c){
                                        for(size_t x_c=j-1;x_c<j+2;++x_c){
                                            //check for index out of bounds errors:
                                            if(y_c>MFNLIN003::PGMimageProcessor::rows-1 || y_c<0){
                                                continue;
                                            }
                                            if(x_c >MFNLIN003::PGMimageProcessor::columns |x_c<0){
                                                continue;
                                            }
                                            temp_q.push(std::make_pair(y_c,x_c));
                                        }
                                    }
                                    //set the current foreground pixel added to your component to 0 in the thresholded image
                                    visited_comp[i][j]=true;
                                    image[i][j]=0;

                                    //popping off candidate pixel coordinates from the queue,
                                    //and expanding/testing those, until the queue has been exhausted
                                    while (!temp_q.empty())
                                    {
                                        std::pair<int,int>p=temp_q.front();
                                        if((float)image[p.first][p.second]==255){//check if neighbour is 255
                                            if(visited_comp[p.first][p.second]){//check if neighbour not yet processed
                                                continue;
                                            }
                                            else{
                                                //add neighbour to connected component
                                                cc.num_pixels++;
                                                cc.coordinates.push_back(p);
                                            }    
                                        }
                                        temp_q.pop();
                                    }
                                }
                            }
                        }
                    }
                    MFNLIN003::PGMimageProcessor::concomp_vector.push_back(cc);
                    id++;
                }
                visited_comp[y][x]=true;
                image[y][x]=(unsigned char )0;
                // std::unique_ptr<MFNLIN003::ConnectedComponent> up=std::make_unique<MFNLIN003::ConnectedComponent>(cc);
                // concomp_vector.push_back(up);//add connected commponent object to vector container  
                
            }
        }
    //clear memory
    for(size_t y=0;y<MFNLIN003::PGMimageProcessor::rows;++y){
            delete [] image[y];
            // delete [] visited_comp[y];
    }
    delete [] image;
    // delete [] visited_comp;
    return MFNLIN003::PGMimageProcessor::concomp_vector.size();
}


/**
 * @brief iterator with an iterator - though your container of connected
components and filter out (remove) all the components which do not
obey the size criteria pass as arguments. The number remaining
after this operation should be returned.
 * 
 * @param minSize 
 * @param maxSize 
 * @return int 
 */
int MFNLIN003::PGMimageProcessor::filterComponentsBySize(int minSize, int maxSize){
        // for(int i=0 ;i<MFNLIN003::PGMimageProcessor::concomp_vector.size();++i){
        //     auto conncomp=MFNLIN003::PGMimageProcessor::concomp_vector[i].get();
        //     size_t num_pix=conncomp->num_pixels;
        //     if(num_pix<minSize || num_pix>maxSize){
        //         MFNLIN003::PGMimageProcessor::concomp_vector.erase(concomp_vector.begin()+i);
        //     }
        // }

        for(int i=0 ;i<MFNLIN003::PGMimageProcessor::concomp_vector.size();++i){
            int num_pix=MFNLIN003::PGMimageProcessor::concomp_vector[i].num_pixels;
            // std::cout<<"got num of pixels "<<num_pix<<std::endl;
            if(num_pix<minSize || num_pix>maxSize){
                MFNLIN003::PGMimageProcessor::concomp_vector.erase(concomp_vector.begin()+i);
            }
        }
  return MFNLIN003::PGMimageProcessor::concomp_vector.size();
}

/**
 * @brief return number of pixels in largest component
 * 
 * @return int 
 */
 int MFNLIN003::PGMimageProcessor::getLargestSize() const{
     int max=0;
    //Loop thru cointainer
    // for(const auto & container : MFNLIN003::PGMimageProcessor::concomp_vector){
    //     auto conncomp=container.get();
    //     if(conncomp->num_pixels>max){
    //         max=conncomp->num_pixels;
    //     }
    // }

    for(const auto & container : MFNLIN003::PGMimageProcessor::concomp_vector){
        auto conncomp=container;
        if(conncomp.num_pixels>max){
            max=conncomp.num_pixels;
        }
}
    return max;
}
/**
 * @brief return number of pixels in smallest component
 * 
 * @return int  
 */
int MFNLIN003::PGMimageProcessor::getSmallestSize() const{
     int min=1000;
    //Loop thru cointainer
    // for(const auto & container : MFNLIN003::PGMimageProcessor::concomp_vector){
    //     auto conncomp=container.get();
    //     if(conncomp->num_pixels<min){
    //         min=conncomp->num_pixels;
    //     }
    // }
    for(const auto & container : MFNLIN003::PGMimageProcessor::concomp_vector){
        auto conncomp=container;
        if(conncomp.num_pixels<min){
            min=conncomp.num_pixels;
        }
    }
    return min;
}

/**
 * @brief print the data for a component to std::cout
see ConnectedComponent class;
print out to std::cout: component ID, number of pixels
 * 
 * @param theComponent 
 */
void MFNLIN003::PGMimageProcessor::printComponentData(const MFNLIN003::ConnectedComponent & theComponent)const{
    std::cout<< "Component ID: "<<theComponent.id<<"Number of pixels: "<<theComponent.num_pixels<<std::endl;

}

std::vector<MFNLIN003::ConnectedComponent> &MFNLIN003::PGMimageProcessor::getVector(){
    return this->concomp_vector;
}