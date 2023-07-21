// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

#include<bits/stdc++.h>
using namespace std;

class KthLargest {
    int size;
    priority_queue<int, vector<int>, greater<int> > pq;
    public:
    KthLargest(int k, vector<int>& nums) {
        size = k;

        for(auto it: nums) {
            if(pq.size() < k) {
                pq.push(it);
                continue;
            }
            if (it > pq.top()) {
                pq.pop();
                pq.push(it);
            }
        }
    }
    
    int add(int val) {
        if (pq.size() < size) {
            pq.push(val);
            return pq.top();
        }
        if (pq.top() < val) {
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
