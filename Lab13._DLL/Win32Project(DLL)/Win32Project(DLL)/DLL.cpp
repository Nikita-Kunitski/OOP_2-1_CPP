#include <Windows.h>
#include "DLL.h"

int WINAPI DllMain(HINSTANCE hInstance, DWORD fdReason, PVOID pvReserved)
{
	return TRUE;
}

EXPORT int MyFunction()
{
	_MEMORYSTATUS* s = new _MEMORYSTATUS;
	::GlobalMemoryStatus((LPMEMORYSTATUS)s);
	int a = s->dwAvailPhys;

	return a;
}

unsigned int myDll::classFunction()
{
	_MEMORYSTATUS* s = new _MEMORYSTATUS;
	::GlobalMemoryStatus((LPMEMORYSTATUS)s);
	int a = s->dwAvailPhys;

	return a;
}