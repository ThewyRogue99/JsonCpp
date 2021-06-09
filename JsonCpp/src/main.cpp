#include <iostream>
#include "Json.h"

int main()
{
	Json json;

	std::vector<JsonNumber> list = { 5, 32, 23, 235, 51, 124, 41214, 142, 3 };

	std::vector<JsonNumber> list2 = { 93,32,2,3,4,681,2,24,15,1 };

	std::vector<JsonArray> arr = { list, list2 };

	json.AddArray(arr);

	json.Print();

	return 0;
}