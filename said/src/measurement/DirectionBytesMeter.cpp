//Author Farzanr Karami
#include <iostream>

#include "DirectionBytesMeter.h"

//float*
//Measurement::DirectionBytesMeter::getFingerprintProEntry( fingerprint* fp ) {
//    return fp->directionBytesMeterPro;
//}

float*
Measurement::DirectionBytesMeter::getFingerprintCntEntry( fingerprint* fp ) {
    return fp->directionBytesMeterCnt;
}
