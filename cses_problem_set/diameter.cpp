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
vector<vector<int>>dp;
int maxi=INT_MIN;
 int dfs(int node, int parent) {
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
     maxi=max(maxi,1+first+second);
     return 1+max(first,second);
    }
class Solution
{
public:
    int helper(int n,vector<vector<int>> &edges)
    {
        //base case is that when n is ==1 and n==2 and n==3 then answer will be 1 pair only alwys
       
     
           adj.resize(n+1, vector<int>());
   

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
      
     
       int ss=dfs(1,-1);
      
        return maxi-1;
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
    int res = obj.helper(N, edges);
        
 
    cout<<res;
  

    
}
// } Driver Code Ends


