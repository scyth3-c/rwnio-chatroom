#include "http.h"


HTTP::HTTP(string url) : URL(url) {
	curl = std::make_shared<CURL*>(curl_easy_init());
	if (!curl) {
		screen(std::cout, RWNIO_ERROR, SYSTEM_DECORATOR); 
		}
}

HTTP::~HTTP() {
	curl.reset();
}

size_t HTTP::callback(void* buffer, size_t size, size_t nmemb, string* data) {
	size_t rsize = size * nmemb;
	try {
		data->append(static_cast<const char* >(buffer), rsize);
	}
	catch (std::bad_alloc& e) {
		screen(std::clog, &e);
	}
	return rsize;
}


void HTTP::get()
{
	curl_easy_setopt(*curl, CURLOPT_URL, URL.c_str());
	curl_easy_setopt(*curl, CURLOPT_WRITEFUNCTION, HTTP::callback);
	curl_easy_setopt(*curl, CURLOPT_WRITEDATA, &response);
	CURLcode perfom = curl_easy_perform(*curl);
	performs.push_back(perfom);

	try {
		if(perfom != CURLE_OK) screen(std::clog, RWNIO_WARNING,CURL_DECORATOR,perfom);
	} catch(std::exception& error) {
		screen(std::cout, RWNIO_ERROR, &error);
	}
	curl_easy_cleanup(*curl);
}



void HTTP::post(string fields) {

	curl_easy_setopt(*curl, CURLOPT_URL, URL.c_str());
	curl_easy_setopt(*curl, CURLOPT_WRITEFUNCTION, HTTP::callback);
	curl_easy_setopt(*curl, CURLOPT_POSTFIELDS, fields.c_str());
	curl_easy_setopt(*curl, CURLOPT_WRITEDATA, &response);
	
	CURLcode perfom = curl_easy_perform(*curl);
	performs.push_back(perfom);

	try {
		if(perfom != CURLE_OK) screen(std::clog, RWNIO_WARNING,CURL_DECORATOR,perfom);
	} catch(std::exception& error) {
		screen(std::cout, RWNIO_ERROR, &error);
	}
	curl_easy_cleanup(*curl);
}

string HTTP::Response() {
	return without(response, char(34));
}

string HTTP::without(string target, char key ) {
	for (auto &it : target) {
		if (it == key) { it = char(00); }
	}
	return target;
}

string HTTP::genPerfomList() {
	int map{};
	for(auto &it: performs) {
		map += it;
	}
	return std::to_string(map);
}

