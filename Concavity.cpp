#include "Concavity.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


Concavity::Concavity(){
    cout << "concav construc" << endl;
}

void Concavity::setRows(int rows){
    this->numRows = rows;
}

int Concavity::getRows(){
    return this->numRows;
}

void Concavity::setCols(int cols){
    this->numCols = cols;
}

void Concavity::setMin(int min){
    this->minVal = min;
}

void Concavity::setMax(int max){
    this->maxVal = max;
}

int Concavity::getMax(){
    return this->maxVal;
}

void Concavity::setX1(int x1){
    this->x1 = x1;
}

void Concavity::setY1(int y1){
    this->y1 = y1;
}

void Concavity::setX2(int x2){
    this->x2 = x2;
}

void Concavity::setY2(int y2){
    this->y2 = y2;
}

void Concavity::setArray(int *histogramArray){
    this->histAry = histogramArray;
}

int* Concavity::getArray(){
    return this->histAry;
}

void Concavity::setMaxHeight(int maxHeight){
    this->maxHeight = maxHeight;
}

int Concavity::getMaxHeight(){
    return this->maxHeight;
}


//loads the histogram array and then returns the max height
int Concavity::loadHist(ifstream& inFile){

    int i = 0;

    string line;
    int number; 
    istringstream iss;

    if(inFile.is_open()){
        while(!inFile.eof()){
            getline(inFile, line);

            iss.clear();
            iss.str(line);

           iss >> number;
           int index = number;

           while (iss >> number){ 
                this->histAry[index] = number;
            }

        }
    }

    //finding the maxHeight
    int maxHeight = histAry[0];
    for(int i = 1; i < this->getMax()+1; i++){
        if(histAry[i] > maxHeight){
            maxHeight = histAry[i];
        }
    }

    return maxHeight;
}