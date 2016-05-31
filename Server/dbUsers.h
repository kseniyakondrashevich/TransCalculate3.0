#pragma once

// dbUsers

#include "../Server/SQLiteDatabase.h"

#define ADMIN "admin"

class dbUsers : public SQLiteDatabase
{
	DECLARE_DYNAMIC(dbUsers)

public:
	dbUsers();
	virtual ~dbUsers();
	bool addUser(const string login, const string password);
	bool removeUser(const string login);
	void SelectUsers(const string _where = "");
	string checkAuth(string login, string password);

protected:
	DECLARE_MESSAGE_MAP()
};


