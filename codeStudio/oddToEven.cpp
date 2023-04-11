// https://www.codingninjas.com/codestudio/problem-details/odd-to-even_1214553

#include <bits/stdc++.h> 
using namespace std;

string oddToEven(string &num) 
{
	// Write your code here
	string nums = num;
	int n = num.size();

	int temp = -1;

	int i = 0;
	int j= n-1;

	while (i<=n-2) {
		if (!(num[i] & 1)) {
			temp = i;
			if (num[i] < num[j]) {
				swap(num[i], num[j]);
				return num;
			}	
		}
		i++;
	}
	if (temp != -1) {
		swap(num[temp], num[j]);
		return num;
	}
	

	return "-1";
}

