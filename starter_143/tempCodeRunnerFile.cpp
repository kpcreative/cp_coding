#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        string s, t;
        cin >> s >> t;

        long long count0_0 = 0;
        long long count1_1 = 0;
        long long count0_2 = 0;
        long long count1_2 = 0;

        for (long long i = 0; i < n; i++) {
            if (s[i] == '1') {
                count1_1++;
            }
            if (t[i] == '1') {
                count1_2++;
            }
            if (s[i] == '0') {
                count0_0++;
            }
            if (t[i] == '0') {
                count0_2++;
            }
        }

        if ((count1_1 != count1_2) || (count0_0 != count0_2)) {
            cout << "no" << endl;
            continue;
        }
       //this was my code for handling string length >3 
        //but during contest i forgot that string of length 2 can be of 4 ways
        //"00". "11".  "10".  "01" 
        //and i only handled the case for "10" and "01"
        //lekin bhai jab string s and string t jab  dono hi same ho gye i. e. "00" or "11" to bhai tu kitna v swap kr le ye same hi rhega  isliye return yes    
        
else if((s=="00" && t=="00")||(s=="11" && t=="11"))
{
    cout<<"yes"<<endl;
    continue;
}

//this above edge case i was missing bhai yar

//aur baki me if diff
        else if (n == 2) {
            //ye agr ki s="10" and t="10"
            //to agr ek swap kro to unequal ho jiga
            //agr observe kro to even number of times me ye same rhega and odd wale me diffrent
            
            //isliye %2==1 aya mean odd hai isliye return no
            if (s[0] == t[0] && s[1] == t[1]) {
                if(k%2==0){
                cout << "yes" << endl;
                continue;
                }
                else
                {
                    cout<<"no"<<endl;
                    continue;
                }
            } else {
                
                //just opposite of above one
                if(k%2==0){
                cout << "no" << endl;
                continue;
                }
                else
                {
                    cout<<"yes"<<endl;
                    continue;
                }
            }
            continue;
        }
          //this was my code for handling string length >3 
        //but during contest i forgot that string of length 2 can be of 4 ways
        //"00". "11".  "10".  "01" 
        //and i only handled the case for "10" and "01"
        //lekin bhai jab string s and string t jab  dono hi same ho gye i. e. "00" or "11" to bhai tu kitna v swap kr le ye same hi rhega  isliye return yes 
      
        else {
            long long diff = 0;
          
            for (long long i = 0; i < n; i++) {
              if(s[i]!=t[i])
              {
                  diff++;
              }
            }
            long long sum = diff;

            // Perform integer division and check if we need to add 1
            long long result = sum / 2; //kitna pair bnaya
            //kyuki swap to pair me hi hoga na 
            
            //let sum=3 tha to sum/2 kuch point me ata to ham na odd k liye ek extra kr diye
            //kyuki diff i.e kuch jada hga tbhi na exact pair me nhi hai ji
            if (sum % 2 != 0) { // If sum is odd
                result += 1;
            }
           //agr ye swap ka pair kam hai is k se to obvious hai hamesha yes hga//kyuki vo pair swap hokr equal ho jiga and then ham usi me se swap krte rhnge till k times
            if (result <= k) {
               
                   cout<<"yes"<<endl;
                   continue;
        
                
            } else {
                //nhi to print no
                //kyuki jab swap hone wala pair hi >k hai to kha se utna swap hokr equal ho piga...ye to impossible hai na
                cout << "no" << endl;
                continue;
            }
        }
    }
}