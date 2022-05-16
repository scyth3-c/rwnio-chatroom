#pragma once
#ifndef MESSAGE_H
#define MESSAGE_H
#pragma warning(disable : 4996)

#include <memory>

#include <string>
#include <vector>
#include "http.h"

using std::make_shared;
using std::move;
using std::shared_ptr;
using std::string;
using std::vector;

struct MSG_t
{
	MSG_t(string data[4])
	{
		hora = move(data[0]);
		creador = move(data[1]);
		contenido = move(data[2]);
		secreto = move(data[3]);
	}
	MSG_t() : hora(" "), creador(" "), contenido(" "), secreto("public"){};
	string hora;
	string creador;
	string contenido;
	string secreto;
};

class Message
{

private:
	shared_ptr<MSG_t> Response = nullptr;
	shared_ptr<string> creador = nullptr;
	shared_ptr<string> URL = nullptr;
	shared_ptr<HTTP> http = nullptr;

	shared_ptr<string> secreto = nullptr;

public:
	explicit Message(string creador, string secreto);
	~Message();

	MSG_t reasing(string);
	string compact(string);
	void setUrl(string);
	string send(string);
	MSG_t last(int);
	string clearify(string);
};

#endif // !MESSAGE_H
