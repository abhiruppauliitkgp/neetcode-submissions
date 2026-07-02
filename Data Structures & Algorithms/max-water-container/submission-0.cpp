class Solution {
public:
    int maxArea(vector<int>& heights) {

        int p1 = 0;
        int p2 = heights.size() - 1;

        int store = 0;

        while(p1<p2){
            int water = min(heights[p1],heights[p2])*(p2-p1);

            store = max(store,water);

            if(heights[p1]>heights[p2])
                p2--;
            else if(heights[p1]<heights[p2])
                p1++;
            else{
                p1++;
                p2--;
            }

        }
        return store;     
    }
};
