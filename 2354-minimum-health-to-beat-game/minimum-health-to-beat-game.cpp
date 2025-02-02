class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        
        sort(damage.begin(),damage.end());
        int n=damage.size();
        damage[n-1]-=armor;
        long long result=0;
        for(int i=0;i<n;i++)
        {
            if(damage[i]>0)
            {
                result+=damage[i];
            }
            
        }

        return result+1;
    }
};