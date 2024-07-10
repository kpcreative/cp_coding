#include <bits/stdc++.h>
using namespace std;

int main() {
/*
Simple take the total cases possible and compare each one of them. we have 2 possiblity of A and 1 of B. so lets do and check the conditions;
*/
	int t;
	cin>>t;
	while(t--)
	{
	    int x,y;
	    cin>>x>>y;
	    /*
	    For a penalty shootout to end in a draw after 5 turns each:

Team A can score a maximum of 2 more goals (since they have 2 turns left).
Team B has 1 turn left to score a goal.
Thus, to check if it's possible for the scores to be equal after 5 turns:

𝑋
X (team A's goals) + 2 (maximum remaining goals they can score) must be at least 
𝑌
Y (team B's goals).
Similarly, 
𝑌
Y + 1 (maximum remaining goals team B can score) must be at least 
𝑋
X.
To put this in terms of conditions:

𝑋
+
2
≥
𝑌
X+2≥Y
𝑌
+
1
≥
𝑋
Y+1≥X


code is hereee for it---

#include <bits/stdc++.h>
#define lil long long int
// #define sort(xyz) sort(xyz.begin(),xyz.end())
const int MOD = 1e9 + 7;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int test;cin>>test;
	while(test--)
	{
	    int a,b;
	    cin>>a>>b;
	    int p=a+1;
	    int q=a+2;
	    int r=b+1;
	    if(a==b||a==r||p==b||p==r||q==b||q==r) cout<<"YES\n";
	    else cout<<"NO\n";
	}

}
	    */
	       if((x + 2 >= y) && (y + 1 >= x))
	            {
	                cout<<"yes"<<endl;
	            }
	            else
	            {
	                cout<<"no"<<endl;
	            }
	}

}
