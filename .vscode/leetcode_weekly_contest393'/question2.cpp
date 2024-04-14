class Solution {
public:


const int lim = 100; // exclusive


    

   

    
//it is sieve method to generate all the prime numbers between 1 to 100 by sieve method

    int maximumPrimeDifference(vector<int>& nums) {
        //phle i generated all the prime numbers between 1 to 100 
        unordered_set<int>st;
        vector<int> n(lim - 2); // exclude 1
    for (int i = 2; i <= lim - 1; i++) { // initialize the array with integers from 2 to lim
        if ((i & 1) == 0) { // evens are not primes. i & 1 returns 0 if i % 2 == 0
            n[i - 2] = 0;
        } else {
            n[i - 2] = i;
        }
    }

    n[0] = 2;

    int p = 3; // start with a prime. Since 2 is already eliminated, start with 3

    while (p * p < lim) {
        for (int i = p * p; i < lim; i += p + p) { // remove multiples of prime. Start at p * p
            n[i - 2] = 0;
        }

        while (n[(p += 2) - 2] == 0) { // find next non-zero number. This is guaranteed to be a prime.
        }
    }
         for (int i = 0; i < lim - 2; i++) { // print non-zero numbers
        if (n[i] != 0) {
            st.insert(n[i]);
        }
        
        
    }
      //now ab check max diff in index
        int index1=-1;
        int index2=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i])!=st.end())
            {
                index1=i;
                break;
            }
        }
                for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i])!=st.end())
            {
                index2=i;
              //aur ye last tak chlte rhega
            }
        }
        //if(index1==-1) and index2==-1). then mila hi ny koi prime ..par aisa to nhi hai ek to milega hi question ke constarints me bola hai
        return index2-index1;
        
    }
};