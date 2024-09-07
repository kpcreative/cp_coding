//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
//https://youtu.be/ZJciCm1kpGQ?si=SQoNTXEz8St8L-nl    
//prefer the above link for the video to understand in more clear ways

//THIS IS THE TEMPLATE OF GFG SO DONTT BE CONFUSE...


//why greeedy fails here lets see
/*
 solved it by simply traversing the tree using dfs
1.  maintained a set
2.  preform dfs
3.  during dfs check if both the node and the parent is in the set or not
4. if not present ,, push node and parent  into the set
5. print size(set)/2


it will fail for this scenario.
1
4
1 2
1 3
2 4
The expected output is 2 but your code output is 1.


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
vector<vector<int>>dp;
 int dfs(int node, int parent,int take) {
      if(dp[node][take]!=-1) return dp[node][take];
       //phle not take liya agr
       if(take==0)//no take the
       {
         int ans=0;
         //to iske sare neighbour ko ham include kr skte hai and usne jo answer ayega we can store them also
         for(auto nghbr:adj[node])
         {
            if(nghbr!=parent)//parent pe wwaps mt chl jana wrna cycle me fans jaoge
            {
               //to sare neighbr ko include krke jo answer ayega vo mera answer hoga isme
               ans+=dfs(nghbr,node,1);//include kro inko
            }
         }
         return dp[node][take]=ans;//jo is current node ka hai vo to aa gye na vo store kr lo
       }
       else{
        //agr include hoga to now you have to calculate lets see
        //its important part here

        //agr take kr rha hai bhai to obvious us node ke liye ye loop me hi ayega...to uska answer fresh se strt hona chaiye na isliye hamne int ans=0 define kra hai yha pe

        int ans=0;
        for(auto nghbr:adj[node])
        {
            if(nghbr!=parent)//parent pe wwaps mt chl jana wrna cycle me fans jaoge
            {
             ans+=dfs(nghbr,node,1);//include kro inko...inckude krke answer la lo ...ham soche the ki answer already calculate rhega par nhhi bhai aisa nhi hai...wrong answer aya tha...tumko ek bar jakr calculagte krna hi pdega ise..tbhi na kuch hga and we will store 
             //it in dp vector and phir jisko ham le rhe hnge usko exclude kr denge ham
            }
        }
        int myres=0;
        for(auto nghbr:adj[node])
        {
             if(nghbr!=parent)//parent pe wwaps mt chl jana wrna cycle me fans jaoge
            {
            myres=max(myres,ans-dp[nghbr][1]+1+dfs(nghbr,node,0));
            }
        }
        return dp[node][take]=myres;//include pe aya na ye isliye dp[][take] likhe hai ham
       }
    }
class Solution
{
public:
    int helper(int n,vector<vector<int>> &edges)
    {
        //base case is that when n is ==1 and n==2 and n==3 then answer will be 1 pair only alwys
       if(n==2||n==3)
        {
            return 1;
        }
     
           adj.resize(n+1, vector<int>());
   
     dp.resize(200005,vector<int>(2,-1));
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
       int ss= max(dfs(1,-1,0),dfs(1,-1,1));//phli bar jo hai usme 1 not included hai isliye 0 pass kiye hai...and ek me 1 included hai isliye 1 pass kiye hai....and isme se jo max aa jaye wahi mera answer hoga

     
       
      
        return ss;
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


