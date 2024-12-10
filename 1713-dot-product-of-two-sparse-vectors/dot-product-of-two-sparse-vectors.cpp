class SparseVector {
public:

    unordered_map<int, int> amp;

    SparseVector(vector<int> &nums) {
        
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]!=0)
                {
                    amp[i]=nums[i];
                }
            } 
    }


    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {

        int result=0;
        for(auto i:vec.amp)
        { 
            for(auto j: this->amp)
            {
                int r=0;
                if(i.first==j.first)
                {
                    r=i.second*j.second;
                }
               //cout<<r<<endl;
               result+=r;
            }
            
        }

        return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);