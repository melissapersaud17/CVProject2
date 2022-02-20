
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

        int **displayGraphs;

    public:
        //constructor
        Concavity();

        //setter methods for rows, columns, min and max; getter method for maxVal
        void setRows(int rows);
        void setCols(int cols);
        void setMin(int min);
        void setMax(int max);
        int getMax();

        //setter method for histogram array 
        void setArray(int *histogramArray);
        int* getArray();

        //setter methods for x1, x2, y1 and y2
        void setX1(int x1);
        void setY1(int y1);
        void setX2(int x2);
        void setY2(int y2);
        int getX1();
        int getX2();
        int getY1();
        int getY2();

        //setter and getter method for setting the slope
        void setSlope(double slope);
        double getSlope();

        //setter and getter method for the y-intercept
        void setYIntercept(double yint);
        double getYIntercept();
        
        //setter method for displayGraph
        void setGraph(int **displayGraph);

        //setter and getter for maxHeight
        void setMaxHeight(int maxHeight);
        int getMaxHeight();

        //setter for bestThrVal;
        void setThrVal(int threshold);
        int getThrValue();

        //loadHistogram method
        int loadHist(ifstream& inFile);

        //displayHistogram method
        void dispHist(ofstream& outFile);

        //deepestConcavity method 
        int DeepestConcavity(int x1, int x2, double slope, double yIntercept, int **displayGraph);

        //plotOneRow method
        void plotOneRow(int x, int y, int **displayGraph);

        //printGraph method
        void printGraph(ofstream& outFile);

        //deconstructor method
        ~Concavity();


};

#endif