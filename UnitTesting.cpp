#define CATCH_CONFIG_RUNNER 
#include "PGMimageProcessor.h"
#include "catch.hpp"

TEST_CASE("PGMimageProcessor class"){
    SECTION("Default Constructor"){
        MFNLIN003::PGMimageProcessor pgmiP;
        REQUIRE(pgmiP.filename=="");
    }
    SECTION("Custom Constructor"){
        MFNLIN003::PGMimageProcessor pgmiP("~/examples/chess.pgm");
        REQUIRE(pgmiP.filename=="~/examples/chess.pgm");
    }

    SECTION("Copy Constructor"){
        MFNLIN003::PGMimageProcessor pgmiP("~/examples/chess.pgm");
        MFNLIN003::PGMimageProcessor pgmiP2(pgmiP);

        REQUIRE(pgmiP.filename==pgmiP2.filename);
    }
    SECTION("MOve Constructor"){
        MFNLIN003::PGMimageProcessor pgmiP("~/examples/chess.pgm");
        MFNLIN003::PGMimageProcessor pgmiP2(std::move(pgmiP));
        REQUIRE(pgmiP.filename==pgmiP2.filename);
    }
    
}