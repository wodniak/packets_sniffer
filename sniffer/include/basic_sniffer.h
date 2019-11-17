#ifndef BASIC_SNIFFER_HPP
#define BASIC_SNIFFER_HPP

#include <iostream>
#include <stdio.h>
#include <functional>
#include <string.h>     //strcmp

#include <pcap.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

namespace gw
{

//Callback for C function made from non-static function from BasicSniffer class
template <typename T>
struct Callback;

template <typename Ret, typename... Params>
struct Callback<Ret(Params...)> {
   template <typename... Args> 
   static Ret callback(Args... args) {                    
      return func(args...);  
   }
   static std::function<Ret(Params...)> func; 
};

// static function dynamically bound to the member function packetHandler. 
template <typename Ret, typename... Params>
std::function<Ret(Params...)> Callback<Ret(Params...)>::func;


class BasicSniffer
{
public:
    /**
     *  \brief Get name of ethernet interface and create handle for the libpcap packet capture
     */ 
    BasicSniffer();

    /**
     *  \brief nothing important ATM
     */
    ~BasicSniffer();

    /**
     *  \brief Callback for pcap_loop.
     *         Execute some logic on packets
     */
    void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet);

private:
    //used to pass C++ non-static function as callback to C function from libpcap
    typedef void (*callback_t)(u_char *, const struct pcap_pkthdr*, const u_char*);
    
    //Keep record of listened packets
    //@{
    uint packetCount;    //processed packets counter
    uint bytesSend;
    uint bytesRecv;
    //@}

    char *dev;                      //interface name
    u_int mask;                     //netmask of sniffing device
    u_int net;                      //IP of sniffing device
    pcap_t *descr;                  //session handle
    char errbuf[PCAP_ERRBUF_SIZE];

    // variables to analyze packet content
    //@{
    struct ether_header* ethernetHeader;
    struct ip* ipHeader;
    struct tcphdr* tcpHeader;
    char sourceIp[INET_ADDRSTRLEN];
    char destIp[INET_ADDRSTRLEN];
    u_int sourcePort;
    u_int destPort;
    u_char *data;
    int dataLength;
    std::string dataStr;
    //@}

};
} //namespace gw

#endif
