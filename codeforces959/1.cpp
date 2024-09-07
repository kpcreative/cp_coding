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
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    if(n==1 &&m==1)
    {
        cout<<-1<<endl;
        continue;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m-1;j++)
        {
          swap(v[i][j],v[i][j+1]);
        }
    }
     for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
          swap(v[i][j],v[i+1][j]);
        }
    }
    for(auto it:v)
    {
        for(auto it1:it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }

}
}