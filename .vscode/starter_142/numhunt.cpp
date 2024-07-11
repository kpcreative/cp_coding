#include <bits/stdc++.h>
using namespace std;
//dekh logic is clear
//hame Y aisa lena hga jo X se bada ho 
//taki kmse kam ye to surity rhega na ki bada number me koi to aisa hga jiska sara factor>=x hga pr less nhi hga 
//dekh agr Y < X le liye tab to dikt hai kyuki Y ka factor for sure <x hga hi 
//isliye Y>X hi lena for better..avi v nhi hai koi surity ki factor<x aye

//now ab greater to lena hai pr prime v nhi le skte and perfect square v nhi le skte
//to kisi same*same number ka value v nhi le skte as vo same number ka perfect square ho jiga

//and ek bat notice krio---ki aur koi number le lo except prime--unka factor to pkka se pkka hga hi
//let x=4 and y=9 choose kiye ye to prime nhi hai and iska factor obvious hai ki 1*3*3 jo ki x se less hai
//dekh agr surity lena hai na ki y ka factor <x na rhe to hame prime number se hi kuch krna pdega just greater than X
//kyuki wahi ek aisa case hai jisme Y ka factor=1 and koi ek number hga jo just greater than x hga 
//to ham kya krnge ki let x=anything hai
//agr x prime hai to usko ek le lo * just another prime khojo  and unka product le lo
//to na to vo Y JO AYEGA VO PRIME HGA ...NA HI  PERFECT SQARE HGA...AUR NA HI FACTOR<X HGA



//the reson for not using this sieve approach is that
/*
Sieve Initialization: Initializing the sieve with a size of 10000000000 is infeasible due to memory constraints. We need to use a much smaller and more realistic size. Generally, a sieve up to 1000000 or slightly more should suffice for most competitive programming problems.
*/


  /* vector<long long>v(10000000000,1);
void prime()
{
    //by sieve method lets create all the prime
 
    v[0]=0;
    v[1]=0;//they are not prime
    for(long long i=2;i<v.size();i++)
    {
        if(v[i]==1)
        {
            //mtlb prime hai and iske muliple ko false kr do
            for(int j=2*i;j<v.size();j+=i)
            {
                v[j]=0;
            }
        }
    }
    
}
bool isprime(long long x)
{
    if(v[x]==1) return true;
    //wrna false
    return false;
}
*/

//IT WILL BE BETTER TO USE THIS BRUTE FORCE APPROACH TO FIND prime
//KYUKI HAME BAS 2 PRIME KHIJNA HAI JUST greater
//AND MAINE YOUTUBE ME ARYAN NAM HAI VO BATYE THE KI 2 PRIME KE BEECH JADA GAP NHI HTA
//ISLIYE THIS BRUTE FORCE APPROACH WILL WORK


bool isprime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}
int main() {
	// your code goes here
int t;
cin>>t;
while(t--)
{
    long long x;
    cin>>x;
    //phle to check kro ki x prime hai kya
    if(isprime(x))
    {
        //now see x+1 ke bad next prime kon sa hai
        
        long long num=x+1;
        for(long long i=num;i<10000000000;i++)
        {
            if(isprime(i))
            {
                num=i;
                break;
            }
        }
        cout<<num*x<<endl;
        continue;
    }
    else
    {
        //agr nhi hai prime to lets check ki is x se bada me 2 prime kon kon sa hai
        long long num=x+1;
        long long count=0;
        long long ans=1;
        for(long long i=num;i<10000000000;i++)
        {
            if(isprime(i))
            {
                ans*=i;
                count++;
                if(count==2)//bhai hame y as small as possible chaiye NA
                {
                    //to aisa Y lnge jo just is x se bada ho and that will come by just 2 grater prime number than  x and unka product se
                    
                    //mean 2 prime mil gya
                    break;
                }
            }
        }
        cout<<ans<<endl;
        continue;
    }
}
}
