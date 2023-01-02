#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
    int removeDuplicates2(std::vector<int> &nums)
    {
        int i = 0, t = 0;
        while (i < nums.size() - 1)
        {
            if (nums[i] == nums[i + 1])
            {
                nums.erase(nums.begin() + (i + 1));
                ++t;
            }
            else
            {
                ++i;
            }
        }
        std::cout << t;
        return nums.size();
    }
    int removeDuplicates(std::vector<int> &nums)
    {
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    sol.removeDuplicates(nums);
    return 0;
}