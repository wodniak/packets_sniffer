#include "display.hpp"

namespace gw
{

DisplayCLI::DisplayCLI()
{
    date = std::time(nullptr);

}


void DisplayCLI::refresh(const statistics_t & data)
{
    CONSOLE_CLEAN;
    std::cout << std::asctime(std::localtime(&date)) << std::endl;
    std::cout << "Statistics:\tSend: " << data.bytesSend << "\tRecv: " << data.bytesRecv << std::endl;
    std::cout << "Packets type counter: TCP:" << data.TCPCount << "  UDP:" << data.UDPCount << std::endl;
}


status_t DisplayCLI::dump_to_file()
{
    return SUCCESS;
}


} //namespace gw
