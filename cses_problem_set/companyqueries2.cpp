#include<bits/stdc++.h>
using namespace std;
// prefer this video for best understanding of it
//https://youtu.be/Zjs5A4gnveg?si=6MySEFhmScyD9_WP
vector<vector<int>> adj;
vector<vector<int>> ancestor;
vector<vector<int>> query;
vector<int>lvl;
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
 
void dfs(int node, int par,int level) {
    lvl[node]=level;
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
        dfs(nghbr, node,level+1);
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
 
   lvl.resize(n+1);
    // Start DFS from root node (assuming node 1 is root)
    dfs(1, -1,0);  // Call DFS to set up ancestor table
 // Processing the queries
   for (int i = 0; i < q; i++) {
        int node1 = query[i][0];
        int node2 = query[i][1];
       
        int lvl_n1=lvl[node1];//node1 ka level btaw
        int lvl_n2=lvl[node2];//node 2 ka level btaw
        //if lvl equal hai dono ke to thik hai..wrna jump kraw 
       if(lvl_n1!=lvl_n2)
        {
            //to jump kraw inke diff jo hai utne upr;
            //phle dekhi ki kon se node ka lvel jada hai
            int diff=0;
            if(lvl_n1>lvl_n2)
            {
              diff=lvl_n1-lvl_n2;
              node1=find_par(node1,diff);
            }
            else{
                diff=abs(lvl_n1-lvl_n2);
                node2=find_par(node2,diff);
            }
        }
        
        //if after bringing to same level if the both nodes are same mean they are only lowest commmon ancestor
        if(node1==node2)
        {
            cout<<node1<<" ";
            
        }
        else{
            //max utna upr jaw jitna upr ja skte ho ....
            //to copy me btaye na ki max level 19 tak hi ho skta hai...
            
            for(int level=ancestor[0].size();level>=0;level--)
            {
               //node1 and node2 se itne level upr jaw bar bar,,,tab tak till whole loop 
              int u=ancestor[node1][level];  //function call krne me TLE DE RHA HAI TO ISSE ACHA HAI KI JO ANCESTOR BNAYE HO USME V TO PARENTS HI HAI NA BHAII TO USEE HI CALL KR LLO NA ISSE ACHA
              int v=ancestor[node2][level];
               
               if( u!=v)
               {
                 node1=u;
                 node2=v;
               }
            }
            
            //phir yha se just 1 level upr jo hga na vo lca hi hga
            int lcaa=find_par(node1,1);
            cout<<lcaa<<" ";
        }
      
    }
 
    return 0;
}
