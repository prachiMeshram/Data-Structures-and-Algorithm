// https://www.codingninjas.com/studio/problems/maximum-xor-with-an-element-from-array_1382020?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h>
using namespace std;

class Node {
	Node* links[2];

	public:
	bool containsKey(int bit) {
		return links[bit] != NULL;
	}

	Node* get(int bit) {
		return links[bit];
	}

	void add(int bit, Node* node) {
		links[bit] = node;
	}
}; 

class Trie {
	Node* root;

	public:
	Trie() {
		root = new Node();
	}

	void insert(int num) {
		Node* node = root;

		for (int i = 31; i >= 0; i--) {
			int bit = (num >> i) & 1;
			if(!node->containsKey(bit)) {
				node->add(bit, new Node());
			}
			node = node->get(bit);
		}

	}

	int getMax(int num) {
		Node* node = root;
		int maxi = 0;

		for (int i = 31; i >= 0; i--) {
			int bit = (num >> i) & 1;
			if (node->containsKey(!bit)) {
				maxi = maxi | (1 << i);
				node = node->get(!bit);
			}
			else {
				node = node->get(bit);
			}
		}

		return maxi;
	}
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.

	int n = arr.size();
	int q = queries.size();

	vector<int> ans(q, 0);

	vector<pair<int, pair<int, int>>> offQueries;
	int i = 0;
	for (auto & it: queries) {
		offQueries.push_back({it[1], {it[0], i++}});
	}

	sort(offQueries.begin(), offQueries.end());

	Trie t;
	int j = 0;
	sort(arr.begin(), arr.end());

	for (auto & it: offQueries) {
		int Ai = it.first;
		int xi= it.second.first;
		int ind = it.second.second;

		while (j < n && arr[j] <= Ai) {
			t.insert(arr[j]);
			j++;
		}

		if (j != 0) {
			ans[ind] = t.getMax(xi);
		}
		else {
			ans[ind] = -1;
		}
	}
	return ans;
}