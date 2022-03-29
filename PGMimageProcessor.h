#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <memory>
#include "ConnectedComponent.h"

namespace MFNLIN003{
    /**
     * @brief encapsulates the functionality needed to read
              in a PGM image and apply a connected component analysis to that image.
     * 
     */
    class PGMimageProcessor{
        private:
            //container storing smart pointers to each ConnectedComponent
            std::vector<std::unique_ptr<ConnectedComponent>> concomp_vector;
        public :
            int rows; //width of image
            int columns;// height of image
            int max;// maximum intensity in image
            std::string comment ="";//image comment
            std::string version;//image version
        unsigned char *readFile(std::string filename);//read file contents from file
        bool writeComponents(const std::string & outFileName);//write data to file
        int extractComponents(unsigned char threshold, int minValidSize);//extract cconnected commponents
        int filterComponentsBySize(int minSize, int maxSize);//contains current components
        int getComponentCount(void) const;// get number of pixels of largested component
        int getLargestSize(void) const;// return number of pixels in largest component
        int getSmallestSize(void) const;// return number of pixels in smallest component
        void printComponentData(const ConnectedComponent & theComponent) const;//print the data for a component

    };
}