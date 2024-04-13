#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
int t;
cin>>t;
while(t--)
{
    int count6=0;

    int count4=0;
    long long int count=0;
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==2) count+=count6;//it mean ki isse phle kitna 6 aya hai vo dekho and wahi add kro
        //like agr [2,4,6] hta to phle 2 aya par 6 nhi aya tha isliye count+=0 hi rehta as count6=0 rehta
        if(v[i]==4) count+=count4;
        
        if(v[i]==6)
        {
            count6++;
        }
        if(v[i]==4)
        {
            count4++;
        }
    }
    cout<<count<<endl;
}
}