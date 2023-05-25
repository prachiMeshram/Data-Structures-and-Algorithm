#include <bits/stdc++.h>
using namespace std;

void printAllSubseqWithSumK(char arr[], int i, string output, int n, int k, int sum) {
    // base case 
    
    if (sum == k) {
        cout << output << endl;
        return;
    }
    else if (i == n) {
        return;
    }

    // include
    printAllSubseqWithSumK(arr, i+1, output + arr[i], n, k, (sum + int (arr[i])));

    // exclude
    printAllSubseqWithSumK(arr, i+1, output, n, k, sum);
}

int main () {
    char arr[] = {'3', '1', '2'};
    int n = 3;

    int k;
    cin >> k;

    string output = "";

    int sum = 0;

    printAllSubseqWithSumK(arr, 0, output, n, k, sum);
    return 0;
}