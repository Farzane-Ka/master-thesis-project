//author Farzane Karami
#include <iostream>

#include "interarrival.h"

//float*
//Measurement::DirectionBytesMeter::getFingerprintProEntry( fingerprint* fp ) {
//    return fp->directionBytesMeterPro;
//}

float*
Measurement::InterarrivalMeter:: getFingerprintCntEntry(fingerprint* fp ) {
    return fp->interarrivalMeterCnt;
}
