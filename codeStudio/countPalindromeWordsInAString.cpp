// https://www.codingninjas.com/codestudio/problems/count-palindrome-words-in-a-sentence_975378

#include <bits/stdc++.h> 
using namespace std;

bool isPalindrome(int s, int e, string p) {
	while (s<=e) {
		if(p[s++]!=p[e--]) {
			return false;
		}
	}
	return true;
}
int countNumberOfPalindromeWords(string s) {
	
	if (s.size()==0) {
		return 0;
	}
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	int count = 0;
	string word;

	int i = 0;

	while (i<s.size()) {
		if (s[i] == ' ') {
			if (isPalindrome(0, word.size()-1, word)) {
				count++;
			}
			word.clear();
			while (s[i] == ' ') {
				i++;
			}
		}
		else {
			word.push_back(s[i++]);
		}
	}

	if (isPalindrome(0, word.size()-1, word)) {
		count++;
	}
	return count;
}

// int countNumberOfPalindromeWords(string s)
// {
// 	//Your code goes here
// 	if (s.size()==1) {
// 		return 1;
// 	}
// 	if (s.size()==0) {
// 		return 0;
// 	}

// 	transform(s.begin(), s.end(), s.begin(), ::tolower);
// 	int count = 0;

// 	int j = 0;
// 	int i = 0;
	
// 	while (j < s.size()) {

// 		while (s[j] != ' ' && j < s.size()) {
// 			j++;
// 		}
		
// 		if (isPalindrome(i, (j-1), s)) {
// 			count++;
// 		}
// 		j++;
// 		while (s[j] == ' ' && j<s.size()) {
// 			j++;
// 		}
// 		i = j;
		
// 	}

// 	return count;
// }