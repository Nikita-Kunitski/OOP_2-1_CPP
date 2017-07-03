#include <iostream>
#include <Windows.h>
using namespace std;

typedef int(MESS)();

int main()
{
	HMODULE hMod = ::LoadLibrary(L"Win32Project(DLL).dll");

	
	MESS* ProcAddr = (MESS*)::GetProcAddress(hMod, "MyFunction");

	if (ProcAddr)
		cout << "Free bytes: "<< ProcAddr() <<std::endl;

	FreeLibrary(hMod);
}