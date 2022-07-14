#include <vector>
#include <iostream>

class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        if (target < nums[0]) return 0;
        if (target > nums.back()) return nums.size();
        if (nums.size() == 1 && target == nums[0]) return 0;
        return recursiveSearch(nums, target, l, r);
    }

    int recursiveSearch(std::vector<int> &nums, int target, int l, int r)
    {
        int m = (l + r) / 2;
        if (l >= r) {
            return m+1;
        }
        if (target < nums[m])
        {
            return recursiveSearch(nums, target, 0, m - 1);
        }
        else if (target > nums[m])
        {
            return recursiveSearch(nums, target, m + 1, r);
        }
        else if (target == nums[m])
        {
            return m;
        }
        return -1;
    }
};

int main()
{
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 7;
    Solution sol;
    std::cout << sol.searchInsert(nums, target);
    return 0;
}