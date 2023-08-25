// https://www.codingninjas.com/studio/problems/631055?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0?s

#include <bits/stdc++.h> 
using namespace std;

void sort012(int *arr, int n)
{
   //   Write your code here
   int low = 0;
   int mid = 0;
   int high = n-1;

   while (mid <= high) {
       if (arr[mid] == 0) {
           swap(arr[mid], arr[low]);
           mid++;
           low++;
       }
       else if (arr[mid] == 1) {
           mid++;
       }
       else {
           swap(arr[mid], arr[high]);
           high--;
       }
   }
}