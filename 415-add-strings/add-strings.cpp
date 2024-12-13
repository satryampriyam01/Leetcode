class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int i=num1.size()-1;
        int j=num2.size()-1;

        string res="";
        int carry=0;

        while(j>-1 || i>-1 || carry)
        {
            int r=0;

            if(i>-1)
            {
                r+=((num1[i--])-48);
            }

            if(j>-1)
            {
                r+=((num2[j--])-48);
            }

            r+=carry;
            carry=r/10;
            r=r%10;
            
            res+=(r+48);

        }


        reverse(res.begin(),res.end());
        return res;
    }
};