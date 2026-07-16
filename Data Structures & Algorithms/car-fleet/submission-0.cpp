class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, int>> sorted;
        int n = position.size();

        for (int i = 0; i < n; i++) {
            sorted.push_back({position[i], speed[i]});
        }

        sort(sorted.begin(), sorted.end());


        stack<pair<int, int>> st;
        st.push(sorted[n-1]);
        int ans = 1;

        for(int i = n-2; i>=0 ; i--){
            double time1 = (double)(target - st.top().first) / st.top().second;

           double time2 = (double)(target - sorted[i].first) / sorted[i].second;

           if (time2 > time1) {
                ans++;
                st.push(sorted[i]);
            }
        }
        return ans;

    }
};