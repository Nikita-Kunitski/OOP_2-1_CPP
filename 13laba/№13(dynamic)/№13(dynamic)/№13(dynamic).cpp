#include <iostream>
#include <Windows.h>


typedef int(*MYPROC)();

int main()
{
	HMODULE hMod = LoadLibrary("¹13(DLL).dll");

	MYPROC ProcAddr = (MYPROC)GetProcAddress(hMod, "MyFunction");

	if (ProcAddr)
		std::cout << "Total number of free bytes: "<< ProcAddr()<<std::endl;

	FreeLibrary(hMod);
}