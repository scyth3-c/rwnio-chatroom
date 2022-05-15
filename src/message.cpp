#include "message.h"

Message::Message(string _creador,string _secreto)  {
	creador = make_shared<string>(_creador);
	secreto = make_shared<string>(_secreto);
}
Message::~Message() {
	http.reset();
	URL.reset();
	creador.reset();
	Response.reset();
	secreto.reset();
}

 void Message::setUrl(string temp) {	URL = make_shared<string>(temp); }

string Message::send(string mensaje) {
	http = make_shared<HTTP>(*URL+"insert");
	http->post(compact(mensaje));
	string response = http->Response();
	http.reset();
	return response;
}

MSG_t Message::last() {
	
	http = make_shared<HTTP>(*URL);
	http->post("last", "secreto="+*secreto);
	auto response = reasing(http->Response());
	http.reset();
	return response;
}

string Message::compact(string _mensaje) { return "creador=" + (*creador) + "&contenido=" + _mensaje + "&secreto="+*secreto;}

MSG_t Message::reasing(string target)
{
	string hora{};
	string creador{};
	string contenido{};
	string secreto{};

	string* it = &contenido;
	int pos = 0;
	for (int i = 0; i < target.length(); i++)
	{
		if (target[i] == ';' && pos==0) {
			pos = 1;
			it = &creador;
		}
		else if(target[i] == ';' && pos == 1) {
			it = &hora;
			pos = 2;
		} else if(target[i] == ';' && pos == 2) {
			it =& secreto;
		}
		*it += target[i];
	}
	string temp [4] = {clearify(hora),clearify(creador),clearify(contenido), clearify(secreto)};
	MSG_t tasty(temp);
	return tasty;
}

string Message::clearify(string target) {
		for (auto& it : target) {
			if (it == ';') { it = char(00); }
		}
		return target;
}