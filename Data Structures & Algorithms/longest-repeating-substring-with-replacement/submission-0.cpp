class Solution {
public:
    int characterReplacement(string s, int k) {

        int maxlen = 0;

        set<char> charSet(s.begin(), s.end());

        for (char c : charSet) {

            int count = 0;
            int l = 0;

            for (int r = 0; r < s.size(); r++) {

                if (s[r] == c)
                    count++;

                while ((r - l + 1) - count > k) {
                    if (s[l] == c)
                        count--;
                    l++;
                }

                maxlen = max(maxlen, r - l + 1);
            }
        }

        return maxlen;
    }
};