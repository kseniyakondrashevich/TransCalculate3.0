#pragma once

#include <string>
#include <sstream>
#include "../Server/dbUsers.h"

using namespace std;

class Manager
{
public:
	Manager();
	~Manager();
	int getType(string msg, char sepr = '/');
	string getLogin(string msg, char sepr = '/');
	string getPassword(string msg, char sepr = '/');
	string getRang(string msg, char sepr = '/');
	string makeResponse(string msg, char sepr = '/');
	string makeActions(string msg, char sepr = '/');
};

