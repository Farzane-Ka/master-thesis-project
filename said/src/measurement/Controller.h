// ---------------------------------------------------------------------------
// Controller.h
//
// Author: Florian Adamsky and Farzane Karami
// ---------------------------------------------------------------------------
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

#include "../Flow/TcpFlow.h"
#include "../Flow/UdpFlow.h"
#include "../structs.h"
#include "../FingerprintDB.h"
#include "../Spid.h"
#include "chi_square.h"
#include "DirectionBytesMeter.h"
#include "interarrival.h"
#include "PayloadSizeMeter.h"
namespace Measurement {
    
    class Controller {

      private:
        // private variables
        vector<Attributes*>           attributes;
        vector<Attributes*>::iterator iter;
        FingerprintDB*                refDB;      // Reference Database
        Spid*                         spid;         
        unsigned int                  dbSize;
        unsigned short attributesSize;

      public:
        // Constructor of this file
        explicit Controller();

        // This file contains the template methods
        #include "Controller.tcc"

        // In this method the actual identification happens
        //short IdentifyFlow(fingerprint* fp);

        // This method calculates the kullback–leibler divergence, which is
        // necessary for identification.
       // float KullbackLeiblerDivergence(float* dbPro, float* fpPro);

        // Deconstructor of this class
        ~Controller();
    };
}

#endif // CONTROLLER_H
