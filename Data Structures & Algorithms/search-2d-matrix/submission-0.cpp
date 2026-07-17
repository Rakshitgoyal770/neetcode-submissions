class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int s = 0;
        int e = rows - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            int start = matrix[mid][0];
            int end = matrix[mid][cols - 1];

            if (target >= start && target <= end) {

                int ss = 0;
                int ee = cols - 1;

                while (ss <= ee) {
                    int mid1 = ss + (ee - ss) / 2;

                    if (matrix[mid][mid1] == target)
                        return true;

                    if (matrix[mid][mid1] < target)
                        ss = mid1 + 1;
                    else
                        ee = mid1 - 1;
                }

                return false;   // target should be in this row but isn't
            }

            else if (target < start) {
                e = mid - 1;
            }

            else {
                s = mid + 1;
            }
        }

        return false;
    }
};
