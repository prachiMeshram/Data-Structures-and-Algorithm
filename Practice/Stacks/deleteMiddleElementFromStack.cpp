// https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=0&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio

#include <bits/stdc++.h> 
using namespace std;

void solve(stack<int>&inputStack, int size, int count) {
   // base case 
   if (count == size/2) {
      inputStack.pop();
      return;
   }

   int num = inputStack.top();
   inputStack.pop();

   solve(inputStack, size, count+1);

   inputStack.push(num);

}

void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   solve(inputStack, N, 0);
}