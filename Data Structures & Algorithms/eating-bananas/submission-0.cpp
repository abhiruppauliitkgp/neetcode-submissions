class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;
        int n = piles.size();

        while(high>=low){
            int k = (low+high)/2;

            int hours = 0;

            for(int i = 0 ; i < n ; i++)
                hours += ceil(double(piles[i])/double(k));

            if(hours<=h){
                ans = k;
                high = k - 1;
            }
            else
                low = k+1;
        }

        return ans;
    }
};
