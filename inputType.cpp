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

        inputType::inputType()
		{
			obj = 'O';
            inputLocationX = field.getRow() / 2;
            inputLocationY = 0;
		}
		void inputType::moveInput(fieldType& field, dustType& dust, flechetteType& flechette, homeBaseType& homeBase)
		{
			bool isTrue = true;
			char temp;

			while(inputLocationY != field.getLength() - 1)
            {
                system("cls");
				field.fieldArray[inputLocationX][inputLocationY] = obj;
				field.draw();
                field.fieldArray[inputLocationX][inputLocationY] = ' ';
				if(isTrue)
				{
					field.fieldArray[inputLocationX][inputLocationY] = temp;
					isTrue = false;
				}
                inputLocationY = inputLocationY + 1;
				if(field.fieldArray[inputLocationX][inputLocationY] != ' ')
				{
					temp = field.fieldArray[inputLocationX][inputLocationY];
					isTrue = true;
				}
				readDustSignal(field, dust, flechette, homeBase);
                dust.signalStrengthList.clear();

				///field.draw();
            }



            inputLocationY = 0;
            homeBase.storeSignalItr = homeBase.storeSignalList.begin();
            homeBase.storeSignalXItr = homeBase.storeSignalXList.begin();
            homeBase.storeSignalYItr = homeBase.storeSignalYList.begin();
            flechette.flechetteLocationXItr = flechette.flechetteLocationXList.begin();
            flechette.flechetteLocationYItr = flechette.flechetteLocationYList.begin();
            while(inputLocationY != field.getLength())
            {
			    ofstream outFile;
			    outFile.open(to_string(inputLocationY) + ".txt");

                int index = 0;
                while(homeBase.storeSignalItr != homeBase.storeSignalList.end())
                {
                    outFile << homeBase.storeSignalXItr->getStoreSignalX() << "     "
                            << homeBase.storeSignalYItr->getStoreSignalY() << "     "
                            << homeBase.storeSignalItr->getStoreSignal() << "     "
                            << inputLocationY << "     "
                            << inputLocationX << "     "
                            << flechette.flechetteLocationYItr->getFlechetteLocationY() << "     "
                            << flechette.flechetteLocationXItr->getFlechetteLocationX() << "     "
                            << 100
                            << endl;
                    index++;
                    homeBase.storeSignalItr++;
                    homeBase.storeSignalXItr++;
                    homeBase.storeSignalYItr++;
                    flechette.flechetteLocationXItr++;
                    flechette.flechetteLocationYItr++;
                    if(flechette.flechetteLocationXItr == flechette.flechetteLocationXList.end())
                    {
                        flechette.flechetteLocationXItr = flechette.flechetteLocationXList.begin();
                        flechette.flechetteLocationYItr = flechette.flechetteLocationYList.begin();
                    }
                    if(index == flechette.inRangeDustIdList.size())
                    {
                        outFile.close();
                        break;
                    }
                }
                inputLocationY = inputLocationY + 1;
			}


			flechette.inRangeDustIdList.clear();
			homeBase.storeSignalList.clear();
			homeBase.storeSignalXList.clear();
			homeBase.storeSignalYList.clear();
		}
		void inputType::readDustSignal(fieldType& field, dustType& dust, flechetteType& flechette, homeBaseType& homeBase)
		{
			double distance;

            double dustX;
            double dustY;
            storeSignalType *newNode1;
            storeSignalXType *newNode2;
            storeSignalYType *newNode3;
            signalStrengthType *newNode;
            int signalStr;

			dust.dustLocationXItr = dust.dustLocationXList.begin();
			dust.dustLocationYItr = dust.dustLocationYList.begin();
            int index1;
            int index2 = 0;

            int storeSig;
            int storeSigX;
            int storeSigY;

			while(dust.dustLocationXItr != dust.dustLocationXList.end())
			{
				int signal = 0;
				newNode = new signalStrengthType;
				if(dust.dustLocationXItr->getDustLocationX() < inputLocationX)
				{
					dustX = inputLocationX - dust.dustLocationXItr->getDustLocationX();
					if(inputLocationY < dust.dustLocationYItr->getDustLocationY())
					{
						dustY = dust.dustLocationYItr->getDustLocationY() - inputLocationY;
                        distance = sqrt(pow(dustX, 2) + pow(dustY, 2));
                        index1 = 90;
						for(int index = 100; index >= 0; --index)
                        {
							index2++;
                            if(index2 == 9)
                            {
								signal++;
								index2 = 0;
							}
                            --index1;
                            if(index1 == 0)
                                break;
                            if(distance < index && distance >= index1)
                            {
								signalStr = signal;
								newNode->setSignalStrength(signalStr);
								dust.signalStrengthList.push_back(*newNode);
                                break;
                            }
                        }
					}
					else
					{
						dustY = inputLocationY - dust.dustLocationYItr->getDustLocationY();
						distance = sqrt(pow(dustX, 2) + pow(dustY, 2));
                        index1 = 90;
                        for(int index = 100; index >= 0; --index)
                        {
							index2++;
							if(index2 == 9)
							{
								signal++;
								index2 = 0;
							}
                            --index1;
                            if(index1 == 0)
                                break;
                            if(distance < index && distance >= index1)
                            {
                                signalStr = signal;
								newNode->setSignalStrength(signalStr);
                                dust.signalStrengthList.push_back(*newNode);
                                break;
                            }
                        }
					}
				}
				else
				{
					dustX = dust.dustLocationXItr->getDustLocationX() - inputLocationX;
					if(inputLocationY < dust.dustLocationYItr->getDustLocationY())
                    {
                        dustY = dust.dustLocationYItr->getDustLocationY() - inputLocationY;
                        distance = sqrt(pow(dustX, 2) + pow(dustY, 2));
                        index1 = 90;
                        for(int index = 100; index >= 0; --index)
                        {
							index2++;
							if(index2 == 9)
							{
								signal++;
								index2 = 0;
							}
                            --index1;
                            if(index1 == 0)
                                break;
                            if(distance < index && distance >= index1)
                            {
                                signalStr = signal;
								newNode->setSignalStrength(signalStr);
                                dust.signalStrengthList.push_back(*newNode);
                                break;
                            }
                        }
                    }
					else
                    {
                        dustY = inputLocationY - dust.dustLocationYItr->getDustLocationY();
                        distance = sqrt(pow(dustX, 2) + pow(dustY, 2));
                        index1 = 90;
                        for(int index = 100; index >= 0; --index)
                        {
							index2++;
							if(index2 == 9)
							{
								signal++;
								index2 = 0;
							}
                            --index1;
                            if(index1 == 0)
                                break;
                            if(distance < index && distance >= index1)
                            {
                                signalStr = signal;
								newNode->setSignalStrength(signalStr);
                                dust.signalStrengthList.push_back(*newNode);
                                break;
                            }
                        }
                    }
				}
				dust.dustLocationXItr++;
				dust.dustLocationYItr++;
			}

			dust.signalStrengthItr = dust.signalStrengthList.begin();
			dust.dustIdItr = dust.dustIdList.begin();
			flechette.inRangeDustIdItr = flechette.inRangeDustIdList.begin();
			dust.dustLocationXItr = dust.dustLocationXList.begin();
			dust.dustLocationYItr = dust.dustLocationYList.begin();

            while(dust.dustIdItr != dust.dustIdList.end())
            {
                flechette.inRangeDustIdItr = flechette.inRangeDustIdList.begin();
                while(flechette.inRangeDustIdItr != flechette.inRangeDustIdList.end())
                {
                    if(dust.dustIdItr->getIdNumber() == flechette.inRangeDustIdItr->getInRangeDustId())
                    {
                        newNode1 = new storeSignalType;
                        storeSig = dust.signalStrengthItr->getSignalStrength();
                        newNode1->setStoreSignal(storeSig);
                        homeBase.storeSignalList.push_back(*newNode1);
                        newNode2 = new storeSignalXType;
                        storeSigX = dust.dustLocationXItr->getDustLocationX();
                        newNode2->setStoreSignalX(storeSigX);
                        homeBase.storeSignalXList.push_back(*newNode2);
                        newNode3 = new storeSignalYType;
                        storeSigY = dust.dustLocationYItr->getDustLocationY();
                        newNode3->setStoreSignalY(storeSigY);
                        homeBase.storeSignalYList.push_back(*newNode3);
                        break;
                    }
                    flechette.inRangeDustIdItr++;
                }
                dust.dustIdItr++;
                dust.signalStrengthItr++;
                dust.dustLocationXItr++;
				dust.dustLocationYItr++;
            }


            return;
		}

