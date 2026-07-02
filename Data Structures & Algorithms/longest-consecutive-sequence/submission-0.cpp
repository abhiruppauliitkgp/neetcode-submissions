class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());

        map <int,int> mp;

        for(int i = 0 ; i < nums.size() ; i++)
            mp[nums[i]]++;

        vector <int> distinct;

        for(auto it:mp)
            distinct.push_back(it.first);

        int count = 0;

        int maxi = 1;

        for(int i = 1; i < distinct.size() ; i++){
            if(distinct[i]==distinct[i-1]+1)
                count++;
            else
                count = 0;
            
            maxi = max(maxi,count+1);
        }

        return maxi;
    }
};