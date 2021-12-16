#include "GC.h"

GC::GC(int i)
{
	this->compt = i;
}

void GC::increment()
{
	this->compt++;
}

int GC::decriment()
{
	
	return --this->compt;
}
