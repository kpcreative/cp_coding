#include<bits/stdc++.h>
using namespace std;

vector<long long> seg;
vector<long long> arr; // This will be used to build the segment tree

void buildtree(long long ind, long long lo, long long hi) {
    if (lo == hi) {
        seg[ind] = arr[lo];
        return;
    }
    long long mid = lo + (hi - lo) / 2;
    buildtree(2 * ind + 1, lo, mid);
    buildtree(2 * ind + 2, mid + 1, hi);
    seg[ind] = min(seg[2 * ind + 1] , seg[2 * ind + 2]);
}

void updatess(long long idx, long long val, long long ind, long long lo, long long hi) {
    if (lo == hi) {
        seg[ind] = val;
        return;
    }
    long long mid = lo + (hi - lo) / 2;
    if (idx <= mid) {
        updatess(idx, val, 2 * ind + 1, lo, mid);
    } else {
        updatess(idx, val, 2 * ind + 2, mid + 1, hi);
    }
    seg[ind] = min(seg[2 * ind + 1] ,seg[2 * ind + 2]);
}

long long mini(long long strt, long long endd, long long ind, long long lo, long long hi) {
    long long mid = lo + (hi - lo) / 2;
    if (lo > endd || hi < strt) {
        return INT_MAX;
    }
    if (lo >= strt && hi <= endd) {
        return seg[ind];
    } else {
        return min(mini(strt, endd, 2 * ind + 1, lo, mid) , mini(strt, endd, 2 * ind + 2, mid + 1, hi));
    }
}



int main() {
    long long n, q;
    cin >> n >> q;

   arr.resize(n+1);

   for(int i=1;i<arr.size();i++)
   {
        int e;
        cin>>e;
        arr[i]=e;

   }

    

    

    seg.resize(4 * n+5);//as ham arr pe lga rhe hai n jo ki alreadyy 2*n hai and hame 4*n i.e 4*2*n
    buildtree(0, 0, arr.size() - 1);

   for(int i=0;i<q;i++)
   {
    int e,f;
    cin>>e>>f;
    cout<<mini(e,f,0,0,arr.size()-1)<<" ";
   }

    return 0;
}
