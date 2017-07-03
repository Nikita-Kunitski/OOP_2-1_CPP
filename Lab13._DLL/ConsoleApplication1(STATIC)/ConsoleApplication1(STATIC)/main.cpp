#pragma comment(lib,"Win32Project(DLL)")

#include "DLL.h"
#include <iostream>

void main()
{
	std::cout << "Total number of free bytes: " << MyFunction() << std::endl;
}