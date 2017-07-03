

#define EXPORT extern "C" __declspec (dllexport)
#define CLASS_EX __declspec (dllexport)

EXPORT int MyFunction();

extern "C" class __declspec (dllexport) myDll
{
public:
	static unsigned int classFunction();
};