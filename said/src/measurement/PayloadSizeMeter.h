//Author : Farzane Karami
#ifndef PAYLOADSIZEMETER_H
#define PAYLOADSIZEMETER_H

#include "Attributes.h"
#include <math.h>
//#include "../Flow/TcpFlow.h"
//#include "../Flow/UdpFlow.h"
//#include "../structs.h"
//#include "../enums.h"

namespace Measurement {
    // Percentage of amount of data, which was sent from the client to the
    // server and vice versa. Through this measurement a distinction is possible
    // between:
    //   * upload and download balanced (e.g. RTP for VoIP, ...)
    //   * almost only download (e.g. HTTP, POP3, ...)
    //   * almost only upload (e.g. SMTP, IRC, ...)
    class PayloadSizeMeter : public Attributes {

    public:
        // public methods
        #include "PayloadSizeMeter.tcc"
        //float* getFingerprintProEntry(fingerprint* fp);
        float*   getFingerprintCntEntry(fingerprint* fp);
    private:
       // template<typename T> float Mean(T* flow);
        //template<typename T> float Variance(T* flow,float m);
    };

}

#endif // DIRECTIONBYTESMETER_H
