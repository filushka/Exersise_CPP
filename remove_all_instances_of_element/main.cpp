#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int size = nums.size();

        for(int i = 0; i < size; i++ ){
            if( nums[i] == val ){
                nums.erase( nums.begin() + i );
                --i;
                --size;
            }
        }

        return size;
    }
};

int main()
{
    vector<int> nums {1,1,1,2,2,2,3,3,3};
    Solution s;
    cout << s.removeElement( nums, 3 )  << endl;
    return 0;
}
