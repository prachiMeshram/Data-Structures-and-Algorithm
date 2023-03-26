
/*You have given a 2D array 'ARR' with 'N' rows and 'M' columns. The queries are given in a 2D array 'QUERIES' of size 'K', in which Queries[i] contains 4 integers denoting the left top and right bottom indices of the submatrix whose sum we need to find. Your task is to find the sum of the submatrix for each query given in the array 'Queries'.*/


#include <bits/stdc++.h> 
using namespace std;

int calQuerySum(vector<vector<int>> &arr, vector<int> &query) {
    int startX = query[0];
    int endX = query[2];
    int endY = query[3];

    int sum = 0;

    while (startX<=endX) {

        int startY = query[1];

        while (startY<=endY) {
            sum += arr[startX][startY]; 
            startY++;
        }
        
        startX++;
    }

    return sum;
}
vector<int> findSubmatrixSum(vector<vector<int>> &arr, vector<vector<int>> &queries) 
{
    // Write your code here
    vector<int> ans;

    for(int i = 0; i < queries.size(); i++) {
        int temp = calQuerySum(arr, queries[i]);
        ans.push_back(temp);
    }
    return ans;
}
