//https://www.codechef.com/problems/REDUARRAY?tab=statement

//explanation
/*

 //isse phle ham pura 1 to n tak loop chla diye th kyuki mujhe pata nhi tha ki sirf array ke elemnt me se hi "x" lena hai
    //and maine actual me wahi kra tha ki jitne frequency the un sare ke map me store kra tha
    //store krne ke bad na maine 1 to n loop chalay tha
    //agr koi present hai to thik total me se uska frequency minus kro and phir uske value se multiply kro
    //overall yhi krna tha
    //let example arr=[2,3,4,5] sara ka frequency =1 hi hai
    //agr array ka element lnge tb mujhe mincost sbko 2 bdlne me lgega i.e 6 
    //par agr sare ko 1 se replace kr de to 5 cost lgega 
    //to minimum to 5 laga na
    //isliye maine 1 to n loop chalay tha..bhale vo elemnt array me ho ya na ho muhjhe minimum chaiye jise above example me hai 
    //1 to n because array ka value ya n ka value 1 to n hi ho sktra hai aur kuch nhi ho skta hai
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        unordered_map<long long, long long> mp;
       
        long long totalElements = 0;
        
        for (int i = 0; i < n; i++) {
            long long e;
            cin >> e;
            a[i] = e;
            mp[a[i]]++;
            totalElements++;
        }
        
      
        long long minCost = LLONG_MAX;
        
       
            
         
        for(long long i=1;i<=n;i++)
        {
            if(mp.find(i)!=mp.end())
            {
                minCost=min(minCost,(totalElements-mp[i])*i);
            }
            else
            {
                minCost=min(minCost,totalElements*i);
            }
        }
        
        cout << minCost << endl;
    }
    return 0;
}
