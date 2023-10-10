// https://www.codingninjas.com/studio/problem-of-the-day/easy?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

char findAddedCharacter(string &s, string &t) {
    // Write your code here.
    int oldSum = 0;
    for (auto it: s) {
        oldSum += it;
    }
    int newSum = 0;
    for (auto it: t) {
        newSum += it;
    }

    return (char)(newSum-oldSum);
}