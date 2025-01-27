class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int ans=INT_MAX;

        int maxi=0;
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,piles[i]);
        }

        int se=0;
        int en=maxi;

        while(se<=en)
        {
            int mid=(se+en)/2;
            int resulting_hr=0;

            for(int i=0;i<n;i++)
            {
                if(mid>=piles[i])
                {
                    resulting_hr+=1;
                }
                else
                {
                    if(mid)
                    resulting_hr+=ceil((double)piles[i]/(double)mid);
                }
            }

            if(resulting_hr<=h && mid)
            {
                //cout<<resulting_hr<<" "<<mid<<endl;
                en=mid-1;
                ans=min(mid,ans);
            }
            else
            {
                se=mid+1;
            }


        }


        return ans;

    }
};