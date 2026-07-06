class Solution {
public:
    int maxArea(vector<int>& heights) {
        int s = 0;
        int e = heights.size() -1;
        int ans = 0;

        while(e > s){
            int ss = heights[s];
            int ee = heights[e];
            int temp = min(ss, ee) * (e - s);


            if(ss >= ee){
                e --;
            }
            if(ee > ss){
                s ++;
            }

            ans = max(ans, temp);
        }
        return ans;
        
    }
};
 