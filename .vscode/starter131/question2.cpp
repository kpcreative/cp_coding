#include <bits/stdc++.h>
using namespace std;
//dixe deception
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    unordered_map<long long int,long long int>mp;
	    //oppposite to up and down map me dal do
	    mp[1]=6;
	    mp[6]=1;
	    mp[2]=5;
	    mp[5]=2;
	    mp[3]=4;
	    mp[4]=3;
	    int n,k;
	    cin>>n>>k;
	    vector<long long>v(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>v[i];
	    }
	    //now sort it 
	    sort(v.begin(),v.end());
	    int i=0;
	    long long sum=0;
	   long long count=0;
	   
	    while(i<n)
	    {
	        if(count<k){
	        long long maxi=-1e19;
	        maxi=max(v[i],mp[v[i]]);
	        sum+=maxi;
	        }
	        else
	        {
	            sum+=v[i];
	        }
	        i++;
	        count++;
	    }
	    cout<<sum<<endl;
	}

}
