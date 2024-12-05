class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        int prevval = 0, res = 0;
        long long num = 0;
        char prevop = '+';
        for(int i=0; i<n; i++){
            if(s[i] >='0' && s[i] <='9'){
                num = num*10 + s[i]-'0';
            }
            if(s[i] == '+' || s[i]=='-' || s[i] == '*' || s[i] == '/' || i==n-1){
                if(prevop == '+'){
                    res += prevval;
                    prevval = num;
                }else if(prevop == '-'){
                    res += prevval;
                    prevval = -num;
                }else if(prevop == '*'){
                    prevval *= num;
                    cout<<prevval<<endl;
                }else if(prevop == '/'){
                    prevval /= num;
                }


                num = 0;
                prevop = s[i];
            } 
        }
        res += prevval;
        return res;
    }
};