//Question Link => https://www.codingninjas.com/codestudio/problems/internship-experience_1381937

#include <bits/stdc++.h>
using namespace std;

bool compareMinGainedPair(pair<int, int> A, pair<int, int> B){
	return (A.second > B.second);
}

void solve(int index, int &currExp, int &internCount, int n, vector<pair<int, int>> &minGained, vector<int> visited){
	//base case
	if(internCount == 0 || index == n){
		return;
	}

	if(minGained[index].first <= currExp && visited[index] == 0){
		currExp += minGained[index].second;
		internCount--;
		visited[index] = 1;
		index = -1;
	}

	return solve(index + 1, currExp, internCount, n, minGained, visited);

}

int internshipExp(int d, int k, int n, vector<int> &minExp, vector<int> &expGained) {
	// Write your code here

	int currExp = d;
	int internCount = k;

	vector<int> visited(n,0);
	vector<pair<int, int>> minGained;

	for(int i = 0; i < n; i++){
		pair<int, int> temp;
		temp.first = minExp[i];
		temp.second = expGained[i];
		minGained.push_back(temp);
	}

	sort(minGained.begin(), minGained.end(), compareMinGainedPair);

	solve(0, currExp, internCount, n, minGained, visited);

	return currExp;

}