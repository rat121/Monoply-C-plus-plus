#include "stdafx.h"
#include "gFunctions.h"


int Random()//random
{
	return  static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}
