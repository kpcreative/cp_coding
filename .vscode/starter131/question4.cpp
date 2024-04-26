#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
//encrypt values
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        long long  s = v[0];
        for (int i = 1; i < n; i++) {
           
          if(s*v[i]>=s+v[i])
          {
              s*=v[i];
              s%=1000000007;
          }
          else
          {
             s+=v[i];
             s%=1000000007;
          }
        }
        cout << s << endl;
    }
    return 0;
}
