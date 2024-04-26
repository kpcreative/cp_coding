#include <bits/stdc++.h>
using namespace std;
//gotta catch them all
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x,y;
	    cin>>n>>x>>y;
	    long long ans=0;
	  
	    for(int i=0;i<n;i++)
	    {
	        int e;
	        cin>>e;
	        long long no=e*x;
	        if(no<=y)
	        {
	            ans+=no;
	        }
	        else
	        {
	            ans+=y;
	        }
	    }
	    cout<<ans<<endl;
	}

}
