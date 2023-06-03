#include<bits/stdc++.h>
using namespace std;

int main () {

    // creation of staxk
    stack<int> s;

    // push operation 
    s.push(2);
    s.push(2);
    
    cout << " printing top element" << s.top() << endl;

    if (s.empty()) {
        cout << "stack is empty" << endl;
    }
    else {
        cout << "stack is not empty" << endl;
    }

    cout << "size of stack is " << s.size() << endl;

    
    return 0;
}