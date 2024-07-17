/*
if the frog slips b units it effectively travels (a-b) units per seconds upwards.But in the last second it doesnt slip as it has escaped the well.by this logic (a-b)*(k-1)+a is the distance it can travel in k seconds and this distance must be greater than equal to h.

hence for a given possible a, if (a-b)*(k-1)+a>=h holds true for a value of b,it also holds true for b-1.hence binary search on b to find the maximum value of b for each possible value of a.


*/
#include <bits/stdc++.h>
using namespace std;
/*
if the frog slips b units it effectively travels (a-b) units per seconds upwards.But in the last second it doesnt slip as it has escaped the well.by this logic (a-b)*(k-1)+a is the distance it can travel in k seconds and this distance must be greater than equal to h.

hence for a given possible a, if (a-b)*(k-1)+a>=h holds true for a value of b,it also holds true for b-1.hence binary search on b to find the maximum value of b for each possible value of a.


*/
int main() {
    int T;
    cin >> T;
    while (T--) {
        long long N, K, H;
        cin >> N >> K >> H;
        
        long long count = 0;
        for (long long A = 1; A <= N; A++) {
            if(A>=H) 
            {
                count+=N;
                continue;
            }
            else{
                //to ye jo b wala code hai ky ham optimize kr skte hai kya
                //kyuki b to sorted pe hi lg rha hai n
                //to kyu na binary search se ham iska upper limit nikal le ki kon se b value at last hai jaha pe ye ((K -1)* (A - B))+A >= H true ho rha hai
                //jaha pe ho rha hga vo return kr dena
                //and kyuki usse piche to sara ye confirm hai ki sara ka sara hga hi answer me...to unpe jakr kyu check krna bhai
                
            for (int B = A; B >=1; B--) {
                if (((K -1)* (A - B))+A >= H) {
                    count+=(B-0);
                    break;
                }
            }
            }
        }
        
        cout << count << endl;
    }
    return 0;
}
