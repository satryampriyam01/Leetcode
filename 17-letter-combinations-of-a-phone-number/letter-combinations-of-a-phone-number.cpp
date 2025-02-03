class Solution {
public:

void helper(string &digits,int index, string str,vector<string> &result, vector<string> &amp)
{
    if(index==digits.size())
    {
        if(str.size())
        result.push_back(str);
        return ;
    }

    for(auto ch:amp[digits[index]-48])
    {
        helper(digits,index+1,str+ch,result,amp);
    }
}


    vector<string> letterCombinations(string digits) {

      vector<string> mp = {"", "", "abc", "def", "ghi", 
                         "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> result;

        helper(digits,0,"",result,mp);

        return result;

    }
};