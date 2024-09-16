/*


//this is the link to understand---   https://hackmd.io/@cs-mshah/H1P3CM-Mt#cses---counting-paths



cses - counting paths
Comment
Here is the problem statement: link
You are given a tree consisting of n nodes, and m paths in the tree.
Your task is to calculate for each node the number of paths containing that node.

To solve this, we will need a few techniques. They are discussed below:

Difference array technique
Lets say we are given an array of integers and we have queries of the form : l r x which means add x to all elements of array with indices in range [l,r]. We have several such queries, and after all queries, we wish to find the final array.

Nieve approach:
Perform the addition to all elements in the given range for all queries. Overall complexity: 
𝑂
(
𝑛
𝑞
)

Faster approach:
Let us initially create an array diff of zeroes of size n+2. We assume that l, r are 1-indexed. Now for every query, we do the following: add x to diff[l] and subtract x from diff[r+1] (diff is 0-indexed). After all the queries are over, we take the prefix sum over diff, and what we get is finally the amout that needs to be added to the original array a to obtain the final array after all queries. Let us take an example:

a = [3 5 1 1 6]
queries:
[1 2 1]
[3 5 2]
[5 5 5]

diff = [0 0 0 0 0 0 0]
query 1:[0 1 0 -1 0 0 0]
query 2:[0 1 0 1 0 0 -2]
query 3:[0 1 0 1 0 5 -7]
prefix sum: [0 1 1 2 2 7 0]
final a: [4 6 3 3 13]

Let us see why this works:
Our aim was to reduce the costs per query, so we typically wanted the per query cost to be 
𝑂
(
1
)
. And after this, we want to process the computation. If we think about a single query, what all is required for updating a range? All we need is to do is add to l, and then this same no. to all nos. from l+1 to r. We know that this is same as doing a prefix sum on an array with all zeroes and a[l] = x. Lets observe:

[0 0 0 0 0 0 0] . query: [1 5 2]
[0 2 2 2 2 2 2]. Now if we just add 2 to l and do a prefix sum, then the (r+1)th value also gets 2. so to cancel the effect of the prefix sum, we subtract 2 form r+1

Now we know that for one query, doing 2 updates and a prefix sum gives us the required diff array. For multiple updates, we can do the 2 updates for all queries and then take the prefix sum at the very end. This works as addition is commutative and associative.
Overall complexity: 
𝑂
(
𝑛
+
𝑞
)

LCA : lowest common ancestor
The best source to read would be : cp-algorithms

The main solution
If we had an array, we would have solved the problem. But what we have is a tree. so things are a little trickier. We somehow want to use the same ideas as that of an array and solve the problem. Key observations:

evey simple path u to v can be broken as u to l and l to v, where l is the lca of u v.
      p
      |  
      l
     / \
    /   k
   u     \
          v
We want to add 1 to the nos. from u to v. So we want to add 1 to the nos. in path u...l and v...k.
In an array, we take prefix sum in the direction of l to r.
So here we have two choices for the direction: l to u and k to v or u to l and v to k.
If we take the latter, then the sum needs to be computed for inner nodes first(starting at leaves). Well, this is easy for us as we have dfs!!
So, all we need to do is a[u]+=1, a[p]-=1, a[v]+=1, a[l]-=1.
Now, as there will be prefix sums coming from the children of a node, this is a classic problem of tree dp.
dp[u] = prefix sum till u. dp[u] = (sum over all child v :(dp[v])) + a[u]. This can easily be computed using a dfs.
*/

#include<bits/stdc++.h>
using namespace std;
// prefer this video for best understanding of it

//https://youtu.be/Zjs5A4gnveg?si=6MySEFhmScyD9_WP

//note----- pta nhi kyu segmentation fault de rhi hai aur yhi chij accept v ho gyi

//isme kuch nhi bas LCA find krne ana chhaiye by binary lifting
//AGR VO AA GYA THEN EASILY WITH THE HELP OF LEVEL OF NODES YOU CAN FIND THE DISTANCE BETWEEN 2 NODES
vector<vector<int>> adj;
vector<vector<int>> ancestor;
vector<vector<int>> query;
vector<int>lvl;//lvl too use pdega hi lca me na ji
vector<int>prefix;
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


int dfs2(int node,int par)
{
    int sum=prefix[node]; 
     int total=0;
    for(auto nghbr:adj[node])
    {
       if(nghbr==par) continue;
        total+=dfs2(nghbr,node);
        
    }
    return prefix[node]=sum+total;
}
 
int main() {
    int n, q;
    cin >> n >> q;
 
    if (n == 1) {
       cout<<0<<endl;
        return 0;
    }
 
    // Resize adj after reading n
    adj.resize(n + 1);  // 1-based indexing
 
    for (int i = 0; i < n - 1; i++) {
        int e; // the boss node
        int v;

        cin >> e;
        cin>>v;
        adj[e].push_back(v);
        adj[v].push_back(e);
       
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
   prefix.resize(n+1,0);
    // Start DFS from root node (assuming node 1 is root)
    dfs(1, -1,0);  // Call DFS to set up ancestor table
 // Processing the queries
  for (int i = 0; i < q; i++) {
        int node1 = query[i][0];
        int node2 = query[i][1];
       prefix[node1]+=1;
       prefix[node2]+=1;
      
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
        
        if(node1==node2)
        {
           //ye lca hai
           prefix[node1]-=1;
           if(find_par(node1,1)!=-1)
           {
            prefix[find_par(node1,1)]-=1;
           }
            
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
             prefix[lcaa]-=1;
         if(find_par(lcaa,1)!=-1)
           {
            prefix[find_par(lcaa,1)]-=1;
           }
            
        }
      
      
    }

  int cc=  dfs2(1,-1);
 for(int i=1;i<prefix.size();i++)
 {
    cout<<prefix[i]<<" ";
 }
 
    return 0;
}
