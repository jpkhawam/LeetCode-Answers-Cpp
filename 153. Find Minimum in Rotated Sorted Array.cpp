class Solution {
public:
    int findMin(vector<int>& nums) {
    int result = nums[0];
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        if (nums[left] < nums[right]) {
            result = result < nums[left] ? result : nums[left];
            break;
        }
        int mid = (left + right) / 2;
        result = result < nums[mid] ? result : nums[mid];
        if (nums[mid] >= nums[left]) {
            left = mid + 1;
        } else {
            right = mid -1;
        }
    }
    return result;
    }
};
