#ifndef H_INPUTTYPE
#define H_INPUTTYPE
#include "homeBaseType.h"

using namespace std;

class inputType
{
	private:
		int inputLocationX;
        int inputLocationY;
		fieldType field;
		homeBaseType homeBase;
        char obj;
	public:
		inputType();
		void moveInput(fieldType& field, dustType& dust, flechetteType& flechette, homeBaseType& homeBase);
		void readDustSignal(fieldType& field, dustType& dust, flechetteType& flechette, homeBaseType& homeBase);
		void plot();
};
#endif // H_INPUTTYPE


