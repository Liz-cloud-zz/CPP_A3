#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <utility>
#include "ConnectedComponent.h"

//constuctors:
MFNLIN003::ConnectedComponent::ConnectedComponent(int ID, int num_Pixels){
    MFNLIN003::ConnectedComponent::id= ID;
    MFNLIN003::ConnectedComponent::num_pixels=num_Pixels;

}
//Destructor
MFNLIN003::ConnectedComponent::~ConnectedComponent(){
    // for (std::vector< std::pair<int, int>>::iterator it = MFNLIN003::ConnectedComponent::coordinates.begin(); it !=  MFNLIN003::ConnectedComponent::coordinates.end(); ++it) {
    // delete it->second;
//}
    std::cout << "Destructor for CC"<<std::endl;
    MFNLIN003::ConnectedComponent::coordinates.clear();
}
//Copy constructor
MFNLIN003::ConnectedComponent::ConnectedComponent(const ConnectedComponent & cc){
     std::cout << "Copy Constructor FOR CC"<<std::endl;
     MFNLIN003::ConnectedComponent::id=cc.id;
     MFNLIN003::ConnectedComponent::num_pixels=cc.num_pixels;
     MFNLIN003::ConnectedComponent::coordinates=cc.coordinates;
}
//Move constructor
MFNLIN003::ConnectedComponent:: ConnectedComponent(ConnectedComponent && cc){
     std::cout << "Move Constructor for CC"<<std::endl;
     MFNLIN003::ConnectedComponent::id=cc.id;
     MFNLIN003::ConnectedComponent::num_pixels=cc.num_pixels;
     MFNLIN003::ConnectedComponent::coordinates =std::move(cc.coordinates);
}