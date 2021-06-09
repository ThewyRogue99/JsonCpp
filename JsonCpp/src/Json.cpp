#include "Json.h"

void Json::AddString(std::string string)
{
	delete data;
	data = new JsonString(string);
}

void Json::AddNumber(int val)
{
	delete data;
	data = new JsonNumber(val);
}

void Json::AddNumber(float val)
{
	delete data;
	data = new JsonNumber(val);
}

void Json::AddBool(bool val)
{
	delete data;
	data = new JsonBool(val);
}

void Json::AddArray(std::vector<JsonString> list)
{
	delete data;
	data = new JsonArray(list);
}

void Json::AddArray(std::vector<JsonNumber> list)
{
	delete data;
	data = new JsonArray(list);
}

void Json::AddArray(std::vector<JsonBool> list)
{
	delete data;
	data = new JsonArray(list);
}

void Json::AddArray(std::vector<JsonObject> list)
{
	delete data;
	data = new JsonArray(list);
}

void Json::AddArray(std::vector<JsonArray> list)
{
	delete data;
	data = new JsonArray(list);
}