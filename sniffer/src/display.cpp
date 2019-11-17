#include "display.hpp"

namespace gw
{

DisplayCLI::DisplayCLI()
{

}


void DisplayCLI::refresh(const statistics_t * data)
{
    CONSOLE_CLEAN;
    std::cout << "Statistics:\tSend: " << data->bytesSend << "\tRecv: " << data->bytesRecv << std::endl; 

}


} //namespace gw
