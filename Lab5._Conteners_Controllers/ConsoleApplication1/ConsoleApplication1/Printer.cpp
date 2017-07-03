#include "stdafx.h"
#include "printer.h"
#include <iostream>

using namespace std;

void Printer::IAmPrinting(Documents *someobj)
{
	cout<<typeid(someobj).name();
	someobj->to_Console();
}