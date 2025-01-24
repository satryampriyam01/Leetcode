class Solution {
public:
vector<string> result;
void helper(string str,int lef,int rgt)
{
    if(lef<0 || rgt<0 || rgt<lef)
    {
        return;
    }
    if(lef==rgt && lef==0)
    {
        result.push_back(str);
    }
    helper(str+'(',lef-1,rgt);
    helper(str+')',lef,rgt-1);

}
    vector<string> generateParenthesis(int n) {

        string str;
        str.clear();
        result.clear();
        
        helper(str,n,n);
        return result;
    }
};