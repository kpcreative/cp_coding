#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, q;
    cin >> n >> q;
    vector<long long> v(n+1);
    for(long long i = 1; i < v.size(); i++)
    {
        long long e;
        cin >> e;
        v[i] = e;
    }
    for(long long i = 2; i < v.size(); i++)
    {
        v[i] += v[i-1];
    }
    for(long long i = 0; i < q; i++)
    {
        long long e, f;
        cin >> e >> f;
        if(e == 1)
        {
            cout << v[f] << " ";
        }
        else
        {
            cout << v[f] - v[e-1] << " ";
        }
    }
}
