#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include <fstream>
#include <list>
#include <random>
#include "homeBaseType.h"

using namespace std;

void homeBaseType::plot()
		{
            fstream comfout;
            comfout.open("command.txt",ios::out);

            comfout<<"set xlabel \"x location\""<<endl;
            comfout<<"set ylabel \"y location\""<<endl;

            comfout<<"set xrange [0:100]"<<endl;
            comfout<<"set yrange [100:0]"<<endl;

            comfout<<"set terminal png"<<endl;

            comfout<<"set output \'0.png\'"<<endl;
            comfout<<"plot \"0.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'5.png\'"<<endl;
            comfout<<"plot \"5.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'10.png\'"<<endl;
            comfout<<"plot \"10.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'15.png\'"<<endl;
            comfout<<"plot \"15.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'20.png\'"<<endl;
            comfout<<"plot \"20.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'25.png\'"<<endl;
            comfout<<"plot \"25.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'30.png\'"<<endl;
            comfout<<"plot \"30.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'35.png\'"<<endl;
            comfout<<"plot \"35.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'40.png\'"<<endl;
            comfout<<"plot \"40.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'45.png\'"<<endl;
            comfout<<"plot \"45.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'50.png\'"<<endl;
            comfout<<"plot \"50.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'55.png\'"<<endl;
            comfout<<"plot \"55.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'60.png\'"<<endl;
            comfout<<"plot \"60.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'65.png\'"<<endl;
            comfout<<"plot \"65.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'70.png\'"<<endl;
            comfout<<"plot \"70.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'75.png\'"<<endl;
            comfout<<"plot \"75.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'80.png\'"<<endl;
            comfout<<"plot \"80.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'85.png\'"<<endl;
            comfout<<"plot \"85.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'90.png\'"<<endl;
            comfout<<"plot \"90.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;
            comfout<<"set output \'95.png\'"<<endl;
            comfout<<"plot \"95.txt\" using 2:1:3 with points pt 7 lc palette notitle, \"\" using 4:5 with points pt 10 notitle, \"\" using 6:7:(sqrt($8)) with circles notitle"<<endl;

             comfout<<"pause -1"<<endl;
             comfout.close();
            system("gnuplot command.txt");


		    return;
		}

