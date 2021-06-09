#pragma once
#include <iostream>
#include <vector>

enum class JsonTypes
{
	TypeString = 3,
	TypeNumber,
	TypeBool,
	TypeNull,
	TypeObject,
	TypeArray
};

enum class JsonNumTypes
{
	TypeFloat,
	TypeInt
};

class JsonData
{
public:
	JsonData(JsonTypes type) : valType(type) { }

	virtual std::string GetString() { return "null"; }

private:
	JsonTypes valType;
};

class JsonString : public JsonData
{
public:
	JsonString() : JsonData(JsonTypes::TypeString) { }

	JsonString(std::string string)
		: value(string), JsonData(JsonTypes::TypeString) { }

	JsonString(const char* string)
		: value(string), JsonData(JsonTypes::TypeString) { }

	virtual std::string GetString() override;

private:
	std::string value;
};

class JsonNumber : public JsonData
{
public:
	JsonNumber(float val)
		: floatValue(val), intValue(0),
		JsonData(JsonTypes::TypeNumber),
		numType(JsonNumTypes::TypeFloat) { }

	JsonNumber(int val)
		: floatValue(0.f), intValue(val),
		JsonData(JsonTypes::TypeNumber),
		numType(JsonNumTypes::TypeInt) { }

	virtual std::string GetString() override;

private:
	float floatValue;
	int intValue;

	JsonNumTypes numType;
};

class JsonBool : public JsonData
{
public:
	JsonBool(bool val) : value(val),
		JsonData(JsonTypes::TypeBool) { }

	virtual std::string GetString() override;

private:
	bool value = false;
};

class JsonObject : public JsonData
{
private:
	std::string key;

	std::vector<JsonData> values;
};

class JsonArray : public JsonData
{
public:
	JsonArray(std::vector<JsonString> list) 
		: JsonData(JsonTypes::TypeArray) {

		ClearList();
		for (JsonString data : list)
			dataArray.push_back(new JsonString(data));
	}

	JsonArray(std::vector<JsonNumber> list)
		: JsonData(JsonTypes::TypeArray) {

		ClearList();
		for (JsonNumber data : list)
			dataArray.push_back(new JsonNumber(data));
	}

	JsonArray(std::vector<JsonBool> list)
		: JsonData(JsonTypes::TypeArray) {

		ClearList();
		for (JsonBool data : list)
			dataArray.push_back(new JsonBool(data));
	}

	JsonArray(std::vector<JsonObject> list)
		: JsonData(JsonTypes::TypeArray) {

		ClearList();
		for (JsonObject data : list)
			dataArray.push_back(new JsonObject(data));
	}

	JsonArray(std::vector<JsonArray> list)
		: JsonData(JsonTypes::TypeArray) {

		ClearList();
		for (JsonArray data : list)
			dataArray.push_back(new JsonArray(data));
	}


	virtual std::string GetString() override;

private:
	std::vector<JsonData*> dataArray;

	void ClearList();
};