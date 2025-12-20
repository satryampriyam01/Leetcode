class Solution {
public:
    bool isStrobogrammatic(string num) {
        
        int se=0;
        int en=num.size()-1;
        

        while(se<en)
        {
            if((num[se]=='6' && num[en]=='9') || (num[se]=='8' && num[en]=='8') ||
            (num[se]=='9' && num[en]=='6') || (num[se]=='1' && num[en]=='1') || (num[se]=='0' && num[en]=='0'))
            {
                se++;
                en--;
                continue;
               
            }
            else
            {
                return false;
            }
             
        }

        if(num.size()%2)
        {
            if(num[se]=='8' || num[se]=='1' || num[se]=='0')
            {
                return 1;
            }
            return 0;
        }


        return true;
    }
};