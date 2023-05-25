#include<bits/stdc++.h>
using namespace std;

void removeDuplicates(int index, string &str, string &output, vector<bool> &count) {
    // base case 
    if (index == str.length()) {
        cout << output << " ";
        return;
    }
    
    // if elem is not present
    int i = str[index] - 'a';
    if (count[i] == 0) {
        count[i] = 1;
        output.push_back(str[index]);
        removeDuplicates(index+1, str, output, count);
    }
    else {
        // already added in output string
        removeDuplicates(index+1, str, output, count);
    }
}


int main () {
    string str;
    cin >> str;
    vector<bool> count(26, 0);

    string output = "";
    removeDuplicates(0, str, output, count);

    return 0;
}