#pragma once
#ifndef MESSAGE_H
#define MESSAGE_H
#pragma warning(disable : 4996)

#include <memory>

#include <string>
#include <vector>
#include "http.h"

using std::move;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::vector;

struct MSG_t {
	MSG_t(string data[2]) {
		hora = move(data[0]);
		creador = move(data[1]);
		contenido = move(data[2]);
	}
	string hora;
	string creador;
	string contenido;
};

class Message {

private:

	shared_ptr<MSG_t> Response = nullptr;
	shared_ptr<string> creador = nullptr;
	shared_ptr<string> URL = nullptr;
	shared_ptr<HTTP> http = nullptr;

public:
	explicit Message(string creador);
	    ~Message();

		MSG_t reasing(string);
		string compact(string);
		void setUrl(string);
		string send(string);
		MSG_t last();
		string clearify(string);
};



#endif // !MESSAGE_H
