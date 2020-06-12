#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include <fstream>
#include <list>
#include <random>
#include "fieldType.h"
#include "dustType.h"
#include "flechetteType.h"
#include "inputType.h"
#include "homeBaseType.h"

using namespace std;

int main()
{
	fieldType field;
	dustType dust;
	flechetteType flechette;
	inputType input;
	homeBaseType homeBase;

	dust.makeDust(field);
	flechette.makeFlechette(field);
	flechette.checkInRange(field, dust);
	input.moveInput(field, dust, flechette, homeBase);
	homeBase.plot();

	return 0;
}
