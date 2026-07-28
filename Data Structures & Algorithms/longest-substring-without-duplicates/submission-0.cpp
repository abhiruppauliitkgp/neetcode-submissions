class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int lenmax = 0;

        map<char, int> mp;

        while (r < s.size()) {
            mp[s[r]]++;

            while (mp[s[r]] > 1) {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }

            lenmax = max(lenmax, r - l + 1);
            r++;
        }

        return lenmax;
    }
};