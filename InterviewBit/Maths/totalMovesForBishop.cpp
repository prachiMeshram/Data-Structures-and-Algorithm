// https://www.interviewbit.com/problems/total-moves-for-bishop/discussion/p/c-singleline-solution/348168/2031/

#include<bits/stdc++.h>
using namespace std;

int solve(int A, int B) {
    return  min(B-1,A-1) + min(8-B,A-1) + min(8-B,8-A) + min(B-1,8-A);

    // int count = 0;
    
    // int tempA = A;
    // int tempB = B;
    // // top right
    // while (tempA<8 && tempB<8) {
    //     tempA++;
    //     tempB++;
    //     count++;
    // }
    // // top left
    // tempA = A;
    // tempB = B;
    // while (tempA>=0 && tempB<8) {
    //     tempA--;
    //     tempB++;
    //     count++;
    // }
    // // bottom right
    // tempA = A;
    // tempB = B;
    // while (tempA<8 && tempB>=0) {
    //     tempA++;
    //     tempB--;
    //     count++;
    // }
    // // bottom left
    // tempA = A;
    // tempB = B;
    // while (tempA>=0 && tempB>=0) {
    //     tempA--;
    //     tempB--;
    //     count++;
    // }
    
    
    // BISHOPS MOVES
    // // topL
    // if ((A-1)>=0 && (B+2)<=7) {
    //     count++;
    // }
    
    // // topR 
    // if ((A+1)<=7 && (B+2)<=7) {
    //     count++;
    // }
    
    // // rightT
    // if ((A+2)<=7 && (B+1)<=7) {
    //     count++;
    // }
    
    // // rightD
    // if ((A+2)><7 && (B-1)>=0) {
    //     count++;
    // }
    
    // // bottomL
    // if ((A-1)>=0 && (B-2)>=0) {
    //     count++;
    // }
    
    // // bottomR
    // if ((A+1)<=7 && (B-2)>=0) {
    //     count++;
    // }
    
    // // leftT
    // if ((A-2)>=0 && (B+1)<=7) {
    //     count++;
    // }
    
    // // leftB
    // if ((A-2)>=0 && (B-1)>=0) {
    //     count++;
    // }
    
    // return count;
}
