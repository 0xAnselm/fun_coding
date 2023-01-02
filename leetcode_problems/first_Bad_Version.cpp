// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#include <iostream>

class Solution
{
public:
    bool isBadVersion(int version)
    {
        if (version == 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int binSearch(int l, int r)
    {
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (!isBadVersion(m))
            {
                l = m + 1;
            }
            else if (isBadVersion(m))
            {
                r = m - 1;
            }
            else
            {
                return m;
            }
        }
        return l;
    }

    int firstBadVersion(int n)
    {
        return binSearch(0, n);
    }
};

int main()
{
    Solution sol;
    std::cout << sol.firstBadVersion(5);
    return 0;
}
