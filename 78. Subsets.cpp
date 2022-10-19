class Solution {
public:
    vector<vector<int>> *output = new vector<vector<int>>();
    int k;

    void backtrack(int first, vector<int> &curr, vector<int> &nums) {
        if (curr.size() == k) {
            output->push_back(curr);
            return;
        }
        for (int i = first; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(i + 1, curr, nums);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        for (k = 0; k <= nums.size(); k++)
            backtrack(0, *new vector<int>(), nums);
        return *output;
    }
};
