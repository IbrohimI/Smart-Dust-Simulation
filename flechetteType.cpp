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

using namespace std;

        flechetteType::flechetteType()
        {
			inRangeDustNum = 0;
			flechetteRange = 10;
            srand(time(0));
        }
		void flechetteType::makeFlechette(fieldType& field)
        {
            flechetteLocationXType *newNode1;
            flechetteLocationYType *newNode2;
            int flechetteLocX;
            int flechetteLocY;
			int num;
			cout << "How many flechettes?: ";
			cin >> num;
            for(int index = 0; index < num; index++)
            {
                newNode1 = new flechetteLocationXType;
                flechetteLocX = rand() % 40;
                newNode1->setFlechetteLocationX(flechetteLocX);
                flechetteLocationXList.push_back(*newNode1);
                newNode2 = new flechetteLocationYType;
                flechetteLocY = rand() % 100;
                newNode2->setFlechetteLocationY(flechetteLocY);
                flechetteLocationYList.push_back(*newNode2);
                field.fieldArray[newNode1->getFlechetteLocationX()][newNode2->getFlechetteLocationY()] = 'F';
            }
        }
		void flechetteType::checkInRange(fieldType& field, dustType& dust)
        {
            int tempX;
			int tempY;
			int tempY1;
			int temp;
			int index5 = 0;

			inRangeDustIdType *newNode;
			int inRanDustId;

			flechetteLocationXItr = flechetteLocationXList.begin();
			flechetteLocationYItr = flechetteLocationYList.begin();
			while(flechetteLocationXItr != flechetteLocationXList.end())
			{
				tempX = flechetteLocationXItr->getFlechetteLocationX() - flechetteRange;
				tempY = flechetteLocationYItr->getFlechetteLocationY();
				tempY1 = 0;
				temp = 0;
				if(tempX < 0)
				{
					tempX = 0;
				}
				for(int index1 = tempX; index1 <= flechetteLocationXItr->getFlechetteLocationX(); index1++)
				{
					if(index1 == field.getRow())
					{
						break;
					}
					temp = temp + 1;
					tempY1 = sqrt(pow(flechetteRange, 2) - pow((flechetteRange - temp), 2));
					for(int index2 = flechetteLocationYItr->getFlechetteLocationY() - tempY1;
							index2 < flechetteLocationYItr->getFlechetteLocationY() + tempY1; index2++)
					{
						if(index2 == field.getLength())
						{
							break;
						}
						else if(index2 < 0)
						{
							index2 = 0;
						}
						if(index2 == flechetteLocationYItr->getFlechetteLocationY() - tempY1
								|| index2 == flechetteLocationYItr->getFlechetteLocationY() + tempY1 - 1)
						{
							if(field.fieldArray[index1][index2] == ' ' )
							{
								field.fieldArray[index1][index2] = '.';
							}
						}
						if(field.fieldArray[index1][index2] == 'x' )
                        {
							inRangeDustNum = inRangeDustNum + 1;
							dust.dustIdItr = dust.dustIdList.begin();
							dust.dustLocationXItr = dust.dustLocationXList.begin();
							dust.dustLocationYItr = dust.dustLocationYList.begin();
							while(dust.dustIdItr != dust.dustIdList.end())
                            {
                                if(dust.dustLocationXItr->getDustLocationX() == index1 &&
                                   dust.dustLocationYItr->getDustLocationY() == index2)
                                {
                                    newNode = new inRangeDustIdType;
                                    inRanDustId = dust.dustIdItr->getIdNumber();
                                    newNode->setInRangeDustId(inRanDustId);
                                    inRangeDustIdList.push_back(*newNode);
                                    break;
                                }
                                dust.dustIdItr++;
                                dust.dustLocationXItr++;
                                dust.dustLocationYItr++;
                            }
                        }
					}
				}
				tempX = flechetteLocationXItr->getFlechetteLocationX();
                tempY = flechetteLocationYItr->getFlechetteLocationY();
                tempY1 = 0;
                temp = flechetteRange;
				for(int index1 = tempX + 1; index1 <= flechetteLocationXItr->getFlechetteLocationX() +
						flechetteRange; index1++)
                {
					if(index1 == field.getRow())
					{
						break;
					}
					temp = temp - 1;
					tempY1 = sqrt(pow(flechetteRange, 2) - pow((flechetteRange - temp), 2));
					for(int index2 = flechetteLocationYItr->getFlechetteLocationY() - tempY1;
                                    index2 <= flechetteLocationYItr->getFlechetteLocationY() + tempY1; index2++)
                    {
						if(index2 == field.getLength())
                        {
                            break;
                        }
                        else if(index2 < 0)
                        {
                            index2 = 0;
                        }
						if(index2 == flechetteLocationYItr->getFlechetteLocationY() - tempY1
                                                                || index2 == flechetteLocationYItr->getFlechetteLocationY() + tempY1)
                        {
                            if(field.fieldArray[index1][index2] == ' ' )
                            {
                                field.fieldArray[index1][index2] = '.';
                            }
                        }
						if(field.fieldArray[index1][index2] == 'x' )
                        {
                            inRangeDustNum = inRangeDustNum + 1;
                            dust.dustIdItr = dust.dustIdList.begin();
							dust.dustLocationXItr = dust.dustLocationXList.begin();
							dust.dustLocationYItr = dust.dustLocationYList.begin();
							while(dust.dustIdItr != dust.dustIdList.end())
                            {
                                if(dust.dustLocationXItr->getDustLocationX() == index1 &&
                                   dust.dustLocationYItr->getDustLocationY() == index2)
                                {
                                    newNode = new inRangeDustIdType;
                                    inRanDustId = dust.dustIdItr->getIdNumber();
                                    newNode->setInRangeDustId(inRanDustId);
                                    inRangeDustIdList.push_back(*newNode);
                                    break;
                                }
                                dust.dustIdItr++;
                                dust.dustLocationXItr++;
                                dust.dustLocationYItr++;
                            }
                        }
					}
				}
				flechetteLocationXItr++;
                flechetteLocationYItr++;
			}
		}



