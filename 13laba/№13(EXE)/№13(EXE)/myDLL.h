

#define EXPORT extern "C" __declspec (dllexport)
#define CLASS_EX __declspec (dllexport)

EXPORT unsigned int CALLBACK MyFunction();

class myDll
{
public:
	static __declspec(dllexport) unsigned int CALLBACK classFunction();
};