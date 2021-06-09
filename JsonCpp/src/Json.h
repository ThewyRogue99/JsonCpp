#pragma once
#include "JsonData.h"

class Json
{
public:
	Json() { data = new JsonData(JsonTypes::TypeNull); }

	void AddString(std::string string);

	void AddNumber(int val);

	void AddNumber(float val);

	void AddBool(bool val);

	void AddArray(std::vector<JsonString> list);
	
	void AddArray(std::vector<JsonNumber> list);
	
	void AddArray(std::vector<JsonBool> list);
	
	void AddArray(std::vector<JsonObject> list);
	
	void AddArray(std::vector<JsonArray> list);

	void Print() { std::cout << data->GetString() << std::endl; }

private:
	JsonData* data;
};