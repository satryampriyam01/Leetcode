class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int start=0;
        int start2=0;

        while(start2<n && start<m)
        {
            if(nums1[start]>nums2[start2])
            {
                swap(nums1[start],nums2[start2]);
                sort(nums2.begin(),nums2.end());
              
            }
            else
            {
                start++;
            }
        }

        while(start<m+n && start2<n)
        {
            nums1[start++]=nums2[start2++];
        }
       

    }
};