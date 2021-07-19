// ---------------------------------------------------------------------------
// DirectionBytesMeter.h
// The header file from the attribute meter: measuring the timing between the packets
//
// Author: Farzane Karami
// ---------------------------------------------------------------------------
#ifndef INTERARRIVAL_H
#define INTERARRIVAL_H

#include "Attributes.h"

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
    class InterarrivalMeter : public Attributes {

    public:
        // public methods
        #include "interarrival.tcc"
        //float* getFingerprintProEntry(fingerprint* fp);
        float* getFingerprintCntEntry(fingerprint* fp);
    };

}

#endif // DIRECTIONBYTESMETER_H
