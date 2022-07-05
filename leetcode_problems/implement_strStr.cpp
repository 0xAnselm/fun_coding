#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty()) {return 0;}
        for (int i = 0; i < haystack.length(); ++i)
        {
            if (needle == haystack.substr(i, needle.length()))
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    string haystack = "mississippi";
    string needle = "issi";
    Solution sol;
    cout << sol.strStr(haystack, needle);
    return 0;
}