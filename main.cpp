#include "Concavity.h"

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]){

    //Concavity object
    Concavity co;

    //inFile 1
    string file1 = argv[1];
    ifstream inFile1;
    inFile1.open(file1);

    //inFile2
    ifstream inFile2;
    inFile2.open(argv[2]);

    // //outFile
    // ifstream outFile;
    // outFile.open(argv[3]);

    //read in numRows, numCols, minVal, maxVal
    int imageHeader[4] = {0};

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
   }

   //reading in file2
   int peakPoints[4] = {0};

   if(inFile2.good()){
        getline(inFile1, line);

        iss.clear();
        iss.str(line);

        int i = 0;

        while (iss >> number){ // only used for collecting the values from the image header
            peakPoints[i] = number;
            i++;
        }

        co.setRows(peakPoints[0]);
        co.setCols(peakPoints[1]);
        co.setMin(peakPoints[2]);
        co.setMax(peakPoints[3]);
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
    //int *display = new int[rows][columns]();

    




    return 0;
}