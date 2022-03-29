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
}