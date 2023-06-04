// https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio

#include <bits/stdc++.h> 
using namespace std;

void addElem(stack<int> &stack, int num) {
	if (stack.empty() || stack.top() <= num) {
		stack.push(num);
		return;
	}

	int top = stack.top();
	stack.pop();

	addElem(stack, num);

	stack.push(top);

}
void sortStack(stack<int> &stack)
{
	// Write your code here
	// base case 
	if (stack.empty()) {
		return;
	}

	int num = stack.top();
	stack.pop();

	sortStack(stack);

	addElem(stack, num);
	
}