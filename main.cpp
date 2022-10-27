#include "hesh.h"
#include <iostream>

int main()
{
	Hash table;
	for (int i = 0; i < 100; i++)
	{
		table.InsertHash(i);
		//std::cin >> table;
	}

	std::cout << table;

	return 0;
}