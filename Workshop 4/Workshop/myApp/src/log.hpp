#ifndef _LOG_HPP_
#define _LOG_HPP_

#include <iostream>

// dirty hack for linux alway enabling debug
#if defined(_DEBUG) || defined(__linux__)
#define LOG_DEBUG   std::cout  << __FILE__<< " " << __LINE__ << " " <<  __FUNCTION__ << std::endl;
#else
#define LOG_DEBUG
#endif
#endif
