#include <iostream>
#include <vector>
using namespace std;

void minStepsReccur(vector<int> &A, vector<int> &B, int start, int destination, int &minSteps) {
    // BASE CASE
    if (destination<A.size()) {
        // processing 
        int xStart = A[start];
        int yStart = B[start];
        int xEnd = A[destination];
        int yEnd = B[destination];
        
        if (xStart<xEnd) {
            if (yStart<yEnd) {
                while (xStart<xEnd && yStart<yEnd) {
                    xStart++;
                    yStart++;
                    minSteps++;
                }
                while (xStart<xEnd) {
                    xStart++;
                    minSteps++;
                }
                while (yStart<yEnd) {
                    yStart++;
                    minSteps++;
                }
            }
            else {
                while (xStart<xEnd && yStart>yEnd) {
                    xStart++;
                    yStart--;
                    minSteps++;
                }
                while (xStart<xEnd) {
                    xStart++;
                    minSteps++;
                }
                while (yStart>yEnd) {
                    yStart--;
                    minSteps++;
                }
            }
        }
        else {
            if (yStart<yEnd) {
                while (xStart>xEnd && yStart<yEnd) {
                    xStart--;
                    yStart++;
                    minSteps++;
                }
                while (xStart>xEnd) {
                    xStart--;
                    minSteps++;
                }
                while (yStart<yEnd) {
                    yStart++;
                    minSteps++;
                }
            }
            else {
                while (xStart>xEnd && yStart>yEnd) {
                    xStart--;
                    yStart--;
                    minSteps++;
                }
                while (xStart>xEnd) {
                    xStart--;
                    minSteps++;
                }
                while (yStart>yEnd) {
                    yStart--;
                    minSteps++;
                }
            }
        }
        
        // while (xStart<xEnd && yStart<yEnd) {
        //     xStart++;
        //     yStart++;
        //     minSteps++;
        // }
        // while (xStart<xEnd) {
        //     xStart++;
        //     minSteps++;
        // }
        // while (yStart<yEnd) {
        //     yStart++;
        //     minSteps++;
        // }
        
        // recursion relation
        minStepsReccur(A, B, destination, destination+1, minSteps);
    }
}

int coverPoints(vector<int> &A, vector<int> &B) {
    int minSteps = 0;
    int n = A.size();
    
    int s = 0;
    int e = 1;
    
    minStepsReccur(A, B, s, e, minSteps);
    
    return minSteps;
}
