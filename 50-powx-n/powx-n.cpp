class Solution {
public:
    double myPow(double x, int n) {
        long long exp=n;

        if(n==0)
        {
            return 1.00;
        }

        if(exp<0)
        {
            x=1/x;
            exp*=(long long)-1;
        }
        

        if(exp%2)
        {
           return x*myPow(x*x,exp/2);
        }
        else
        {
           return myPow(x*x,exp/2);
        }
    }
};