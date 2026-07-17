class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int a = 0;
        for(int i = 0; i < piles.size(); i++){
            a = max(a, piles[i]);
        }

        int s = 1;
        int e = a;
        int ans = 0;

        while(e >= s){
            int mid = s + (e-s)/2;

            if(valid(mid, piles, h)){
                e = mid -1;
                ans = mid;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }


    bool valid(int mid,vector<int>& piles, int h){
        int temp = 0;
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] % mid > 0){
                temp += 1 + piles[i]/mid;
            }
            else{
                temp += piles[i]/mid;
            }
            if(temp > h){
                return false;
            }
        }
        return true;
    }
};
