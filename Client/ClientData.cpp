#include "stdafx.h"
#include "ClientData.h"


ClientData::ClientData()
{
}


ClientData::~ClientData()
{
}

string ClientData::MakeRequest(char type, vector<string> v, char sepr)
{
	stringstream ss;
	ss << type << sepr;
	string request = ss.str();
	for (int i = 0; i < v.size(); i++)
	{
		request += v[i] + sepr;
	}
	return request;
}
