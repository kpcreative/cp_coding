#include <bits/stdc++.h>
using namespace std;
/*
if the frog slips b units it effectively travels (a-b) units per seconds upwards.But in the last second it doesnt slip as it has escaped the well.by this logic (a-b)*(k-1)+a is the distance it can travel in k seconds and this distance must be greater than equal to h.

hence for a given possible a, if (a-b)*(k-1)+a>=h holds true for a value of b,it also holds true for b-1.hence binary search on b to find the maximum value of b for each possible value of a.


*/
long long upper_limit(long long lo,long long hi,long long sec,long long a,long long h)
{
    //calculate the mid and mid ka jo value hga ham use b assume kr rhe hai isliye b likhe hai vsariable me so dont be confuse so much
    long long ans=0;
    while(lo<=hi){
    long long b=lo+(hi-lo)/2;
    
    if((a-b)*(sec-1)+a>=h)
    {
        ans=b;
        lo=b+1;
    }
    else
    {
        hi=b-1;
    }
    }
    return ans;
}
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
                //kyuki b to sorted pe hi lg rha hai n i.e let a=10 to b= 10 to 1 ya b=1 to 10 tak sorted hi hai na
                //isme bas upper limit dekhna hai ki b kaha tk ja skta hai jaha pe k-1*(a-b)+a>==h ho jaye
                //let b=5 pe ye last satisy kiya it mean 1 to 5 tak obvious krega hi krega to total 5 hua isliye we return 5
                //5 ke bad wala thdi satisy krega as vo phir k-1*(a-b)+a>=h satisfy kr hi ny piga na
                //to kyu na binary search se ham iska upper limit nikal le ki kon se b value at last hai jaha pe ye ((K -1)* (A - B))+A >= H true ho rha hai
                //jaha pe ho rha hga vo return kr dena
                //and kyuki usse piche to sara ye confirm hai ki sara ka sara hga hi answer me...to unpe jakr kyu check krna bhai
                
            long long b=upper_limit(1,N,K,A,H);
            count+=b;
            }
            }
            cout << count << endl;
        }
        
        return 0;
    }
    

