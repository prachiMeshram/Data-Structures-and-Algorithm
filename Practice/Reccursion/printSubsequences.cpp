// https://www.youtube.com/watch?v=AxNNVECce8c&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=6

#include<bits/stdc++.h>
using namespace std;

void printAllSubsequences(char arr[], int i, string output, int n) {
    // base case 
    if (i == n) {
        if (output.size() == 0) {
            cout << "{}";
        }
        cout << output << endl;
        return;
    }

    // include
    printAllSubsequences(arr, i+1, output + arr[i], n);

    // exclude
    printAllSubsequences(arr, i+1, output, n);
    
}

int main () {
    char arr[] = {'3', '1', '2'};
    int n = 3;

    string output = "";

    printAllSubsequences(arr, 0, output, n);

    return 0;
}