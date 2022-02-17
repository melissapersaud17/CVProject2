
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
        //constructor
        Concavity();

        //setter methods for rows, columns, min and max
        void setRows(int rows);
        void setCols(int cols);
        void setMin(int min);
        void setMax(int max);

        //setter method for histogram array 
        void setArray(int *histogramArray);

        //setter methods for x1, x2, y1 and y2
        void setX1(int x1);
        void setY1(int y1);
        void setX2(int x2);
        void setY2(int y2);

        //getter methods for obtaining the maxVal 
        int getMax();
        int getRows();

        //setter method for displayGraph
        void setGraph(int *displayGraph);


        void setMaxHeight(int maxHeight);
        int getMaxHeight();

        int* getArray();


        int loadHist(ifstream& inFile);

        void dispHist(ofstream& outFile);

        int DeepestConcavity();

        void plotOneRow();

        void printGraph();


};

#endif