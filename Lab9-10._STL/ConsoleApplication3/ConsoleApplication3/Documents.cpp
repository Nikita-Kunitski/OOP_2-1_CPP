#include "stdafx.h"
#include "Documents.h"

Documents::Documents(string Name){
	name=Name;
}

string Documents::getName()
{
	return name;
}

void Documents::setName(string Name)
{
	name=Name;
}

std::ostream& operator << (std::ostream& output, Documents * object)
{
	output<<object->name;
	return output;
}

std::ostream& operator << (std::ostream& output, Documents & object)
{
	output<<object.name;
	return output;
}
