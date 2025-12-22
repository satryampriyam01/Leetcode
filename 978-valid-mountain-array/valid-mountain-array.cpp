class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

     int se=0;
     int n=arr.size();
     for(se;se+1<n;se++)
     {
        if(arr[se]>=arr[se+1])
        {
            break;
        }
     }

     if(se==0 || se==n-1)
     {
        return 0;
     }


     for(se;se+1<n;se++)
     {
        if(arr[se+1]>=arr[se])
        {
            return false;
        }
     }

     return true;

    }
};