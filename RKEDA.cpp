/* 
 * File:   RKEDA.cpp
 * Author: mayowaayodele
 * 
 * Created on 13 February 2017, 22:09
 */
//#include "stdafx.h"
#include "RKEDA.h"
#include "EDAUtils.h"
#include "Tools.h"
#include "PFSP.h"



RKEDA::RKEDA(int probSize, int popSize, int trunSize, double stdev, int FEs, std::string filename, std::string results) {
    problemSize = probSize;
    populationSize = popSize;
    truncationSize = trunSize;
    variance = stdev;
    fitnessEvaluations = FEs;
    fileName = filename;
    fileNameResults = results;
}


void RKEDA::runAlgorithm1(string fileName, string fileNameResults) {

    //    ofstream myfile;
    //  myfile.open ("./results/fsp" + std::to_string(truncationSize) +".txt");

    //    myfile.open(fileNameResults);
    string results = "FileName \t Solution \tFitness \t err \t FEs \n";
    string results1 = "FileName \t Solution \tFitness \t err \t FEs \n";

    int noOfEvals = 0;
    int numberofGenerations = (fitnessEvaluations / populationSize);
    cout << "number of gens: " << numberofGenerations << endl;
    //    vector<RK*> pop = e.initialPopulationRK(problemSize, populationSize, fileName);
    RK* bestSolution;
    fsp.ReadInstance(fileName);
    vector<RK*> pop(populationSize);
    vector<RK*> population(populationSize);
    for (int i = 0; i < populationSize; i++) {

        double* childAct = new double[problemSize];
        for (int x = 0; x < problemSize; x++) {
            double r = ((double) rand() / (RAND_MAX));
            childAct[x] = r;

        }
        RK* child = new RK(childAct, problemSize);
        //          RK child(childAct, problemSize);
        child->setPermutation(e.randomKeyToAL(childAct, problemSize));
        child->normalise();
        child->setFitness(fsp.EvaluateFSPTotalFlowtime(child->getPermutation()));
        pop[i] = (child);

        if (i == 0) {
            bestSolution = child;
        } else {
            if (bestSolution->getFitness() > child->getFitness()) {
                bestSolution = child;
            }
        }
        delete[] childAct;
        //        delete child;
    }



    cout << "end initialisation" << endl;
    for (int i = 0; i <= numberofGenerations; i++) {
        if (noOfEvals >= fitnessEvaluations) {
            break;
        }
        double coolingParameter = 1 - ((double) i / numberofGenerations);
        variance = variance * coolingParameter;
        // cout<<"stdev: "<<variance<<endl;
        double* matrix = new double[problemSize];
        matrix = e.getPM(pop, truncationSize, problemSize);

        //        pop.clear();
        std::random_device generator;
        for (int j = 0; j < populationSize; j++) {

            double* childAct = new double[problemSize];
            for (int x = 0; x < problemSize; x++) {
                //             double r2 = r.nextGaussian() * currentModel[x][1] + currentModel[x][0];
                double mean = matrix[x];

                std::normal_distribution<double> distribution(mean, variance);
                double r2 = distribution(generator);
                childAct[x] = r2;

            }
            RK* child = new RK(childAct, problemSize);
         
            //            RK child(childAct, problemSize);
            child->setPermutation(e.randomKeyToAL(childAct, problemSize));
            child->normalise();
            child->setFitness(fsp.EvaluateFSPTotalFlowtime(child->getPermutation()));
            noOfEvals++;
            if (noOfEvals >= fitnessEvaluations) {
                break;
            }
            population[j] = child;

            if (bestSolution->getFitness() > child->getFitness()) {
                bestSolution = child;
                cout << "gen: " + to_string(i) << endl;
                cout << bestSolution->getFitness() << endl;
                results1 = fileName + "\t" + e.perm2str(bestSolution->getPermutation(), problemSize) + "\t" + std::to_string(bestSolution->getFitness()) + "\t" + "0" + "\t" + to_string(noOfEvals) + "\n";
//                results += results1;
            }
           // delete[] childAct;
        }
        for (int i = 0; i < pop.size(); i++)
	{
		pop[i]->~RK();
	}
        pop = population;

        //        population.clear();
        //        cout << "gen: " + to_string(i) << endl;
        //        cout << bestSolution->getFitness() << endl;
        //        results1 = fileName + "\t" + e.perm2str(bestSolution->getPermutation(), problemSize) + "\t" + std::to_string(bestSolution->getFitness()) + "\t" + "0" + "\t" + to_string(noOfEvals) + "\n";
        //		   results += fileName + "\t" + e.perm2str(bestSolution->getPermutation(), problemSize) + "\t" + std::to_string(bestSolution->getFitness()) + "\t" + "0" + "\t" + to_string(e.getNumberofEvaluations()) + "\n";
        //        results += results1;

        //	 cout <<results<<endl;
        //        myfile << results;
        //        myfile.close();
        delete[] matrix;
        //        population.clear();

    }
    for (int i = 0; i < population.size(); i++)
	{
                population[i]->~RK();
	}
   
    delete bestSolution;

    fsp.~PFSP();
    ofstream myfile1;
    myfile1.open(fileNameResults.replace(fileNameResults.end() - 4, fileNameResults.end(), "all.txt"));
    myfile1 << results1;
    myfile1.close();
    cout << "ended" << endl;

}

