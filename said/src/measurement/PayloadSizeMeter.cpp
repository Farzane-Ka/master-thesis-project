//Author: Farzane Karami
#include <iostream>

#include "PayloadSizeMeter.h"

//float*
//Measurement::DirectionBytesMeter::getFingerprintProEntry( fingerprint* fp ) {
//    return fp->directionBytesMeterPro;
//}

float*
Measurement::PayloadSizeMeter::getFingerprintCntEntry( fingerprint* fp ) {
    return fp->payloadSizeMeterCnt;
}
