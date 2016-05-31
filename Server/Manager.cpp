#include "stdafx.h"
#include "../Server/Manager.h"

Manager::Manager()
{
}

Manager::~Manager()
{
}

int Manager::getType(string msg, char sepr) {

	return atoi(msg.substr(0, msg.find(sepr)).c_str());
}

string Manager::getLogin(string msg, char sepr) {

	string l_p = msg.substr(msg.find(sepr) + 1);
	string l = l_p.substr(0, l_p.find(sepr));

	return l;
}

string Manager::getPassword(string msg, char sepr) {

	string l_p = msg.substr(msg.find(sepr) + 1);
	string p_sh = l_p.substr(l_p.find(sepr) + 1);
	string p = p_sh.substr(0, p_sh.length() - 1);

	return p;
}

string Manager::getRang(string msg, char sepr) {

	string r_sh = msg.substr(msg.find(sepr) + 1);
	string r = r_sh.substr(0, r_sh.length() - 1);

	return r;
}

string Manager::makeResponse(string msg, char sepr) {

	int type = getType(msg, sepr);
	stringstream ss;
	ss.clear();

	switch (type) {
		case 1: {
			dbUsers db;
			ss	<< type 
				<< sepr
				<< db.checkAuth(getLogin(msg, sepr), getPassword(msg, sepr)) 
				<< sepr;
			break;
		}
	}

	return ss.str();
}

string Manager::makeActions(string msg, char sepr) {

	int type = getType(msg, sepr);
	stringstream ss;
	ss.clear();

	switch (type) {
		case 1: {
			ss << getRang(msg, sepr);
			break;
		}
	}

	return ss.str();
}
