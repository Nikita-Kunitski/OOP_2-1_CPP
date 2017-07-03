#include <Windows.h>
#include "myDLL.h"

int WINAPI DllMain(HINSTANCE hInstance, DWORD fdReason, PVOID pvReserved)
{
	return TRUE;
}

EXPORT unsigned int CALLBACK MyFunction()
{
	_MEMORYSTATUS* s = new _MEMORYSTATUS;
	::GlobalMemoryStatus((LPMEMORYSTATUS)s);
	int a = s->dwAvailPhys;

	return a;
}

unsigned int CALLBACK myDll::classFunction()
{
	_MEMORYSTATUS* s = new _MEMORYSTATUS;
	::GlobalMemoryStatus((LPMEMORYSTATUS)s);
	int a = s->dwAvailPhys;

	return a;
}