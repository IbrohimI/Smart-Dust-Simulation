#ifndef H_HOMEBASETYPE
#define H_HOMEBASETYPE

#include <list>
using namespace std;

class storeSignalType
{
private:
    int storeSignal;
public:
    void setStoreSignal(int storeSig)
    {
        storeSignal = storeSig;
    }
    int getStoreSignal()
    {
        return storeSignal;
    }
};

class storeSignalXType
{
private:
    int storeSignalX;
public:
    void setStoreSignalX(int storeSigX)
    {
        storeSignalX = storeSigX;
    }
    int getStoreSignalX()
    {
        return storeSignalX;
    }
};

class storeSignalYType
{
private:
    int storeSignalY;
    public:
    void setStoreSignalY(int storeSigY)
    {
        storeSignalY = storeSigY;
    }
    int getStoreSignalY()
    {
        return storeSignalY;
    }
};

class homeBaseType
{
public:
    list<storeSignalType> storeSignalList;
    list<storeSignalType>::iterator storeSignalItr;
    list<storeSignalXType> storeSignalXList;
    list<storeSignalXType>::iterator storeSignalXItr;
    list<storeSignalYType> storeSignalYList;
    list<storeSignalYType>::iterator storeSignalYItr;
    void plot();
};
#endif // H_HOMEBASETYPE
