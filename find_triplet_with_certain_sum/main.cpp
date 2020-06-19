#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        auto len = nums.size();

        for( auto i = 0 ; i < len; i++ ){
            for( auto j = i + 1; j < len; j++ ){
                for( auto k = j + 1; k < len; k++) {
                    for( auto l = k + 1; l < len; l++) {

                        if( nums[i] + nums[j] + nums[k] + nums[l] == target ) {
                            //vector<int> v;
                            //v.insert( v.begin(), nums[i] );
                            //v.insert( v.begin() + 1, nums[j] );
                            //v.insert( v.begin() + 2, nums[k] );
                            //v.insert( v.begin() + 3, nums[l] );

                            int myints[] = {nums[i], nums[j] , nums[k], nums[l] };
                            std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );

                            sort( v.begin(), v.end() );
                            res.insert( res.end(), v );
                        }
                    }
                }
            }
        }

        sort( res.begin(), res.end() );

        // remove duplicates
        auto res_len = res.size();
        auto i = 1;

        if( res_len > 0 ) {
            while( i < res_len ) {
                if( res[i] == res[i-1] ) {
                    res.erase( res.begin() + i );
                    --res_len;
                }
                else
                    ++i;
            }
        }

        for( auto i : res )
           cout << i[0] << "," << i[1] << "," << i[2] << "," << i[3]<< endl;


        return res;
    }
};

int main()
{
    vector<int> nums = {-1,2,2,-5,0,-1,4 };
 //{};//{ -5,5,4,-3,0,0,4,-2 }; //{ -5,-4,-3,-2,-1,0,0,1,2,3,4,5 }; // { 1,0,-1,0,-2,2 };//{ -3,-2,-1,0,0,1,2,3 };
    Solution s;
    s.fourSum( nums, 3 );
    return 0;
}
