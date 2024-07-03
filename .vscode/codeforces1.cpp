#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        long long no=1+(n-1)*k;
        cout<<no<<endl;
    }
    return 0;
}