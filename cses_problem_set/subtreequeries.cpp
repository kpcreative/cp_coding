#include<bits/stdc++.h>
using namespace std;

vector<long long> seg;
vector<vector<long long>> adj;
vector<long long> value;
vector<long long> start;
vector<long long> endi;
vector<long long> arr; // This will be used to build the segment tree

void buildtree(long long ind, long long lo, long long hi) {
    if (lo == hi) {
        seg[ind] = arr[lo];
        return;
    }
    long long mid = lo + (hi - lo) / 2;
    buildtree(2 * ind + 1, lo, mid);
    buildtree(2 * ind + 2, mid + 1, hi);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
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
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

long long summ(long long strt, long long endd, long long ind, long long lo, long long hi) {
    long long mid = lo + (hi - lo) / 2;
    if (lo > endd || hi < strt) {
        return 0;
    }
    if (lo >= strt && hi <= endd) {
        return seg[ind];
    } else {
        return summ(strt, endd, 2 * ind + 1, lo, mid) + summ(strt, endd, 2 * ind + 2, mid + 1, hi);
    }
}

long long t = 0; // Globally declared

void dfs(long long node, long long par) {
    start[node] = t;
    arr[t] = value[node];
    t++;
  
    // DFS call for child nodes
    for (auto nghbr : adj[node]) {
        if (nghbr == par) continue;
        dfs(nghbr, node);
    }
    endi[node] = t;
    arr[t] = value[node];
    t++;
}

int main() {
    long long n, q;
    cin >> n >> q;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    adj.resize(n + 1);  // 1-based indexing
    value.resize(n + 1);
    for (long long i = 1; i < value.size(); i++) {
        long long e;
        cin >> e;
        value[i] = e;
    }

    for (long long i = 0; i < n - 1; i++) {
        long long e; // The boss node
        long long v;
        cin >> e >> v;
        adj[e].push_back(v);
        adj[v].push_back(e);
    }

    start.resize(n + 1);
    endi.resize(n + 1);
    arr.resize(2 * n); // Each node's value will appear twice

    dfs(1, -1);  // Call DFS to set up ancestor table

    seg.resize(8 * n);//as ham arr pe lga rhe hai n jo ki alreadyy 2*n hai and hame 4*n i.e 4*2*n
    buildtree(0, 0, arr.size() - 1);

    // Now let's run the query
    for (long long i = 0; i < q; i++) {
        long long e;
        cin >> e;
        if (e == 1) {
            // To further input two more values
            long long a, b;
            cin >> a >> b;
            // 'a' is the node, find its start and end
            long long ss = start[a];
            long long ee = endi[a];
            // Update both start and end positions
            updatess(ss, b, 0, 0, arr.size() - 1);
            updatess(ee, b, 0, 0, arr.size() - 1);
        } else {
            // Print sum
            long long c;
            cin >> c;
            long long ss = start[c];
            long long ee = endi[c];
            // Get the sum for this range
            cout << summ(ss, ee, 0, 0, arr.size() - 1) / 2 << " ";
            continue;
        }
    }

    return 0;
}
