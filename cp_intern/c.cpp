#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>mat;
vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
#include<queue>



//APPROACH----1
/*
ALL THE APPROACHES ARE AS FOLLOWS---
1- using recursion/dfs based approach


EDGE CAsE---
start from given src(src_i,src_j) for the edge case see that this start src and destination where we are going should not have wall(i.e 1) as we cant reach then return false directly
else
{
    from given src go in all the 4 directions and maintain parent index from where you have come
  


solve(int i,int j,visited array)
{
    from(i,j)---->go in 4 directions (except(which are visited dont go to it)) which are not visited)
    
    otherwise
    {
        if((i,j)==(dest_i,dest_j)) return true;...i.e we have reached the destination 
        //and dont call for the further recursive call return true---as we have got 1 path from src to destination
    }
}
otherwise return false--i.e you are not able to reach
return false;

---its time complexcity will be O(M*N*4)

}

*/








//aproach-2

/*
for this i am using BFS based approach for it

time complexcity--- in general bfs takes o(v+e) here in our case v==m*n i.e no of vertices
and E==no of edges here the no of edges is 4 only as we can move in 4 direction only 
//so overall complexcity is o(4*m*n)==o(m*n)
Imagine a grid where all cells are 0 (open and not walls). If you start BFS from one corner, the BFS may need 
to enqueue all the cells in a large section of the grid before it starts to dequeue and process them.
In this scenario, the number of cells in the queue can grow up to O(M * N) before the BFS reaches the 
destination or runs out of cells to explore.
*/
bool bfs(int i,int j,int dest_i,int dest_j )
{
    if((mat[i][j]==1) || (mat[dest_i][dest_j]==1)) return false;//edge case if already from where we start or go if it has wall then we cant reach
else{
    queue<pair<int,int>>q;
    q.push(make_pair(i,j));
    mat[i][j]=-1;
    while(!q.empty())
    {
        auto it=q.front();
        int c_r=it.first;
        int c_c=it.second;
        q.pop();
        if(c_r==dest_i && c_c==dest_j) return true;//we reached here
        for(int i=0;i<4;i++)
        {
            int new_r=c_r+dir[i][0];
            int new_c=c_c+dir[i][1];
            if(new_r>=0 && new_c>=0 && new_r<mat.size() && new_c<mat[0].size())
            {
                //which are not visited take those
                if(mat[new_r][new_c]==0)
                {
                    q.push(make_pair(new_r,new_c));
                    mat[new_r][new_c]=-1;
                }
            }
        }
    }
    return false;
}
    
}
int main()
{
int m,n,src_i,src_j,dest_i,dest_j;
cout<<"enter the grid size"<<endl;

cin>>m>>n;
cout<<"enter the src and dest index position"<<endl;
cin>>src_i>>src_j;
cin>>dest_i>>dest_j;
mat.resize(m,vector<int>(n,0));
//for building matrix it took o(m*n)
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        int e;
        cin>>e;
        mat[i][j]=e;
    }
}
//now call for bfs
bool f=bfs(src_i,src_j,dest_i,dest_j);
if(f==true)
{
    cout<<"yes you can reach the destination"<<endl;
}
else{
    cout<<"no you cant reach the destination"<<endl;
}

}




/*
MODIFIED QUESTION-------

You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle).
 You can move up, down, left, or right from and to an empty cell in one step.
 given that you can eliminate at most k obstacles
 now give answer can you reach the destination or not

 grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
 Solution: 
	1. Since it talks about the can we reach or not.
	2. We use the visited array (matrix only) in a different way to keep storing the number of obstacles 
		that we can still remove after walking through that cell. (Basically BEST remaining K after reaching that cell)
	3. Simply traverse the BFS by storing the X, Y and currentK remaining in the queue.
	4. If you reach the destination index, return the true
	5. If you try to access an invalid cell, i.e with (obstacle)
		or you hit an obstacle but have no K to spend(i.e you cant break it), 
		or this index X and Y have already been accessed and with a better remaining K than yours or say directly if already visited, WE SKIP/continue.
	6. Push the adjacent indexes into the queue.
    7. if we get that destination then return true other wise false
    8.time complexcity o(m*n)
    9.space=o(m*n) visited matrix




*/