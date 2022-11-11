#include <vector>
#include <algorithm>

using std::vector;

class Solution {
private:
    static bool sortIntervalsComp(vector<int> &v1, vector<int> &v2) {
        return v1[0] < v2[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end(), sortIntervalsComp);
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i][1] >= intervals[i + 1][0]) {
                intervals[i][0] = std::min(intervals[i][0], intervals[i + 1][0]);
                intervals[i][1] = std::max(intervals[i][1], intervals[i + 1][1]);
                intervals.erase(intervals.begin() + i + 1);
                i--;
            }
        }
        return intervals;
    }
};

