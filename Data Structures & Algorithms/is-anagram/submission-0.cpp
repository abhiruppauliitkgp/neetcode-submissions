class Solution {
public:
    bool isAnagram(string s, string t) {
        int check1[256] = {0};

        int check2[256] = {0};

        for(int i = 0 ; i < s.length() ; i++)
            check1[s[i]]++;

        for(int i = 0 ; i < t.length() ; i++)
            check2[t[i]]++;

        for(int i = 0 ; i < 256 ; i++){
            if(check1[i]!=check2[i])
                return false;
        }

        return true;
    }
};
