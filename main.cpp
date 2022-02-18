#include "Concavity.h"

#include <iostream>
#include <fstream>
#include <sstream>
#define width 10
#define height 15

using namespace std;

int main(int argc, char* argv[]){

    //Concavity object
    Concavity co;

    //inFile 1
    string file1 = argv[1];
    ifstream inFile1;
    inFile1.open(file1);

    //inFile2
    string file2 = argv[2];
    ifstream inFile2;
    inFile2.open(file2);

    //outFile
    string outFile1 = argv[3];
    ofstream outFile;
    outFile.open(outFile1);

    //read in numRows, numCols, minVal, maxVal
    int *imageHeader = new int[4]();

    int number;
    string line;
    istringstream iss;

    if(inFile1.good()){
        getline(inFile1, line);

            iss.clear();
            iss.str(line);

            int i = 0;

            while (iss >> number){ // only used for collecting the values from the image header
                imageHeader[i] = number;
                i++;
            }

            co.setRows(imageHeader[0]);
            co.setCols(imageHeader[1]);
            co.setMin(imageHeader[2]);
            co.setMax(imageHeader[3]);

            delete[] imageHeader;
   }

   //reading in file2
   int *peakPoints = new int[4]();

   if(inFile2.good()){
        getline(inFile2, line);

        iss.clear();
        iss.str(line);

        int i = 0;

        while (iss >> number){ // only used for collecting the values from the image header
            peakPoints[i] = number;
            i++;
        }

        co.setX1(peakPoints[0]);
        co.setY1(peakPoints[1]);
        co.setX2(peakPoints[2]);
        co.setY2(peakPoints[3]);

        delete[] peakPoints;
    }


    //creates and initializes the histAry
    int size = co.getMax() + 1;
    int *histogram = new int[size]();
    co.setArray(histogram); //sets the array for the Concavity object to 0 

    //the maxHeight will get set from the loadHist method 
    co.setMaxHeight(co.loadHist(inFile1));

    //dynamically allocate displayGraph array and initalizes it 
    const int rows = co.getMax()+1;
    const int columns = co.getMaxHeight() + 1;
    int *displayG = new int[rows*columns]();  
    co.setGraph(displayG);

    co.dispHist(outFile);

    //calculating the slope
    double rise = co.getY2() - co.getY1();
    double run = co.getX2() - co.getX1();
    co.setSlope(rise/run);

    //calculating the y-intercept
    double yIntercept = co.getY1() - (co.getSlope() * co.getX1());
    






    return 0;
}