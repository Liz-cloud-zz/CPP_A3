#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <memory>

namespace MFNLIN003
{
    class ConnectedComponent {
        public:
           int num_pixels;//number of pixels
           int id;//unique id for component
           std::vector< std::pair<int,int> >coordinates;// store the pixels in that component ((x,y) pairs)

            //constuctors:
            
            //constuctor
            ConnectedComponent(int id, int num_pixels);
            //destructor
            ~ConnectedComponent();
            //Copy Constructor
            ConnectedComponent(const ConnectedComponent & cc);
            //Move Constructor
            ConnectedComponent(ConnectedComponent && cc);
            //Copy Assignment 
            ConnectedComponent & operator=(const ConnectedComponent &cc);
            //Move Assignment
            ConnectedComponent & operator=(ConnectedComponent && cc);
    };
}