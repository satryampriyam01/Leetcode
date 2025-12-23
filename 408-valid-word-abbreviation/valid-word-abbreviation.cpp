class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        
        int m=word.size();
        int j=0;
        int n=abbr.size();

        for(int i=0;i<n;)
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
                
                j+=num;

                if(j>m)
                {
                    cout<<"point2 j "<<j<<" i "<<i<<endl;
                    //cout<<word[j]<<" "<<abbr[i]<<endl;
                    return 0;
                }
                
            }
            else
            {
                if(abbr[i]!=word[j])
                {
                    cout<<abbr[i]<<" "<<word[j]<<endl;
                    cout<<"point1"<<endl;
                    return 0;
                }
                else
                {
                    i++;
                    j++;
                }
            }

        }

    if(j!=m)
    {
        return 0;
    }



        return 1;
    }
};