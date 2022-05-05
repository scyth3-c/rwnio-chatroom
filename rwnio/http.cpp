#include "http.h"


HTTP::HTTP(string url) : URL(url) {
	curl = curl_easy_init();
	if (!curl) {
		screen(std::cout, RWNIO_ERROR, SYSTEM_DECORATOR);
	}
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

	curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, HTTP::callback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
	CURLcode resolve = curl_easy_perform(curl);

	try
	{
		if (resolve != CURLE_OK) {
			screen(std::clog, RWNIO_WARNING,CURL_DECORATOR,resolve);
		}
	}
	catch (std::exception& e) {
		screen(std::cout, RWNIO_ERROR, &e);
	}

	curl_easy_cleanup(curl);
}

void HTTP::post(string fields) {

	curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, HTTP::callback);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, fields.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
	CURLcode resolve = curl_easy_perform(curl);

	try
	{
		if (resolve != CURLE_OK) {
			screen(std::clog, RWNIO_WARNING, CURL_DECORATOR, resolve);
		}
	}
	catch (std::exception& e) {
		screen(std::cout, RWNIO_ERROR, &e);
	}

	curl_easy_cleanup(curl);
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
