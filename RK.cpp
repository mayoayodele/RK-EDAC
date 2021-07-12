//#include "stdafx.h"
#include <iostream>
using namespace std;
#include "RK.h"



//int* permutation= new int[IND_SIZE];

RK::RK(double randomkeys1[], int psize) {
    pSize = psize;
    randomkeys = new double[psize];
    permutation= new int[psize];
    for (int i = 0; i < psize; i++) {
        randomkeys[i] = randomkeys1[i];
    }
}

RK::~RK()
{
	delete[] randomkeys;
	delete[] permutation;

}

 RK* RK::Clone()
{
      //RK rk1(randomkeys, pSize);
	RK * ind = new RK(randomkeys, pSize);
	ind->setFitness(fitness);
	ind->setPermutation(permutation);
	return ind;
}
 

double RK::getFitness() {
    return fitness;
}

void RK::setFitness(double fitness1) {
    fitness = fitness1;
}

void RK::setProblemSize(int size) {
    pSize = size;
}

int RK::getProblemSize() {
    return pSize;
}

int* RK::getPermutation() {
    int* perm= new int[pSize];
    
    for (int i = 0; i < pSize; i++) {
        perm[i] = permutation[i];
    }
    return perm;
    //        return permutation;
}

void RK::setPermutation(int* perm) {
   
    for (int i = 0; i < pSize; i++) {
        permutation[i] = perm[i];
    }
}

double* RK::copyGene() {
    double* randomkeys1= new double[pSize];
    for (int i = 0; i < pSize; i++) {
        randomkeys1[i] = randomkeys[i];
    }
    return randomkeys1;
}

RK RK::copyOf() {

    RK rk1(randomkeys, pSize);
    rk1.setFitness(fitness);
    rk1.setPermutation(permutation);
    return rk1;
}

void RK::normalise() {
    for (int i = 0; i < pSize; i++) {
        //            AL[i] = (double)(ranks[i]-1)/(size-1);
        randomkeys[permutation[i]] = (double)((double)i /(pSize - 1));
    }
    //randomkeys = normaliseRanks(permutation);
}
 double* RK::getNormalisedRKs() 
 {
     return randomkeys;
 }




