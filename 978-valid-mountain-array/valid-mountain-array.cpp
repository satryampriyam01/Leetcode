class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        int n=arr.size();
        int se=0;
        while(se+1<n && arr[se]<arr[se+1])
        {
            se++;
        }

        if(se==n-1 || se==0)
        {
            return 0;
        }

        while(se+1<n && arr[se]>arr[se+1])
        {
            se++;
        }

        if(se==n-1)
        {
            return 1;
        }

        return 0;
    }
};