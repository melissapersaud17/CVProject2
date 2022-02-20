#include "Concavity.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


//constructor
Concavity::Concavity(){
}

//setter methods for rows, columns, minVal and MaxVal
void Concavity::setRows(int rows){
    this->numRows = rows;
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

//getter method to return the maxVal
int Concavity::getMax(){
    return this->maxVal;
}

//setter and getter for x1
void Concavity::setX1(int x1){
    this->x1 = x1;
}

int Concavity::getX1(){
    return this->x1;
}

//setter and getter for y1
void Concavity::setY1(int y1){
    this->y1 = y1;
}

int Concavity::getY1(){
    return this->y1;
}

//setter and getter for x2
void Concavity::setX2(int x2){
    this->x2 = x2;
}

int Concavity::getX2(){
    return this->x2;
}

//setter and getter for y2
void Concavity::setY2(int y2){
    this->y2 = y2;
}

int Concavity::getY2(){
    return this->y2;
}

//setter and getter method for slope
void Concavity::setSlope(double slope){
    this->m = slope;
}

double Concavity::getSlope(){
    return this->m;
}

//setter and getter method for y-intercept
void Concavity::setYIntercept(double yInt){
    this->b = yInt;
}

double Concavity::getYIntercept(){
    return this->b;
}

//setter and getter method for the histogram array
void Concavity::setArray(int *histogramArray){
    this->histAry = histogramArray;
}

int* Concavity::getArray(){
    return this->histAry;
}

//setter and getter method for the maxHeight
void Concavity::setMaxHeight(int maxHeight){
    this->maxHeight = maxHeight;
}

int Concavity::getMaxHeight(){
    return this->maxHeight;
}

//setter method for displaying the graph
void Concavity::setGraph(int **displayGraph){
    this->displayGraphs = displayGraph;
}

//setter and getter for threshold value
void Concavity::setThrVal(int threshold){
    this->bestThrVal = threshold;
}

int Concavity::getThrValue(){
    return this->bestThrVal;
}

//loads the histogram array and then returns the max height
int Concavity::loadHist(ifstream& inFile){

    //variables used to obtain the values from the inFile
    string line;
    istringstream iss;
    int number; 

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
    int findingMaxHeight = this->histAry[0];
    for(int i = 1; i < this->getMax()+1; i++){
        if(this->histAry[i] > findingMaxHeight){
            findingMaxHeight = this->histAry[i];
        }
    }

    return findingMaxHeight;
}

//display the histogram to the outfile 
void Concavity::dispHist(ofstream& outFile){
    int *pointer2 = (this->getArray());
        
    outFile << "2D Display of histogram " << endl;
    outFile << endl;
    if(outFile.is_open()){
        for (int i = 0; i < this->getMax() + 1; i++){
            outFile <<  i  << " " << "(" << pointer2[i] << "):";

            for(int x = 0; x < pointer2[i]; x++){
                outFile << "+"; 
            }

            outFile << endl;
        }
    }

}

//deepestConcavity method
int Concavity::DeepestConcavity(int x1, int x2, double slope, double yIntercept, int **displayGraph){
    int max = 0;
    int first = x1;
    int second = x2;
    int x = first;
    int thr = first;

    while(x <= second){
        int y = (slope * x) + yIntercept;
        
        plotOneRow(x,y,displayGraph);

        int gap = abs(this->histAry[x] - y);

        if(gap > max){
            max = gap;
            thr = x;
        }
        x++;
    }

    return thr;
}

//plotRow method
void Concavity::plotOneRow(int x, int y, int **displayGraph){
    int index = min(this->histAry[x],y);
    int last = max(this->histAry[x],y);

    while(index <= last){
        this->displayGraphs[x][index] = 3;
        index++;
    }

    this->displayGraphs[x][this->histAry[x]] = 1;
    this->displayGraphs[x][last] = 2;
}

//printGraph method
void Concavity::printGraph(ofstream& outFile){
    int rows = this->getMax()+1;
    int columns = this->getMaxHeight() + 1;
    for(int i =0; i < rows; i++){
        for(int x = 0; x < columns; x++){
            if(displayGraphs[i][x] == 0){
                outFile << " ";
            }else if (displayGraphs[i][x] == 1){
                outFile << "*";
            }else if(displayGraphs[i][x] == 2){
                outFile << "+";
            }else if(displayGraphs[i][x] == 3){
                outFile << "=";
            }
        }
        outFile << endl;
    }
}

Concavity::~Concavity(){
    delete[] histAry;
    delete[] displayGraphs;
}