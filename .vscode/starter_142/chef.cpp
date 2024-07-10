#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        if (x == 2) {
            cout << 0 << endl;
            continue;
        }
        if ((x & (x - 1)) == 0) {
            cout << 0 << endl;
        } else {
            /*
            REASON----
            i asked it with chat gpt 
            
            
            While it may seem that using sqrt(x) followed by a bit manipulation can sometimes yield the correct power of 2, this method is not reliable or straightforward. The correct approach involves directly finding the largest power of 2 less than  x

x through iteration. Here’s why:

Inaccuracy and Extra Steps:

Using sqrt(x) gives an approximate value which then needs to be adjusted. This adds unnecessary complexity and does not guarantee accuracy in all cases.
Simplicity and Efficiency:

Iteratively doubling a number until it exceeds 
𝑥
x is straightforward and ensures that you find the exact largest power of 2 less than or equal to 
𝑥
x without any adjustments or approximations.
Let's further clarify with the correct code example and an explanation:

Example Explanation:
If 
𝑥
=
14
x=14:

Using sqrt(x):

14
≈
3.74
14
​
 ≈3.74
Floor value of 3.74 is 3.
1<<3==8
1<<3=8 (correct in this instance, but not a reliable method for all values of 
𝑥
x).
Using iteration:

Start with 1.
Double it until it exceeds 14:
1, 2, 4, 8, 16 (stop here, as it exceeds 14).
The largest power of 2 less than 14 is 8.
            
            
            */
            
            
            
            
            
            
            
            
           /*long long no = sqrt(x);  // Using sqrt to find power of 2
            
            // Incorrect way to find largest power of 2
            long long left = 1<<no;
            long long n1 = x - left;
            if(n1<0)
            {
                //to tab tak ye left se 1 minus krte rho jab tak ye positive na aa jaye
                //i.e no se 1 minus kro  kyuki us power me hame -ve mila
                long long left=1;
                long long smaller=-1;
                while(left<x)
                {
                    smaller=left;
                    left*=2;
                }
                  long long n1 = x-left;
                  long long n11=n1/2;
                  cout<<n11*4<<endl;
                  continue;
              }
                 long long nn = n1 / 2;
            cout << nn * 4ll << endl;
            */
            long long justsmaller_power_of_2_less_than_x=1;
            long long prev=0;
            while(justsmaller_power_of_2_less_than_x<x)
            {
                prev=justsmaller_power_of_2_less_than_x;
                justsmaller_power_of_2_less_than_x*=2;
            }
            //now dekho ki diff kitna hai
            long long diff=x-prev;
            //now divide by 2 ki kitna age hai vo  ;
            long long no=diff/2;
            cout<<no*4<<endl;
        }
    }
    return 0;
}
