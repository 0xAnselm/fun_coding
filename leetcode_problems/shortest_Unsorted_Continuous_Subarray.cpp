#include <vector>
class Solution
{
public:
    int findUnsortedSubarray(std::vector<int> &nums)
    {
        int end = -1;
        int max = nums[0];
        int size = nums.size();
        for (int i = 1; i < size; i++)
        {
            if (max > nums[i])
            {            // the left value is greater then current value
                end = i; // mark that index with end
            }
            else
            {
                max = nums[i];
            }
        }

        int start = 0;
        int min = nums[size - 1];
        for (int i = size - 2; i >= 0; i--)
        {
            if (min < nums[i])
            {              // the right value is smaller then current value
                start = i; // mark that index with start
            }
            else
            {
                min = nums[i];
            }
        }
        if (end==start) {return 0;}
        return end - start + 1;
    }
};

int main()
{
    Solution sol;
    std::vector<int> test1 = {1, 2, 3, 4};
    sol.findUnsortedSubarray(test1);
    return 0;
}