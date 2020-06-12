#ifndef H_FLECHETTETYPE
#define H_FLECHETTETYPE
#include <list>
using namespace std;

class flechetteLocationXType
{
private:
    int flechetteLocationX;
public:
        void setFlechetteLocationX(int flechetteLocX)
        {
            flechetteLocationX = flechetteLocX;
        }
        int getFlechetteLocationX()
        {
            return flechetteLocationX;
        }

};

class flechetteLocationYType
{
    private:
        int flechetteLocationY;
    public:
        void setFlechetteLocationY(int flechetteLocY)
        {
            flechetteLocationY = flechetteLocY;
        }
        int getFlechetteLocationY()
        {
            return flechetteLocationY;
        }

};

class flechetteType
{
        public:
        int numberOfFlechette;
		int flechetteRange;
		int inRangeDustNum;
		list<inRangeDustIdType> inRangeDustIdList;
		list<inRangeDustIdType>::iterator inRangeDustIdItr;
        list<flechetteLocationXType> flechetteLocationXList;
        list<flechetteLocationXType>::iterator flechetteLocationXItr;
        list<flechetteLocationYType> flechetteLocationYList;
        list<flechetteLocationYType>::iterator flechetteLocationYItr;
        flechetteType();
		void makeFlechette(fieldType& field);
		void checkInRange(fieldType& field, dustType& dust);
};
#endif // H_FLECHETTETYPE
