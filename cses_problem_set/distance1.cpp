//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
/*
How to Optimize with Two DFS Calls:
First DFS: Start from an arbitrary node (e.g., node 1) to find the farthest node A.
Second DFS: Perform a DFS from A to find the farthest node B (which gives the tree's diameter) and record distances from A.
Third DFS: Perform a DFS from B to record distances from B.
For each node, the longest distance will be the maximum of its distances from A and B.
*/
class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
// User function Template for C++
 vector<vector<int>> adj;

vector<vector<int>>depth;
vector<int>up;
vector<long long>maxdist;
int maxi=INT_MIN;
 long long dfs(long long node, long long parent) {
   int total=0;
    int first=0;
    int second=0;
     for(auto nghbr:adj[node])
     {
        total=0;

        if(nghbr!=parent)
        {
          total=dfs(nghbr,node);
  
        // If current element is greater than first 
        if (total >= first) { 
            second = first; 
            first = total; 
        } 
        // If current element is in between first and second 
        else if (total> second && total < first) { 
            second = total; 
        } 
     
        }
     }
     
     depth[node][0]=1+first;
     depth[node][1]=1+second;
     //maxi=max(maxi,1+first+second);
     return 1+max(first,second);
    }



//NOTE---YE HAM BASICALLY VERTEX KE FORM ME KR RHE HAI SO AT LAST FOR EDGE HAME -1 KRNA HI HOGA

//is function call me ham maxdist calculate krte chlege
//maxdist---ya to iscurrent node ka max uske depth me hi pda hua hoga......ya phir usske parent wale me..mtlb parent wale me jo v max farthesthoga jo is node se bas pass nhi hona chaiye vo up wale vector me store krte chlo
//up wale vector me ham basically us node pe like 3 hai 3 ka prent 1 hai...to up[3] ye btaiga ki uske parent i.e 1 ka max dist kya hai and vo ye 3 se pass nhi hona chhaiye

    
    void dfs2(long long node,long long parent)
    {
         int first_depth_of_node=depth[node][0];
         int second_depth_of_node=depth[node][1];
         int up_of_node=up[node];//obvious parent se hi na ayega..par ye chij calculate krke hmne waha up[node] me hi store kiya hai
         //to max dist dekh lo ya to iske depth se aa rha hga
         int dist=max(first_depth_of_node,second_depth_of_node);
         //ya to uppe me hoga max...par upper me na max wala lena jo is node se pass na lr rha ho...mean upper node me max i.e farthest distance which is not going from this node
         //to up wale ka depth1,depth2,up me se jo 1st max 2nd max hga vo nikal lo
         //agr sbse max wala is node ke through ja rha to use mat lo i.e scnd max ko lo wrna max ko k=hi lekr up me set kr lo
       
        maxdist[node]=max(first_depth_of_node,max(second_depth_of_node,up[node]));
//cout<<maxdist[node]<<" ";
         
 for(auto nghbr:adj[node])
      {
        if(nghbr==parent) continue;
        //ya to uppe me hoga max...par upper me na max wala lena jo is node se pass na lr rha ho...mean upper node me max i.e farthest distance which is not going from this node
         //to up wale ka depth1,depth2,up me se jo 1st max 2nd max hga vo nikal lo
         //agr sbse max wala is node ke through ja rha to use mat lo i.e scnd max ko lo wrna max ko k=hi lekr up me set kr lo
         int depth_par=depth[node][0];  //is neighbor ke liye parent to node hi to hai na
         int depth2_par=depth[node][1];
         int up_of_node=up[node];//obvious parent se hi na ayega...is neighbour ka up uske parent i.e node se hi na yega
         //ab 1st max and second max dekho
         int first_max = max(depth_par, max(depth2_par, up_of_node));
          int second_max;

    // Find the second maximum
       if (first_max == depth_par) {
        second_max = max(depth2_par, up_of_node);
        } else if (first_max == depth2_par) {
        second_max = max(depth_par, up_of_node);
        } else {
          second_max = max(depth_par, depth2_par);
        }
       //to dekho ki jo firstmax hai vo kahi is node se hokr to nhi ja rha hai na
       if(1+depth[nghbr][0]==first_max)//first_depth_of_node max node hi to hai...kyuki koi v max hoga bhai vo is node ke max depth se hi pass hoga to kyu bina mtlb ka scnd wale se check kre ham
        {
         //to second max wala use kro
            up[nghbr]=1+second_max;
        }
     else if(1+depth[nghbr][0]!=first_max)  //is depth of nghbr me nhi hona chaiye uska max....agr hai to bdl lo
       {
         up[nghbr]=1+first_max;
    }
      dfs2(nghbr,node);


      }
    }
class Solution
{
public:
    vector<long long> helper(int n,vector<vector<int>> &edges)
    {
        //base case is that when n is ==1 and n==2 and n==3 then answer will be 1 pair only alwys
       

           adj.resize(n+1, vector<int>());
   
depth.resize(n+1,vector<int>(2));
up.resize(n+1,0);
maxdist.resize(n+1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
      
    
       long long ss=dfs(1,-1);
     

     //2nd call
     dfs2(1,0);//parent is 0
   
     
      
        return maxdist;
    }
   
};





//{ Driver Code Starts.

int main(){
   

        int N;
        scanf("%d",&N);
        
    
      vector<vector<int>>edges(N-1,vector<int>(2));
      
      for(int i=0;i<N-1;i++)
      {
        int a,b;
        cin>>a>>b;
        edges[i][0]=a;
        edges[i][1]=b;
        
      }
        
       
        
        Solution obj;
    vector<long long> res = obj.helper(N, edges);
        
 
for(int i=1;i<res.size();i++)
{
    cout<<res[i]-1<<" ";
}
  

    
}
// } Driver Code Ends


