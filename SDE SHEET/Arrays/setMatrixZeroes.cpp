// https://leetcode.com/problems/set-matrix-zeroes/

#include <bits/stdc++.h> 
using namespace std;


// Brute Force
class Solution {

public:
    void markRow(int i, vector<vector<int>>& matrix) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }
    void markCol(int j, vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    markRow(i,matrix);
                    markCol(j,matrix);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// with (m+n) extra space 
class Solution {

public:

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n, 1);
        vector<int> col(m, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] == 0 || col[j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// optimum solution
class Solution {

public:

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int col0 = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(matrix[i][j] == 0 ) {
                    if (j == 0) {
                        col0 = 0;
                        matrix[i][0] = 0;
                    }
                    else {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (j == 0) {
                    if(col0 == 0) {
                    matrix[i][j] = 0;
                }
                }
                else if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};