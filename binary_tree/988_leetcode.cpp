/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 /*
 Classic backtracking exercise. Since it is quicker to add a character to the end of a string than it is to insert it at the beginning, it is best to build your strings in reverse order (from root to leaf).
Each time you add a leaf node to your current string, reverse it and compare with the lexiographically smallest string found so far.
Don't forget to reverse the current string again when you continue the backtracking.
 */

 /*
 Eye opening Test Case : [25,1,null,0,0,1,null,null,null,0]
My output : "abz"
Expected output: "ababz"

I eliminate abab while check (ab , abab) I pick ab is small but z is add in parent node logic fail brillant test case
 */


 //NOTE----- i tried using postorder ki niche se upr jana hai na string bnate hue to kyu na post order se kre
 //but that was wrong see my submission which failed on last test case
class Solution {
public:
string smallest="";//smallest jo hai
void helper(TreeNode* root,string &s)
{
     
    if(root==nullptr)
    {
        return ;
    }
    s+=char('a'+root->val);
   if(root->left==nullptr && root->right==nullptr)
    {
        reverse(s.begin(),s.end());
        if(smallest=="")
        {
            smallest=s;
        }
        else
        {
            if(smallest>s)
            {
                smallest=s;
            }
        }
        //wapas se reverse kyuki backtrack kr rhe hai na bhai

        reverse(s.begin(),s.end());
        s.pop_back();//yah v pop krna pdega wrna glti hga..when you will be at leaf node to upr me to vo node add kr diya na
        //par return se phle usko pop nhi krega to age gdbd hga...
        //isliye backtrack krte waqt na pop krna jrur
        return;
    }
    
    helper(root->left,s);
    helper(root->right,s);
    s.pop_back();//during recursive call back jo add kiya use remove kr do na is stack se jane se phle
    //as upr me string s is passes by refereal isly ye krna pdega

}
    string smallestFromLeaf(TreeNode* root) {
    string s="";
        helper(root,s);
        return smallest;
    }
};