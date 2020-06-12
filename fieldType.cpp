#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include <fstream>
#include <list>
#include <random>
#include "fieldType.h"

using namespace std;

                fieldType::fieldType()
                {
                        row = 40;
                        length = 100;
                        for(int index1 = 0; index1 < row; index1++)
                        {
                                for(int index2 = 0; index2 < length; index2++)
                                {
                                        fieldArray[index1][index2] = ' ';
                                }
                                cout << endl;
                        }

                }
                int fieldType::getRow()
                {
                        return row;
                }
                int fieldType::getLength()
                {
                        return length;
                }
                void fieldType::draw()
                {
                        for(int index1 = 0; index1 < row; index1++)
                        {
                                for(int index2 = 0; index2 < length; index2++)
                                {
                                        cout << fieldArray[index1][index2];
                                }
                                cout << endl;
                        }
                }



