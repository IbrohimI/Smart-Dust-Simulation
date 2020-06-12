#ifndef H_DUSTTYPE
#define H_DUSTTYPE
#include <list>
using namespace std;

class dustIdType
{
private:
    int idNumber;
public:
    void setIdNumber(int idNum)
    {
        idNumber = idNum;
    }
    int getIdNumber()
    {
        return idNumber;
    }
};

class inRangeDustIdType
{
private:
    int inRangeDustId;
public:
    void setInRangeDustId(int inRanDustId)
    {
        inRangeDustId = inRanDustId;
    }
    int getInRangeDustId()
    {
        return inRangeDustId;
    }
};

class dustLocationXType
{
private:
	int dustLocationX;
public:
    void setDustLocationX(int dustLocX)
    {
        dustLocationX = dustLocX;
    }
    int getDustLocationX()
    {
        return dustLocationX;
    }
};

class dustLocationYType
{
private:
	int dustLocationY;
public:
    void setDustLocationY(int dustLocY)
    {
        dustLocationY = dustLocY;
    }
    int getDustLocationY()
    {
        return dustLocationY;
    }
};

class signalStrengthType
{
private:
	int signalStrength;
public:
    void setSignalStrength(int signalStr)
    {
        signalStrength = signalStr;
    }
    int getSignalStrength()
    {
        return signalStrength;
    }
};

class dustType
{
	public:
		int numberOfDust;
		list<dustIdType> dustIdList;
		list<dustIdType>::iterator dustIdItr;
		list<dustLocationXType> dustLocationXList;
		list<dustLocationXType>:: iterator dustLocationXItr;
		list<dustLocationYType> dustLocationYList;
		list<dustLocationYType>::iterator dustLocationYItr;
		list<signalStrengthType> signalStrengthList;
		list<signalStrengthType>::iterator signalStrengthItr;
		//default_random_engine generator;
        //normal_distribution<double> distribution;
		dustType();
		void makeDust(fieldType& field);
};
#endif // H_DUSTTYPE



