class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxi = 0;
        int ans = 0;
        int s = prices.size();
        if(s <= 1) {
            return 0;
        }

        for(int i = 1; i < s; i++){
            if(prices[i] - mini > 0){
                maxi = max(maxi, prices[i] - mini);
                cout << prices[i];
            }

            if(mini > prices[i]){
                mini = prices[i];
                cout << mini;
            }

        }
        return maxi;
        
    }
};
