#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if( size <= 1 )
            return size;

        int prev = nums[0];

        for(int i = 1; i < size; i++ ) {
           if( nums[i] == prev ){
               --size;
               nums.erase( nums.begin() + i );
               --i;
           }
           else
               prev = nums[i];
        }

        return size;
    }
};

int main()
{
    vector<int> nums {1,1,1,2,2,2,3,3,3};
    Solution s;
    cout << s.removeDuplicates( nums ) << endl;
    return 0;
}
