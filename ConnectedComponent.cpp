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

/**
 * @brief Construct a new MFNLIN003::ConnectedComponent::ConnectedComponent object
 * 
 * @param ID 
 * @param num_Pixels 
 */
MFNLIN003::ConnectedComponent::ConnectedComponent(int ID, int num_Pixels){
    this->id= ID;
    this->num_pixels=num_Pixels;

}
/**
 * @brief Destroy the MFNLIN003::ConnectedComponent::ConnectedComponent object
 * 
 */
MFNLIN003::ConnectedComponent::~ConnectedComponent(){
    // std::cout << "Destructor for CC"<<std::endl;
    if(!this->coordinates.empty()){
        this->coordinates.clear();
    }
   
}

/**
 * @brief Copy Constructor for MFNLIN003::ConnectedComponent::ConnectedComponent object
 * 
 * @param cc 
 */
MFNLIN003::ConnectedComponent::ConnectedComponent(const ConnectedComponent & cc){
    //  std::cout << "Copy Constructor FOR CC"<<std::endl;
     this->id=cc.id;
     this->num_pixels=cc.num_pixels;
     this->coordinates=cc.coordinates;
}

/**
 * @brief MOve Constructor for Connected Component
 * 
 * @param cc 
 * @return MFNLIN003::ConnectedComponent:: 
 */
MFNLIN003::ConnectedComponent:: ConnectedComponent(ConnectedComponent && cc){
    //  std::cout << "Move Constructor for CC"<<std::endl;
     this->id=cc.id;
     this->num_pixels=cc.num_pixels;
     this->coordinates=std::move(cc.coordinates);
}