#include <vector>
#include <algorithm>
#include <iostream>

using std::endl;
using std::cout;
using std::find;
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (auto beg = nums.begin(); beg != nums.end(); ++beg)
        {
            auto start = beg;
            auto iter = find(++start, nums.end(), target - *beg);
            if ((iter != beg) && (iter != nums.end()))
            {
                return vector<int>{beg - nums.begin(), iter - nums.begin()};
            }
        }
        return vector<int>{0,0}; // should never go here
    }
};

int main()
{
    Solution solt;
    vector<int> ivec{3,3};
    vector<int> jvec = solt.twoSum(ivec, 6);
    cout << jvec[0] << " " << jvec[1] << endl;
    return 0;
}
