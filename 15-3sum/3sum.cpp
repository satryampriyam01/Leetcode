class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> answer;
        sort(nums.begin(),nums.end());
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            
            if(i && nums[i]==nums[i-1])
            {
                continue;
            }
            else
            {
                int num=nums[i];
                int se=i+1;
                int en=n-1;

                while(se<en)
                {
                    if(num+nums[se]+nums[en]>0)
                    {
                        en--;
                    }
                    else if(num+nums[se]+nums[en]<0)
                    {
                        se++;
                    }
                    else
                    {
                        vector<int> result;
                        result.push_back(num);
                        result.push_back(nums[se]);
                        result.push_back(nums[en]);
                        answer.push_back(result);

                        while(se<n-1 && nums[se]==nums[se+1])
                        {
                            se++;
                        }

                        while(en>0 && nums[en]==nums[en-1])
                        {
                            en--;
                        }
                        se++;
                        en--;
                    }
                }
            }
        }


        return answer;
    }
};