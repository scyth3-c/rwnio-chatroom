#include "user.h"


User::~User() {
	isLogin.reset();
}

User::User(string user, string apodo, string pass, string url) : UserName(user), Apodo(apodo), URL(url) {
	isLogin = make_shared<bool>(false);
	PassWord = make_shared<string>(pass);
	response = "no login";
}

void User::Login() {

	http = make_unique<HTTP>(URL+"login");
	string query = "apodo=" + Apodo + "&clave=" + *PassWord;

	http->post(query);
	if (http->Response() != "" || http->Response() != "404")
	{
		isLogin.reset();
		isLogin = make_unique<bool>(true);
		response = http->Response();
	}
	else {
		response = "datos incorrectos!";
	}
	PassWord.reset();
	http.reset();
}

void User::Register() {

	http = make_unique<HTTP>(URL + "saveme");
	string query = "nombre="+UserName + "&apodo=" + Apodo + "&clave=" + *PassWord;

	http->post(query);
	response = http->Response();

	PassWord.reset();
	http.reset();
}

void User::LogOut() {
	this->~User();
}
string User::Response() { return response; }
