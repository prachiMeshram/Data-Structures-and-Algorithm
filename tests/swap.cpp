#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    
    for (int k = 1; k <= t; k++) {
        int n;
        cin>>n;
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        int count = 0;
        int i = 0; 
        while (i < n-1) {
            int j = i+1;
            if(arr[i]%2==0 && arr[j]%2==0) {
                while (j<n){
                    if(arr[j]%2 == 0) {
                        swap(arr[i], arr[j]);
                        count++;
                        break;
                    }
                    else {
                        j++;
                    }
                }
                if(j==n) {
                    cout<<"-1"<<endl;
                    return 0;;
                }
            }
            else if (arr[i]%2==1 && arr[j]%2==1){
                while (j<n){
                    if(arr[j]%2==0) {
                        swap(arr[i], arr[j]);
                        count++;
                        break;
                    }
                    else {
                        j++;
                    }
                }
                if(j==n) {
                    cout<<"-1"<<endl;
                    return 0;;
                }
            }
            i += 2;
        }
        cout<<count<<endl;
    }
    
    return 0;
}
