class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        vector<int> mp1(26, 0), mp2(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            mp1[s1[i] - 'a']++;
            mp2[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (mp1[i] == mp2[i])
                matches++;
        }

        int l = 0;
        int r = s1.size();

        while (r < s2.size()) {
            if (matches == 26)
                return true;

            // Add new character
            int idx = s2[r] - 'a';
            mp2[idx]++;
            if (mp2[idx] == mp1[idx])
                matches++;
            else if (mp2[idx] == mp1[idx] + 1)
                matches--;

            // Remove left character
            idx = s2[l] - 'a';
            mp2[idx]--;
            if (mp2[idx] == mp1[idx])
                matches++;
            else if (mp2[idx] == mp1[idx] - 1)
                matches--;

            l++;
            r++;
        }

        return matches == 26;
    }
};