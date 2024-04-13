#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        //no edghe case as s.size()==2 se hi start hga
        for(int i=1;i<s.size();i++)
        {
             sum+= abs((int)s[i]-(int)s[i-1]);//in ascii just write int in front of s[i] it will convert in ascii value
        }
        return sum;
        
    }
};
