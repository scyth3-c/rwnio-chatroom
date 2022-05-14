#pragma once

#ifndef HTTP_H
#define HTTP_H


#define CURL_STATICLIB
#include <curl/curl.h>
#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "rwnio.h"

using std::string;

class HTTP {
private:

	std::shared_ptr<CURL*> curl = nullptr;
	std::vector<CURLcode> performs;
	unsigned int queryIndice=0;
	string URL{};
	string response{};

public:

	HTTP(string);
    ~HTTP();
	static size_t callback(void*, size_t, size_t, string*);

	void get();
	void post(string);
	void post(string, string);

	string Response();
	string without(string, char);
	string genPerfomList();

};


#endif // !HTTP_H

