#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

namespace MFNLIN003
{
    class ConnectedComponent {
        public:
           int num_pixels;//number of pixels
           int id;//unique id for component
           std::vector< std::pair<int,int> >coordinates;// store the pixels in that component ((x,y) pairs)

            //constuctors:
            //constuctor
            ConnectedComponent(void);
            //destructor
            ~ConnectedComponent();
            //Copy COnstructor
            


    };
}