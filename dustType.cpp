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

using namespace std;

        dustType::dustType()
		{
			//default_random_engine generator(time(0));
			//normal_distribution<double> distribution(8, 3);
			srand(time(0));
		}
		void dustType::makeDust(fieldType& field)
		{
		    int idNum;
		    int dustLocX;
		    int dustLocY;
			dustIdType *newNode;
			dustLocationXType *newNode1;
			dustLocationYType *newNode2;
			int num;
			cout << "How many dusts?: ";
			cin >> num;
			for(int index = 0; index < num; index++)
			{
				newNode = new dustIdType;
				idNum = index;
				newNode->setIdNumber(idNum);
				dustIdList.push_back(*newNode);
				newNode1 = new dustLocationXType;
				//newNode1->dustLocationX = int(distribution(generator)) + field.getRow() / 2;
				dustLocX = rand() % 40;
				newNode1->setDustLocationX(dustLocX);
				dustLocationXList.push_back(*newNode1);
				newNode2 = new dustLocationYType;
				dustLocY = rand() % 100;
                newNode2->setDustLocationY(dustLocY);
                dustLocationYList.push_back(*newNode2);
				field.fieldArray[newNode1->getDustLocationX()][newNode2->getDustLocationY()] = 'x';
			}
		}



