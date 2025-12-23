class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        

        int m=word.size();
        int n=abbr.size();
        int i=0;
        int se=0;

        for(i=0;i<n;)
        {
            int num=0;

            if(isdigit(abbr[i]))
            {
                if(abbr[i]-48==0)
                {
                   
                    return 0;
                } 
                while(isdigit(abbr[i]) && i<n)
                    { 
                        int r=abbr[i]-48;
                        num=num*10+r;
                        i++;
                    }
                   
                se+=num;
                if(se>m)
                {
                    return 0;
                }
            }
            else
            {
                if(word[se]!=abbr[i])
                {
                    cout<<"here"<<endl;
                    return 0;
                }
                else
                {
                    i++;
                    se++;
                }
            }

            
        }

        if(se==m)
        {
            return 1;
        }
        cout<<se<<" "<<i<<endl;
        cout<<"Here2"<<endl;
        return 0;

    }
};