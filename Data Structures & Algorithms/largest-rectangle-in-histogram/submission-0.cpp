class Solution {
public:
    vector<int> PSI(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                result[i] = st.top();
            }

            st.push(i);
        }

        return result;
    }

    vector<int> NSI(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, n);   // Changed from -1 to n
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                result[i] = st.top();
            }

            st.push(i);
        }

        return result;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left = PSI(heights);
        vector<int> right = NSI(heights);

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};