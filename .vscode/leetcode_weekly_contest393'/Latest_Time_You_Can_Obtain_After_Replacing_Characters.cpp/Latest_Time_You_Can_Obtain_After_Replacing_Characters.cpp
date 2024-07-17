class Solution {
public:
    string findLatestTime(string s) {
        //one posiiblities ki agr yaha ? hai to s[1] pe chahe ? ho ya 0 1 tak koi ho to 1 hi put krna
        //kyuki s[0]=? and s[1]=? the 11 hi hna chahiye as yhi lates hai
        //isliye maine bola ki s[1=? then also put 1 at s[0]
        //s[1] pas possiblities hai ki 0,1,2,3,4,5,6,7,8,9...ye aa skte ha..par agr s[1] pe<'2' rha to s[1] pe 1 hi ayega
        //agr s[1]>='2' rha lk es[1]=8 to s[0]='0' hi rhna pdega as 18 nhi 08 tak hi reh skta hai
        if(s[0]=='?')
        {
            if(s[1]=='?' || s[1]<'2')
            {
                s[0]='1';
            }
            else
            {
                s[0]='0';
            }
        }
        if(s[1]=='?')
        {
            if(s[0]=='0')
            {
                s[1]='9';
            }
            else
            {
                s[1]='1';
            }
        }
        if(s[3]=='?')
        {
            s[3]='5';
        }
        if(s[4]=='?')
        {
            s[4]='9';
        }
        return s;
    }
};