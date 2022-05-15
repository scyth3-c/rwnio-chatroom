#pragma once
#ifndef RWNIO_H
#define RWNIO_H


constexpr auto RWNIO_WARNING = "-[THIS IS A WARNING]-";
constexpr auto RWNIO_ERROR = "-[CRITIAL ERROR]-";
constexpr auto RWNIO_INFO = "-]";

constexpr auto CURL_DECORATOR = "_IN CURL RESPONSE_";
constexpr auto SYSTEM_DECORATOR = "_BAD SYSTEM RESPONSE_";

#define RWNIO_HTTP_URL "http://localhost:3000/"
#define TEST_DOMAIN "http://example.com/"


#if defined(_WIN32) || defined(_WIN64) 
  #define RWNIO_SYS_CLEAR "cls"
#else 
  #define RWNIO_SYS_CLEAR "clear"
#endif

#include <ostream>

#define C std::cout
#define N "\n"
#define T "\t"

namespace rwnio {

template<class...A>
void screen(std::ostream& access, A const&... params)
{
	((access << params), ...);
}

};



#endif // !RWNIO_H