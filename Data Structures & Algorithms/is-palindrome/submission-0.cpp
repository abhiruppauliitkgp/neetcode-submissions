class Solution {
public:
    bool isPalindrome(string s) {

        string compare = "";

        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9')
                compare = compare + (char)tolower(s[i]);
        }

        int p1 = 0;
        int p2 = (int)compare.size()-1;

        while(p1<=p2){
            if(compare[p1]!=compare[p2])
                return false;

            p1++;
            p2--;
        }

        return true;
        
    }
};