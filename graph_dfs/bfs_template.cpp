//shortcut path wala template hai ye
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
  int helper(vector<vector<int>>&grid,int i,int j,int x,int y)
  {
      int n=grid.size();
      int m=grid[0].size();
      queue<pair<int,int>>q;
      q.push(make_pair(0,0));
      grid[0][0]=-1;
      int level=0;
      while(!q.empty())
      {
          int curr=q.size();
          level++;
          while(curr--){
          pair<int,int>p=q.front();
          q.pop();
          int fr=p.first;
          int sc=p.second;
          if(fr==x and sc==y) return level-1;
          for(int i=0;i<dir.size();i++)
          {
              int new_r=fr+dir[i][0];
              int new_c=sc+dir[i][1];
              if(new_r>=0 && new_c>=0 && new_r<n && new_c<m)
              {
                  if(grid[new_r][new_c]!=0&&grid[new_r][new_c]!=-1)
                  {
                      q.push(make_pair(new_r,new_c));
                      grid[new_r][new_c]=-1;
                  }
              }
          }
          }
      }
      //otherwise at last return -1;
      return -1;
  }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0) return -1;
        if(A[X][Y]==0) return -1;
        return helper(A,0,0,X,Y);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends