#pragma once
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class ClientData
{
public:
	ClientData();
	~ClientData();
	string MakeRequest(char type, vector<string> v, char sepr='/');

};

