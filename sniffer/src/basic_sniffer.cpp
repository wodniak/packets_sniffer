#include "basic_sniffer.h"

namespace gw
{   

BasicSniffer::BasicSniffer()
{
    //registering callback for pcap_loop
    Callback<void(u_char *, const struct pcap_pkthdr*, const u_char*)>::func = std::bind(&BasicSniffer::packetHandler,
         this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    callback_t func = static_cast<callback_t>(Callback<void(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)>::callback);

    dev = pcap_lookupdev(errbuf);   //interface name
    if (dev == NULL) 
    {
        std::cout << "pcap_lookupdev() failed: " << errbuf << std::endl;
    }

    descr = pcap_open_live(dev, BUFSIZ, 0, -1, errbuf);
    if (descr == NULL) 
    {
        std::cout << "pcap_open_live() failed: " << errbuf << std::endl;
    }

    if (pcap_loop(descr, 0, func, NULL) < 0) 
    {
        std::cout << "pcap_loop() failed: " << pcap_geterr(descr);
    }
}


BasicSniffer::~BasicSniffer()
{
    std::cout << "capture finished" << std::endl;
}


void BasicSniffer::packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    ++packetCount;

    ethernetHeader = (struct ether_header*)packet;
    if (ntohs(ethernetHeader->ether_type) == ETHERTYPE_IP) 
    {
        ipHeader = (struct ip*)(packet + sizeof(struct ether_header));
        inet_ntop(AF_INET, &(ipHeader->ip_src), sourceIp, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &(ipHeader->ip_dst), destIp, INET_ADDRSTRLEN);

        //Check if packet was send or received
        if (strcmp(sourceIp, "192.168.1.178") == 0)
        {
            bytesSend += pkthdr->len;
        }
        else
        {
            bytesRecv += pkthdr->len;
        }
        
        std::cout << "Statistics:\tSend: " << bytesSend << "\tRecv: " << bytesRecv << std::endl; 

        if (ipHeader->ip_p == IPPROTO_TCP) 
        {
            tcpHeader = (tcphdr*)(packet + sizeof(struct ether_header) + sizeof(struct ip));
            sourcePort = ntohs(tcpHeader->source);
            destPort = ntohs(tcpHeader->dest);
            data = (u_char*)(packet + sizeof(struct ether_header) + sizeof(struct ip) + sizeof(struct tcphdr));
            dataLength = pkthdr->len - (sizeof(struct ether_header) + sizeof(struct ip) + sizeof(struct tcphdr));

            // convert non-printable characters, other than carriage return, line feed,
            // or tab into periods when displayed.
            for (int i = 0; i < dataLength; i++) 
            {
                if ((data[i] >= 32 && data[i] <= 126) || data[i] == 10 || data[i] == 11 || data[i] == 13) 
                {
                    dataStr += (char)data[i];
                }
                else 
                {
                    dataStr += ".";
                }
            }

            // print the results
            std::cout << sourceIp << ":" << sourcePort << " -> " << destIp << ":" << destPort << std::endl;
            if (dataLength > 0) 
            {
                // std::cout << dataStr << std::endl;
            }
        }
    }
}

} //namespace gw
