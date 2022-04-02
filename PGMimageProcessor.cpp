#include "PGMimageProcessor.h"
#include <bits/stdc++.h>

 //constructors
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
        auto conncomp=container.get();
        for(const auto & point :conncomp->coordinates ){
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
      size_t num_of_comp=0;//num of components

  
      //covert 1d array to 2d
      unsigned char ** image=new unsigned char *[MFNLIN003::PGMimageProcessor::rows];
      for(size_t i=0;i<MFNLIN003::PGMimageProcessor::rows;++i){
          image[i]=new unsigned char [MFNLIN003::PGMimageProcessor::columns];
        }

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

       //make a corresponding 2d array that marks the points checked in the 2d image
      bool visited_comp[MFNLIN003::PGMimageProcessor::columns][MFNLIN003::PGMimageProcessor::rows];
      for(size_t y=0;y<MFNLIN003::PGMimageProcessor::rows;++y){
           for(size_t x=0;x<MFNLIN003::PGMimageProcessor::columns;++x){
              visited_comp[y][x]=false;
            }
          
      }
        //Extract components
        int id=0;//unique id for component
         //pushing it’s non-tested N/S/E/W neighbour
        //coordinates onto a queue (initially empty)
        std::queue<std::pair<int,int>>temp_q;
        //make a connected component
        MFNLIN003::ConnectedComponent cc(id,1);

        for(size_t y=0;y<MFNLIN003::PGMimageProcessor::rows;++y){
            for(size_t x=0;x<MFNLIN003::PGMimageProcessor::columns;++x){
                std::pair<int, int>pair=std::make_pair(y,x);
                if((float)image[y][x]==0 || (visited_comp[y][x]==true)){//check if char has been visited
                    continue;//go to next point
                }

                if(MFNLIN003::PGMimageProcessor::checkForeGround(image[y][x],threshold,minValidSize)){//check if point is foreground
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
                    id++;
                }
                visited_comp[x][y]=true;
                image[y][x]=0;
                concomp_vector.push_back(std::make_unique<MFNLIN003::ConnectedComponent>(cc));//add connected commponent object to vector container
            }
        }
    //clear memory
    for(size_t y=0;y<MFNLIN003::PGMimageProcessor::rows;++y){
            delete [] image[y];
            delete [] visited_comp[y];
    }
    delete [] image;
    delete [] visited_comp;
    return MFNLIN003::PGMimageProcessor::concomp_vector.size();
}

bool MFNLIN003::PGMimageProcessor::checkValidRange(int minSize, int maxSize) {

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
    
    //remove > maxSize
    MFNLIN003::PGMimageProcessor::concomp_vector.erase(std::remove_if(
            MFNLIN003::PGMimageProcessor::concomp_vector.begin(),
            MFNLIN003::PGMimageProcessor::concomp_vector.end(),
            [](const auto &conncomp ){ return (conncomp.get().num_pixels>maxSize);})
            ,MFNLIN003::PGMimageProcessor::concomp_vector.end());
    
    //remove <minSize
     MFNLIN003::PGMimageProcessor::concomp_vector.erase(std::remove_if(
            MFNLIN003::PGMimageProcessor::concomp_vector.begin(),
            MFNLIN003::PGMimageProcessor::concomp_vector.end(),
            [](const auto &conncomp ){ return (conncomp.get().num_pixels<minSize);})
            ,MFNLIN003::PGMimageProcessor::concomp_vector.end());
  
}
/**
 * @brief return number of pixels in largest component
 * 
 * @return int 
 */
 int MFNLIN003::PGMimageProcessor::getLargestSize() const{
     int max=0;
    //Loop thru cointainer
    for(const auto & container : MFNLIN003::PGMimageProcessor::concomp_vector){
        auto conncomp=container.get();
        if(conncomp->num_pixels>max){
            max=conncomp->num_pixels;
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
    for(const auto & container : MFNLIN003::PGMimageProcessor::concomp_vector){
        auto conncomp=container.get();
        if(conncomp->num_pixels<min){
            min=conncomp->num_pixels;
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
void MFNLIN003::PGMimageProcessor::printComponentData(const ConnectedComponent & theComponent)const{
    std::cout<< "component ID: "<<theComponent.id<<"number of pixels: "<<theComponent.num_pixels<<std::endl;

}