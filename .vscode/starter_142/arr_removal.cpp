#include <bits/stdc++.h>
using namespace std;
/*

or--ye jo hai n increasing hai //to hamne array ko sort kr liya

//sort krne pe agr or lenge to bhai obvious increase hi hga n ji

//dekh 2^k-1==koi odd hi hta hai

//mtlb like 2^2-1=3 jo ki 3 i.e 3=11 in bit

//to prefix 'or' le lo sbka

//now start iterating from 0th index

//agr kisi ka 'or' ka value 2^k-1 hai to itna tak ko rkho and remaining ko hta do

//to ye 2^k-1 hai ki nhi ye pta. chlega agr let 2^k-1 me hamesha all bit will be=='1111111...'' all will be 1 only

//isliye to check ki sara bit==1 hai ki nhi bas n+1 wala number se and krnge to vo hmesha 0 hi dega

//agr aisa hai it mean ye 2^k-1 ke form me hai

//and aise krte krte till last tak check kro kya pta bad me v 'or'==2^k-1 ke form me mile and us tym hame aur kam elemnt remove krne pdnge

//isliye we will be checking all condition

remove_ = min(remove_, n - 1 - i); } this line mean ki is Ith pe hame 'or'==2^k-1 mila hai to usko store kro ki minimum jo bacha hai utna remove kr skte hai taki hmara array avi v 'or'==2^k-1 hi de
*/
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long remove_ = LLONG_MAX;
       
        for (long long i = 1; i < a.size(); i++) {
            a[i] = a[i] | a[i - 1];
        }
        
        for (long long i = 0; i < a.size(); i++) {
            long long no = a[i];
            if ((no & (no + 1)) == 0) {
                remove_ = min(remove_, n - 1 - i);
            }
        }
        if (remove_ == LLONG_MAX) {
            cout << n << endl;
            continue;
        }
        cout << remove_ << endl;
    }
}
