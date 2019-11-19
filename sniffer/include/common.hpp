#ifndef COMMON_H
#define COMMON_H

namespace gw
{

//processed packets information
//used to communicate with Displayer
typedef struct
{
    unsigned int packetCount;    //total numer of packets
    unsigned int bytesSend;
    unsigned int bytesRecv;
    unsigned int UDPCount;
    unsigned int TCPCount;

} statistics_t;

typedef uint8_t status_t;
}

//Error codes for application
#define SUCCESS 0x001

//display
//@{
#define FAIL 0x002
//@}
#endif //COMMON_H