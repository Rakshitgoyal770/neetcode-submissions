class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st; // {start_index, height}
        int ans = 0;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;

            while (!st.empty() && heights[i] < st.top().second) {
                auto [index, height] = st.top();
                st.pop();
                ans = max(ans, height * (i - index));
                start = index;
            }

            st.push({start, heights[i]});
        }

        // Process remaining stack
        int n = heights.size();
        while (!st.empty()) {
            auto [index, height] = st.top();
            st.pop();
            ans = max(ans, height * (n - index));
        }

        return ans;
    }
};
