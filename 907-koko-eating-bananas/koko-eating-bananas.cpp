class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int se=0;
        int en=0;
        int answer=INT_MAX;

        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            en=max(en,piles[i]);
        }


        while(se<=en)
        {
            int banana=(se+en)/2;
            int result=0;

            for(int i=0;i<n;i++)
            {
                if(banana>=piles[i])
                {
                    result+=1;
                }
                else
                {
                    if(banana)
                    result+=ceil((double)piles[i]/(double)banana);
                }
            }

            if(result<=h && banana)
            {
                answer=min(answer,banana);
                en=banana-1;
            }
            else
            {
                se=banana+1;
            }

        }

        return answer;

    }
};