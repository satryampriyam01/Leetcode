class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {

        string encode="";

        for(int i=0;i<strs.size();i++)
        {
            encode+=(to_string(strs[i].size())+'.'+strs[i]);
        }

        return encode;
        
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {

        vector<string> result;

        for(int i=0,size=0;i<s.size();i+=size,size=0)
        {
            while(isdigit(s[i]) && i<s.size())
            {
                size=size*10+(s[i++]-'0');
            }
            string res=s.substr(++i,size);
            result.push_back(res);
        }

        return result;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));