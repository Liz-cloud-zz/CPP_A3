#include "ConnectedComponent.h"

//constuctors:

/**
 * @brief Construct a new MFNLIN003::ConnectedComponent::ConnectedComponent object
 * 
 * @param ID 
 * @param num_Pixels 
 */
MFNLIN003::ConnectedComponent::ConnectedComponent(int ID, int num_Pixels){
    MFNLIN003::ConnectedComponent::id= ID;
    MFNLIN003::ConnectedComponent::num_pixels=num_Pixels;

}
/**
 * @brief Destroy the MFNLIN003::ConnectedComponent::ConnectedComponent object
 * 
 */
MFNLIN003::ConnectedComponent::~ConnectedComponent(){
    // for (std::vector< std::pair<int, int>>::iterator it = MFNLIN003::ConnectedComponent::coordinates.begin(); it !=  MFNLIN003::ConnectedComponent::coordinates.end(); ++it) {
    // delete it->second;
//}
    std::cout << "Destructor for CC"<<std::endl;
    MFNLIN003::ConnectedComponent::coordinates.clear();
}

/**
 * @brief Construct a new MFNLIN003::ConnectedComponent::ConnectedComponent object
 * 
 * @param cc 
 */
MFNLIN003::ConnectedComponent::ConnectedComponent(const ConnectedComponent & cc){
     std::cout << "Copy Constructor FOR CC"<<std::endl;
     MFNLIN003::ConnectedComponent::id=cc.id;
     MFNLIN003::ConnectedComponent::num_pixels=cc.num_pixels;
     MFNLIN003::ConnectedComponent::coordinates=cc.coordinates;
}

/**
 * @brief 
 * 
 * @param cc 
 * @return MFNLIN003::ConnectedComponent:: 
 */
MFNLIN003::ConnectedComponent:: ConnectedComponent(ConnectedComponent && cc){
     std::cout << "Move Constructor for CC"<<std::endl;
     MFNLIN003::ConnectedComponent::id=cc.id;
     MFNLIN003::ConnectedComponent::num_pixels=cc.num_pixels;
     MFNLIN003::ConnectedComponent::coordinates =std::move(cc.coordinates);
}