#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iostream>
#include "basic_sniffer.h"

#define CONSOLE_CLEAN std::system("clear")

namespace gw
{

class DisplayCLI
{
public:
    DisplayCLI();
    void refresh(const statistics_t * data);

private:
    
};

} //namespace gw

#endif //DISPLAY_HP