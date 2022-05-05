#pragma once
#ifndef MESSAGE_H

#include <string>

using std::string;

class Message {

private:

	string hora;
	string autor;
	string contenido;

public:

	void send();
	void extract();
	void last();

};


#endif // !MESSAGE_H
