class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector <int> pre;
        vector <int> suf(n + 1);

        

        int product1 = 1;
        int product2 = 1;

        pre.push_back(1);

        for(int i = 0 ; i < n ; i++){
            product1 = nums[i]*product1;
            product2 = nums[n-i-1]*product2;
            pre.push_back(product1);
            suf[n-i-1] = product2;
        }

        suf[n] = 1;

        vector <int> ans;

        for(int i = 0 ; i < n ; i++){
            ans.push_back(pre[i]*suf[i+1]);
        }

        return ans;
    }
};
