// https://www.interviewbit.com/problems/is-rectangle/

int solve(int A, int B, int C, int D) {
    
    int temp[4] = {A, B, C, D};
    
    for(int i = 0; i < 4; i+=2) {
        if(temp[i]!=temp[i+1]) {
            return 0;
        }
    }
    return 1;
    // int xorr = A^B^C^D;
    // if (xorr == 0) {
    //     return 1;
    // }
    // else {
    //     return 0;
    // }
}
