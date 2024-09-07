//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


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

 int dfs(vector<int>& sub,int node, int parent) {
      
        int sum=0;
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
               sum+= 1+dfs(sub, neighbor, node);
               
            }
        }
         sub[node-1] =sum;
         return sum;
    }
class Solution
{
public:
    vector<int> helper(int n, vector<int> &sub,vector<vector<int>> &edges)
    {
           adj.resize(n+1, vector<int>());
   
     
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
       int ss= dfs(sub,1,-1);
     
       
      
        return sub;
    }
   
};





//{ Driver Code Starts.

int main(){
   

        int N;
        scanf("%d",&N);
        
      vector<int>sub(N+1,0);
      vector<int>sub1(N-1,0);
      for(int i=0;i<N-1;i++)
      {
        int e;
        cin>>e;
        sub1[i]=e;
      }
      vector<vector<int>>edges(N-1,vector<int>(2));
      int k=0;
      for(int i=2;i<=N;i++)
      {
        edges[k][0]=i;
        edges[k][1]=sub1[k];
        k++;
      }
        
       
        
        Solution obj;
        vector<int> res = obj.helper(N, sub, edges);
        
  for(int i=0;i<N;i++)
  {
    cout<<res[i]<<" ";
  }

    
}
// } Driver Code Ends


