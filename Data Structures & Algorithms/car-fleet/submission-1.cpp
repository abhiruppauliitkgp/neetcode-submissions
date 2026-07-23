class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> cars;

        for(int i = 0; i < position.size(); i++)
            cars.push_back({position[i], speed[i]});

        sort(cars.rbegin(), cars.rend());

        vector<double> time(cars.size());

        for(int i = 0; i < cars.size(); i++)
            time[i] = (double)(target - cars[i].first) / cars[i].second;

        stack<double> st;

        if(time.empty()) return 0;

        st.push(time[0]);

        for(int i = 1; i < time.size(); i++) {
            if(time[i] > st.top())
                st.push(time[i]);
        }

        return st.size();
    }
};