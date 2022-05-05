#pragma once

#ifndef USER_H
#define USER_H

#include<memory>
#include <vector>
#include <string>

#include "http.h"

using std::vector;
using std::string;

using std::make_unique;
using std::make_shared;
using std::unique_ptr;
using std::shared_ptr;

class User {
private:
	
	shared_ptr<bool> isLogin = nullptr;
	string UserName;
	string Apodo;
	shared_ptr<string> PassWord = nullptr;
	string response;
	string URL;
	unique_ptr<HTTP> http = nullptr;

public:


	explicit User(string user,string apodo, string pass, string url);
	~User();

	void Register();
	void Login();
	void LogOut();
	string Response();
};



#endif // !USER_H
