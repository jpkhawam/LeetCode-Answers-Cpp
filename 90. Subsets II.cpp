#include <vector>
#include <algorithm>

using std::vector;

class Solution {
private:
    vector<vector<int>> *output = new vector<vector<int>>();

    void backtrack(int index, vector<int> &curr, vector<int> &nums) {
        if (index == nums.size()) {
            output->push_back(curr);
            return;
        }

        // All subsets that include nums[index]
        curr.push_back(nums[index]);
        backtrack(index + 1, curr, nums);
        curr.pop_back();

        // All subsets that don't include nums[index]
        while (index + 1 < nums.size() && nums[index] == nums[index + 1])
            // skip over any duplicates since they are next to each other
            index++;
        backtrack(index + 1, curr, nums);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        // sort input array to make possible skipping over duplicates
        std::sort(nums.begin(), nums.end());
        backtrack(0, *new vector<int>(), nums);
        return *output;
    }
};
