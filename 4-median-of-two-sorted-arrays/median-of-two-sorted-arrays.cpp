class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

       int n=nums1.size();
       int m=nums2.size();
       nums1.resize(m+n);
       int j=0;

       for(int i=n;i<m+n;i++)
       {
            nums1[i]=nums2[j++];
       } 

       sort(nums1.begin(),nums1.end());

       return (m+n)%2?nums1[(n+m)/2]:(nums1[(n+m)/2-1] + nums1[(n+m)/2])/2.0;
    }
};