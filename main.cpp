///* 
// * File:   main.cpp
// * Author: mayowaayodele
// *
// * Created on 10 February 2017, 10:55
// */
//
//#include "stdafx.h"
#include <iostream>
#include <random>
//
//#include "Add.h"
//#include "RK.h"
#include "Tools.h"
#include "RK.h"
using namespace std;
#include <stdio.h> 
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include "EDAUtils.h"
#include "RKEDA.h"

int main () {
	
	 /*int FEs = 10000;
  //  int FEs = 266211000;
  int pSize =100;
   int populationSize  = 1000;
   int truncSize = populationSize/10;
   double stdev = 0.15;
     string fileName = "./taillard_instances/tai100_10_0.fsp";
	 string resultsName = "tai100_10_0.fsp";
   //string fileName = "./taillard_instances/tai500_20_9.fsp";
//   cout<<"truncSize: "<<truncSize<<endl;
	 */

	 int FEs =0, pSize = 0, populationSize = 0, truncSize = 0;
	 double stdev = 0;
	 string fileName = "", resultsName = "";
	 //char input[400] = "500 ../src/taillard_instances/ tai50_5_0.fsp 220712150 50 0 0.05 ../resultsA/ tai50_5_0P500T50V0.06e0run0.txt";
	// char input[400] = "1000 ../src/taillard_instances/ tai100_5_0.fsp 47175960 100 0 0.05 ../results/ tai100_5_0P1000T100V0.05e0run0.txt";
	 char input[400] = "5000 ../src/taillard_instances/ tai500_20_9.fsp 260316750 500 0 0.05 ../results/ tai500_20_9P5000T500V0.05e0run19.txt";


	 char *token = std::strtok(input, " ");



	 

	 while (token != NULL) {

		 populationSize = std::stoi(token);

		 token = std::strtok(NULL, " ");

		 fileName = token;

		 token = std::strtok(NULL, " ");

		 fileName += token;

		 fileName = fileName.replace(0, 6, ".");

		 token = std::strtok(NULL, " ");

		 FEs = std::stoi(token);

		 token = std::strtok(NULL, " ");

		 truncSize = std::stoi(token);

		 token = std::strtok(NULL, " ");

		 token = std::strtok(NULL, " ");

		 stdev = std::stod(token);

		 token = std::strtok(NULL, " ");

		 resultsName = token;

		 token = std::strtok(NULL, " ");

		 resultsName+= token;

		 resultsName = resultsName.replace(0, 1, "");

		 pSize = truncSize;

		 break;

	 }
	 std::cout << to_string(populationSize) + ", " + to_string(truncSize) + ", " + to_string(stdev) + ", " + to_string(FEs) + ", " +
		 fileName + ", " + resultsName + ", " + to_string(pSize) + ". " << endl;
	 /*
	 populationSize = std::stoi(args[0]);
	 truncSize = std::stoi(args[4]);
	 stdev = std::stod(args[6]);
	 FEs = std::stoi(args[3]);
	 fileName = args[1] + args[2];
	 resultsName = args[7] + args[8];
	 pSize = truncSize;*/
   RKEDA rkeda (pSize,populationSize, truncSize,stdev, FEs, fileName, resultsName);
   cout<<"start"<<endl;
   rkeda.runAlgorithm1(fileName, resultsName);

  return 0;
}


///* 
// * File:   main.cpp
// * Author: 1013288
// *
// * Created on 19 June 2017, 13:10
// */
//
//#include <cstdlib>
//#include <iostream>
//#include <random>
//#include "Tools.h"
//#include "RK.h"
//
//#include <stdio.h> 
//#include <iostream>     // std::cout
//#include <algorithm>    // std::sort
//#include <vector>       // std::vector
//#include "EDAUtils.h"
//#include "RKEDA.h"
//using namespace std;
///*
// * 
// */
//int main() {
//	 int FEs, pSize, populationSize, truncSize;
//	 double stdev;
//	 string fileName, resultsName;
//         pSize = 500;
//         populationSize = 500;
//         truncSize = 50;
//         stdev = 0.05;
////         FEs = 260316750;
//          FEs = 2603;
//         fileName = "./taillard_instances/tai500_20_0.fsp";
//        resultsName = "./resultsfull/tai500_20_0P500T50V0.05e0run0.txt";
//   RKEDA rkeda (pSize,populationSize, truncSize,stdev, FEs, fileName, resultsName);
//
//   cout<<"start"<<endl;
//   rkeda.runAlgorithm1(fileName, resultsName);
//      cout<<"end" << endl;
//      
//      return 0;
//
//}
//
