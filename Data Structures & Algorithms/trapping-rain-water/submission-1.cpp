class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> left(size, 0);
        vector<int> right(size, 0);

        left[0] = height[0];
        right[size-1] = height[size-1];

        int temp = height[0];
        int temp2 = height[size-1];
        int ans = 0;

        if (height.size() <= 2)
        {
            return 0;
        }
            
 

        for(int i = 1; i < size; i++){
            if(temp > height[i]){
                left[i] = temp;
            }
            else{
                temp = height[i];
                left[i] = 0;
            }
        }

        for(int i = size-1; i >= 0; i--){
            if(temp2 > height[i]){
                right[i] = temp2;
            }
            else{
                temp2 = height[i];
                right[i] = 0;
            }
        }

        for(int i = 1; i < size -1; i++){
            if(left[i] == 0 || right[i] == 0){
                continue;
            }
            int local = min(left[i], right[i]) - height[i];
            ans += local;
        }
        return ans;
        
    }
};
