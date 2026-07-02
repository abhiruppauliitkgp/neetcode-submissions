class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";

        for(int i = 0 ; i < strs.size() ; i++)
            encoded_string = encoded_string + strs[i] + "-";

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector <string> decoded_strs;

        string temp = "";

        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]!='-')
                temp = temp + s[i];
            else{
                decoded_strs.push_back(temp);
                temp = "";
            }

        }

        return decoded_strs;
    }
};
