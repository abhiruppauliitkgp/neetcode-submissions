class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0;
        int p2 = numbers.size() - 1;

        vector <int> ans;

        while(p1<p2)
        {
            int sum = numbers[p1] + numbers[p2];

            if(sum>target)
                p2--;
            else if (sum<target)
                p1++;
            else{
                ans.push_back(p1+1);
                ans.push_back(p2+1);
                break;
            }
        }

        return ans;
    }
};
