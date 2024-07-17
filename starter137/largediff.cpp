#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    int k;
	    cin>>n>>k;
	    vector<long long>v(n);
	    for(int i=0;i<n;i++)
	    {
	        long long e;
	        cin>>e;
	        v[i]=e;
	    }
	    //phle to sum nikal lo original
	   long long sum=0;
	   for(int i=0;i<n-1;i++)
	   {
	    sum+=abs(v[i]-v[i+1]);
	   }
	   long long maxi=-1e10;
	     long long ans=-1e10;
	   //ab ek bar v[i]=1 put kro and ek bar v[i]=k;
	   for(int i=0;i<n;i++)
	   {
	       if(i==0)
	       {
	           long long ne_sum=sum-abs(v[i]-v[i+1]);
	           ne_sum=ne_sum+abs(1-v[i+1]);
	           
	           maxi=max(ne_sum,sum);
	          ans=max(maxi,ans);
	           //now put ==k 
	           ne_sum=sum-abs(v[i]-v[i+1]);
	             ne_sum=ne_sum+abs(k-v[i+1]);
	               maxi=max(ne_sum,sum);
	               ans=max(maxi,ans);
	       }
	       else if(i==n-1)
	       {
	            long long ne_sum=sum-abs(v[i]-v[i-1]); 
	              ne_sum=ne_sum+abs(1-v[i-1]);
	               maxi=max(ne_sum,sum);
	                    ans=max(maxi,ans);
	               
	                 ne_sum=sum-abs(v[i]-v[i-1]);
	             ne_sum=ne_sum+abs(k-v[i-1]);
	               maxi=max(ne_sum,sum);
	                ans=max(maxi,ans);
	       }
	       else
	       {
	             long long ne_sum=sum-abs(v[i]-v[i-1])-abs(v[i]-v[i+1]);
	               ne_sum=ne_sum+abs(1-v[i-1])+abs(1-v[i+1]);
	                maxi=max(ne_sum,sum);
	                  ans=max(maxi,ans);
	                
	                ne_sum=sum-abs(v[i]-v[i-1])-abs(v[i]-v[i+1]);
	                 ne_sum=ne_sum+abs(k-v[i-1])+abs(k-v[i+1]);
	                     maxi=max(ne_sum,sum);
	                       ans=max(maxi,ans);
	       }
	   }
	   cout<<ans<<endl;
	}

}
