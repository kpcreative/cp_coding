#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int findLowerBound(vector<vector<int>> &vec, long long k,int lo){
    int low = lo;
    int high = vec.size()-1;
    // ans will store the prev index of element which is the lower bound of k
    int ans = vec.size();  
    
    while(low <= high){
        
        int mid = low + (high - low) / 2;
        if(vec[mid][0] >k){
            high = mid-1;
        }
        else{
            ans = mid;
            low = mid+1;
        }
    }
     // return only ans+1 if you want just the index of lower-bound//as that will be index jaha se hame phir start krna hai
     return ans+1;
}
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        //sort on the basis of start point
        sort(points.begin(),points.end());
        //and try ki index=i se index=i+w tak agr koi start point hai to waha tak jaw and and us index tak ek rectangle needed hga
        long long ans=0;
        //and further rectangle will be needed after that index
        int get_index=0;
        for(int i=0;i<points.size();i+=get_index)
        {
            long long target=(long long)points[i][0]+w;//ki max jo elemnt hai yaha tak cover ho skta hai ek rectangle me
            get_index=findLowerBound(points, target,i);
            get_index-=i;//jo phle i tha usse minus kr do as i=3 pe tha let and get_index=5 aya to i+=get_index to =8 ho jiga na
            //isliye 5-3=2 to i+=2 i.e i=5 se start hga
            ans++;
          
        }
        return ans;
        
    }
};