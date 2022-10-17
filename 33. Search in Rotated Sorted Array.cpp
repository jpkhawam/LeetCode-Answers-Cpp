class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = (int) nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (target == nums[mid]) return mid;

            // are we in the left sorted portion?
            if (nums[left] <= nums[mid]) {
                if (target > nums[mid] || target < nums[left]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
                // we would be in right sorted portion
            else {
                if (target < nums[mid] || target > nums[right]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};
