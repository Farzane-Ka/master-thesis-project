// ---------------------------------------------------------------------------
// 
// The header file from the attribute meter: Measuring randomness of bytes in the payload by using the chi-square formula
// 
//
// Author: Farzane Karami
// ---------------------------------------------------------------------------
#ifndef CHI_SQUARE
#define CHI_SQUARE
#include<fstream>
#include "Attributes.h"
#include<math.h>
namespace Measurement { 

    class chi_square: public Attributes {

    private:
        int chert = 0 ;
        u_char* p_payload;                 // pointer to the payload of a packet
        u_int   payload_size;              // size of this packet
    public:
        #include "chi_square.tcc"
        float* getFingerprintProEntry(fingerprint* fp);
        float*   getFingerprintCntEntry(fingerprint* fp);
        void convert(u_char* p_payload,int* p );
        //void shift(bool ch[],int n);//shifts the array one bit
        void calculate(bool arr[],int count[],int len) ;//calculate the count2 ,count3
        float chi(int count4[],int n,int m);
        void fe(int ** x,bool* y) ;
    };
    
}

#endif // ALLPACKETSFIRST8BYTESEQUALITYMETER
