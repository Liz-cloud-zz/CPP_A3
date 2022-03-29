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

    };
}