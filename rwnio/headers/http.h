#pragma once

#ifndef HTTP_H
#define HTTP_H

#define CURL_STATICLIB
#include <curl/curl.h>
#include <iostream>
#include <string>
#include <vector>
#include <functional>

#include "rwnio.h"

using std::string;

class HTTP {
private:

	CURL* curl;
	string URL;
	string response;

public:

	HTTP(string);

	static size_t callback(void*, size_t, size_t, string*);

	void get();
	void post(string);

	std::function<void(void)> test();

	string Response();
	string without(string, char);

};


#endif // !HTTP_H

