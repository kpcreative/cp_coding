//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


//NOTE--- https://youtu.be/nGhE4Ekmzbc?si=Vooi0Y3XBqcNkHyz
//PREFER THE ABOVE VIDEO IF GOT STUCKED....BUTS ITS MATH AND SOME KIND OF RE ROOTING
//LIKE NODE(U)=1+NEIGHBOR PE JO HGA ANSWER
//PR NEIGHBO PE JITNE NODE HNGE UN SBME YE 1+ ADD HGA....TO AISE KRKE MERE NODE(U)=NEIGHBR KA ANS+ NO OF NODES AT NGHBR PE AA GYA
//Y TRA SUBTREEANS AISE CALCULATE KRA HAI HMNE



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

vector<long long>subtreeans;
vector<long long>nodes;
vector<long long>ans;
 int dfs(long long node, long long parent) {
   long long nodess=0;
    for(auto nghbr:adj[node])
    {
        if(nghbr==parent) continue;
       nodess+=dfs(nghbr,node);//bhai upr me no of nodes calculate hokr aa hi jiga...chuki recursion chal rha hai to subtreeans[leaf] phle set hga jo ki=0 hi hga
       subtreeans[node]+=(subtreeans[nghbr]+nodes[nghbr]); //ye har subtreeans yha pe store krke rkh lete hai....see in copy jo btaya hai...trust on the recurence ye kr lega bhai
    }
   nodes[node]=1+nodess;
    return 1+nodess;

    }




    
    void dfs2(long long node,long long  parent)
    {
        //ye ek edge case tha jo ham glt kr rhe the
        if(node==1)
        {
            ans[node]=subtreeans[node];
        }
        //obvious hai bhai ans[npde] calculate krte tym ham obvious hai ki ans[parent calculate kr liye hnge...so dont be worry yar bhai mere]
        else{
         //agr ise for loop ke andr likhega to bhai leaf ke liye calculate hi nhi kr piga isliye upr likho..,you can see in dry run also yar
          //dekh tumko to aise hr parent se v puchna hga is current nghbr ko hta ke ki is node se unka distance kitna hai...to after caluclating hame ye mila tha.....see the copy or photo or i have pasted the video link above prefer that only
            ans[node]=subtreeans[node]+ans[parent]-subtreeans[node]-nodes[node]+nodes[1]-nodes[node]; //i calculated it in copy see it
            //node[1] jo hai n total no of nodes hai vo actual me in tree
        }
        for(auto nghbr:adj[node])
        {
            if(nghbr==parent) continue;
          
            dfs2(nghbr,node);
        }
      
    }
    
class Solution
{
public:
    vector<long long> helper(int n,vector<vector<int>> &edges)
    {
        //base case is that when n is ==1 and n==2 and n==3 then answer will be 1 pair only alwys
       
           subtreeans.resize(n+1,0);
           nodes.resize(n+1,0);//for storing number of nodes
           adj.resize(n+1, vector<int>());
          
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
      
    
     int ss=  dfs(1,-1);
     //now call second dfs jisme ham re rooting krnge
ans.resize(n+1,0);
     dfs2(1,0);
     
   
     
      
        return ans;
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
    cout<<res[i]<<" ";
}
  

    
}
// } Driver Code Ends


