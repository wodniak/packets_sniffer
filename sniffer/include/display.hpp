#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iostream>
#include "common.hpp"
#include <ctime>

#define CONSOLE_CLEAN std::system("clear")

namespace gw
{

class DisplayCLI
{
public:
    DisplayCLI();
    void refresh(const statistics_t & data);
    status_t dump_to_file();

private:
    std::time_t date;   //Unix ts, start of application
    std::string fileName;   //log file name
};

} //namespace gw

#endif //DISPLAY_HP