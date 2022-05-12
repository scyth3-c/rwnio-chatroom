#pragma once
#ifndef RWNIO_H
#define RWNIO_H


constexpr auto RWNIO_WARNING = "-[THIS IS A WARNING]-";
constexpr auto RWNIO_ERROR = "-[CRITIAL ERROR]-";
constexpr auto RWNIO_INFO = "-]";

constexpr auto CURL_DECORATOR = "_IN CURL RESPONSE_";
constexpr auto SYSTEM_DECORATOR = "_BAD SYSTEM RESPONSE_";

#include <ostream>

template<class...A>
void screen(std::ostream& access, A const&... params)
{
	((access << params), ...);
}

#endif // !RWNIO_H