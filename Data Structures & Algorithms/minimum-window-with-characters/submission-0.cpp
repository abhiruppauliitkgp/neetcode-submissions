class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        int hashT[256] = {0};
        int hashS[256] = {0};

        // Frequency of characters in t
        for (char c : t)
            hashT[c]++;

        int l = 0;
        int start = 0;
        int minLen = INT_MAX;
        int matched = 0;

        for (int r = 0; r < s.size(); r++) {
            hashS[s[r]]++;

            // Count matched characters
            if (hashT[s[r]] > 0 && hashS[s[r]] <= hashT[s[r]])
                matched++;

            // Shrink window while it contains all characters
            while (matched == t.size()) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                hashS[s[l]]--;

                if (hashT[s[l]] > 0 && hashS[s[l]] < hashT[s[l]])
                    matched--;

                l++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};