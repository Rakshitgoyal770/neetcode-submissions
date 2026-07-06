class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int leftMax = height[0];
        int rightMax = height[height.size() - 1];
        int ans = 0;

        while(l < r){
            if(height[l] <= height[r]){
                if(leftMax > height[l]){
                    ans += leftMax - height[l];
                    l++;
                }
                else{
                    leftMax = height[l];
                    l++;
                }
            }
            else{
                if(rightMax > height[r]){
                    ans += rightMax - height[r];
                    r--;
                }
                else{
                    rightMax = height[r];
                    r--;
                }

            }
        }
        return ans;
        
    }
};
