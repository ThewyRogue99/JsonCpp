#include "JsonData.h"
#include <string>

std::string JsonString::GetString()
{
	JsonData::GetString();

	std::string result = '\"' + value + '\"';

	return result;
}

std::string JsonNumber::GetString()
{
	JsonData::GetString();

	std::string result = "";

	if (numType == JsonNumTypes::TypeInt)
		result = std::to_string(intValue);
	else if (numType == JsonNumTypes::TypeFloat)
		result = std::to_string(floatValue);

	return result;
}

std::string JsonBool::GetString()
{
	return value ? "true" : "false";
}

std::string JsonArray::GetString()
{
	JsonData::GetString();

	std::string result = "";

	result += '[';

	size_t arraySize = dataArray.size();

	for (size_t i = 0; i < arraySize; i++)
	{
		JsonData* data = dataArray[i];

		result += data->GetString();

		if (i == arraySize - 1)
			result += ']';
		else
			result += ", ";
	}

	return result;
}

void JsonArray::ClearList()
{
	for (JsonData* data : dataArray)
		delete data;

	dataArray.clear();
}