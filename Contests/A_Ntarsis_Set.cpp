// #include<bits/stdc++.h>

// using namespace std;

// const long long int N = 1e6+2;
// const long long int MOD = 1e9+7;

// #define F	first
// #define S	second
// #define pb	push_back
// #define POB	pop_back
// #define MP	make_pair
// #define ump	unordered_map
// #define int	long long int
// typedef vector<string> vs;
// typedef vector<int> vi;
// typedef pair<int, int> pi;

// int32_t main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;

//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;
//         int k;
//         cin >> k;
//         vector<int> arr(n);
//         for (int i = 0; i < n; i++) {
//             cin >> arr[i];
//         }

//         int maxi = INT_MIN;
//         for (auto it: arr) {
//             maxi = max(maxi, it);
//         }

//         vector<int> temp(maxi+1);
//         temp.push_back(0);

//         for (int i = 1; i < maxi+1; i++) {
//             temp.push_back(i);
//         }

//         for (int i = 0; i < k; i++) {
//             for (auto it: arr) {
//                 temp[it] = -1;
//             }
//             vector<int> v(maxi+1);
//             v.push_back(0);
//             for (auto it: temp) {
//                 if (it != -1) {
//                     v.push_back(it);
//                 }
//             }
//             int j = *(v.end()- 1);
//         }
//     }

//     return 0;
// }

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    // initializing the variables
    int H, W, h, w, row, col, flag = 0;
    // taking input the dimensions of the grid
    cin >> H >> W;
    // declaring a 2d array for storing the strings present in grid
    string arr[H][W];
    // taking input the data of the grid
    for (int i = 0; i < H; i++)
    {
        string str, T;
        int j = 0;
        // taking input a row of string
        getline(cin, str);
        // this guarantees that getline function doesn't take an empty line as input
        while (str.length() == 0)
        {
            getline(cin, str);
        }
        // stringstream allow us to read from the string just like an input stream by associating a string object with it
        stringstream X(str);
        // reading the individual strings separated by ' ' from string object and saving them in given 2d array
        while (getline(X, T, ' '))
        {
            arr[i][j++] = T;
        }
    }
    // finding the location of 'snuke' by traversing the whole array and then breaking the loop as soon as we find it
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (arr[i][j] == "snuke")
            {
                h = i;
                w = j;
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    // printing the location of the 'snuke'
    row = h + 1;
    // adding 65 (ASCII code of 'A') so that we can get the output in alphabetic character
    col = w + 65;
    cout << char(col) << row;
    return 0;
}