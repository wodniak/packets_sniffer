#include "display.hpp"

namespace gw
{

DisplayCLI::DisplayCLI()
{

}


void DisplayCLI::refresh(const statistics_t & data)
{
    // CONSOLE_CLEAN;
    std::cout << "Statistics:\tSend: " << data.bytesSend << "\tRecv: " << data.bytesRecv << std::endl;
    std::cout << "Packets type counter: TCP:" << data.TCPCount << "  UDP:" << data.UDPCount << std::endl;
}


} //namespace gw
