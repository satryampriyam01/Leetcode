class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int result=0;

        int start=0;
        int ending=height.size()-1;

        while(start<ending)
        {
            result=max(result,min(height[start],height[ending])*(ending-start));

            if(height[start]<height[ending])
            {
                start++;
            }
            else
            {
                ending--;
            }
        }

        return result;
    }
};