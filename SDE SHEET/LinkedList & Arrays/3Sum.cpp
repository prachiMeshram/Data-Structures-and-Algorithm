// https://www.codingninjas.com/studio/problems/893028?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    // store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// BETTER APPROACH
#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            // Calculate the 3rd element:
            int third = K - (arr[i] + arr[j]);

            // Find the element in the set:
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    // store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// OPTIMAL APPROACH
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            int sum = arr[i] + arr[l] + arr[r];
            if (sum == K)
            {
                vector<int> temp = {arr[i], arr[l], arr[r]};
                ans.push_back(temp);
                l++;
                r--;
                while (arr[l] == arr[l - 1])
                    l++;
                while (arr[r] == arr[r + 1])
                    r--;
            }
            else if (sum < K)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }

    return ans;
}