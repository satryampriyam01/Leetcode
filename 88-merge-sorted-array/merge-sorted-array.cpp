class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int en=m-1;
        int en2=n-1;
        int in=m+n-1;

        while(in>-1 && en>-1 && en2>-1)
        {
            if(nums1[en]>nums2[en2])
            {
                nums1[in]=nums1[en--];
            }
            else
            {
                nums1[in]=nums2[en2--];
            }
            in--;
        }

        while(in>-1 && en2>-1)
        {
            nums1[in]=nums2[en2];
            in--;
            en2--;
        }

    }
};