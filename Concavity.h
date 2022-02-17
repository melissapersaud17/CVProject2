
#ifndef CONCAVITY_H
#define CONCAVITY_H

#include <iostream>
using namespace std;

class Concavity{
    private: 
        int numRows;
        int numCols;
        int minVal;
        int maxVal;

        int x1;
        int y1;
        int x2;
        int y2;

        double m;
        double b;

        int *histAry;

        int maxHeight;
        int bestThrVal;

        int *displayGraphs;

    public:
        Concavity();

        void setArray(int *histogramArray);

        void setRows(int rows);
        void setCols(int cols);
        void setMin(int min);
        void setMax(int max);

        void setMaxHeight(int maxHeight);
        int getMaxHeight();

        int getMax();
        int getRows();
        int* getArray();

        void setX1(int x1);
        void setY1(int y1);
        void setX2(int x2);
        void setY2(int y2);

        int loadHist(ifstream& inFile);
        void printHist();

        int DeepestConcavity();

        void plotOneRow();

        void printGraph();


};

#endif