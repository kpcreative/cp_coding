#include<bits/stdc++.h>
using namespace std;

vector<long long> colors;
vector<vector<long long>> adj;
vector<long long> ans;

// DFS function that returns a set of unique colors encountered
unordered_set<long long> dfs(long long node, long long par) {
    unordered_set<long long> st;
    st.insert(colors[node]);  // Insert the color of the current node

    // Iterate over all neighbors of the current node
    for (auto nghbr : adj[node]) {
        if (nghbr == par) continue;  // Skip the parent node to avoid backtracking

        // Perform DFS on the neighbor and get its color set
        unordered_set<long long> stt = dfs(nghbr, node);

        // Merge smaller set into the larger one to reduce insertion cost
        if (stt.size() > st.size()) {
            swap(st, stt);  // Swap so that 'st' is always the larger set
        }

        // Insert elements of the smaller set into the larger set
        st.insert(stt.begin(), stt.end());
    }

    ans[node] = st.size();  // Store the size of the color set in ans for the current node
    return st;  // Return the color set for the current node
}

int main() {
    long long n;
    cin >> n;
    colors.resize(n + 1);  // Resize colors for 1-based indexing
    adj.resize(n + 1);     // Resize adjacency list for 1-based indexing

    // Input for colors
    for (long long i = 1; i <= n; i++) {
        long long e;
        cin >> e;
        colors[i] = e;
    }

    // Input for edges
    for (long long i = 0; i < n - 1; i++) {
        long long e, v;
        cin >> e >> v;
        adj[e].push_back(v);
        adj[v].push_back(e);
    }

    ans.resize(n + 1);  // Resize ans for 1-based indexing

    // Start DFS from node 1 with parent as -1
    unordered_set<long long> stt = dfs(1, -1);

    // Output the result stored in ans
    for (long long i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}
