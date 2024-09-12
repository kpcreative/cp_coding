#include<bits/stdc++.h>
using namespace std;
// prefer this video for best understanding of it
//https://youtu.be/Zjs5A4gnveg?si=6MySEFhmScyD9_WP
vector<vector<int>> adj;
vector<vector<int>> ancestor;
vector<vector<int>> query;

int find_par(int node, int k) {
    // Binary lifting approach to find the k-th ancestor of node
    for (int i = 0; i < 32; i++) {
        if ((k >> i) & 1) {  // Check if the i-th bit is set in k
            node = ancestor[node][i];
            if (node == -1) {
                return -1;  // If no valid ancestor, return -1
            }
        }
    }
    return node;
}

void dfs(int node, int par) {
    ancestor[node][0] = par;  // The direct parent is the 0-th ancestor
    for (int j = 1; j < ancestor[0].size(); j++) {
        if (ancestor[node][j - 1] != -1) {
            ancestor[node][j] = ancestor[ancestor[node][j - 1]][j - 1];  // Set j-th ancestor using j-1th ancestor
        }
        if (ancestor[node][j] == -1) {
            break;  // The rest will also be -1
        }
    }
    // DFS call for child nodes
    for (auto nghbr : adj[node]) {
        if (nghbr == par) continue;
        dfs(nghbr, node);
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    if (n == 1) {
        // Handle the edge case of just 1 node
        while (q--) {
            int p, qq;
            cin >> p >> qq;
            cout << -1 << " ";  // Single node cannot have any ancestor
        }
        return 0;
    }

    // Resize adj after reading n
    adj.resize(n + 1);  // 1-based indexing

    int k = 2;  // Starting from node 2
    for (int i = 0; i < n - 1; i++) {
        int e; // the boss node
        cin >> e;
        adj[e].push_back(k);
        adj[k].push_back(e);
        k++;
    }

    query.resize(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        int p, qq;
        cin >> p >> qq;
        query[i][0] = p;
        query[i][1] = qq;
    }

    int col = ceil(log2(n)) + 1;
    int row = n + 1;  // We only need row = n for 1-based indexing (from 1 to n) thats why agr n loge sirf to dikt hga kyuki <n tak chlega and nth node access ho hi ny piga aise to
    ancestor.resize(row, vector<int>(col, -1));  // Initialize ancestor matrix with -1

    // Start DFS from root node (assuming node 1 is root)
    dfs(1, -1);  // Call DFS to set up ancestor table

    // Processing the queries
    for (int i = 0; i < q; i++) {
        int node = query[i][0];
        int level = query[i][1];
        int parr = find_par(node, level);
        cout << parr << " ";
    }

    return 0;
}
