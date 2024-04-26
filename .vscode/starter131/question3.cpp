#include <bits/stdc++.h>
using namespace std;
//k closeness
int main() {
	// your code goes here
	int t ;
	cin>>t;
	
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    vector<long long>v(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>v[i];
	        v[i]=v[i]%k;//we want ki sab na k se chota hi rhe stored....as khud socho na ki agr ham isko kitna v k operation bdhynge ye k se mod lene pe wahi waps se 0 to k-1 ke bich me hi aa jiga
	    }
	    //now sort kro
	    sort(v.begin(),v.end());
	    long long int ans=v[n-1]-v[0];//storing the first min and max ka diff
	    for(int i=0;i<n-1;i++)
	    {
	        ans=min(ans,v[i]+k-v[i+1]);
	    }
	    cout<<ans<<endl;
	}

}
