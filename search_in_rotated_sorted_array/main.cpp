#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<int>::iterator find_lower_bound (vector<int>::iterator first, vector<int>::iterator last, const int& val)
    {
      vector<int>::iterator it;
      iterator_traits<vector<int>::iterator>::difference_type count, step;
      count = distance(first,last);
      while (count>0)
      {
        it = first; step=count/2; advance (it,step);
        if (*it<val) {                 // or: if (comp(*it,val)), for version (2)
          first=++it;
          count-=step+1;
        }
        else count=step;
      }
      return first;
    }

    int search(vector<int>& nums, int target) {
        auto res = -1;
        auto len = nums.size();

        if( len == 0 )
            return res;

        if( len == 1 )
            return nums[0]^target ? -1 : 0;

        if( len == 2 ) {
            if( !(nums[0]^target) )
                return 0;
            if( !(nums[1]^target))
                return 1;
            return -1;
        }

        // Array is sorted
        if( nums[0] < nums[len-1] ){
            res = find_lower_bound( nums.begin(), nums.end(), target ) - nums.begin();
            if(  *(nums.begin() + res) != target )
                res = -1;
        }
        else { //nums[0] > nums[len-1]
            // find pivot
            auto x0 = 0;
            auto x1 = ( len - 1 )/2;
            auto x2 = len -1 ;
            auto pivot = 0;
/*
            while( nums[ x1 ] > nums[ len-1 ]) {
                if( x0 == x2 || x0 == x1 )
                    break;
                if( nums[ x1 ] > nums[ x2 ] ) {
                    auto tmp = x0;
                    x0 = x1;
                    x1 = (x2 - tmp ) / 2 + tmp;
                }
                else{
                    auto tmp = x1;
                    x1 = (tmp - x0) / 2 + x0;
                    x2 = tmp;
                }
            }

            pivot = x1;
            while( nums[ pivot ] < nums[len-1] )
                --pivot;
*/

            while( nums[ x1 ] > nums[ len-1 ]) {
                if( x0 == x1 - 1 && x0 == x2 - 2 ){
                    if( nums[x0] < nums[x1] && nums[x1] < nums[x2] )
                        pivot = x2;

                    if( nums[x0] < nums[x1] && nums[x1] > nums[x2])
                        pivot = x1;

                    if( nums[x0] > nums[x1] && nums[x1] < nums[x2])
                        pivot = x0;

                    if( nums[x0] < nums[x1] && nums[x1] < nums[x2])
                        pivot = x2;

                    break;
                }
                if( nums[ x1 ] > nums[ x2 ] ) {
                    auto tmp = x0;
                    x0 = x1;
                    x1 = (x2 - tmp ) / 2 + tmp;
                }
                else{
                    auto tmp = x1;
                    x1 = (tmp - x0) / 2 + x0;
                    x2 = tmp;
                }
            }

            pivot = x1;

            while( nums[ pivot ] < nums[len-1] )
                --pivot;


            if( target < nums[0] ) {
                //if(binary_search( nums.begin() + pivot + 1, nums.end(), target ))
                //    res = lower_bound( nums.begin() + pivot +1, nums.end(), target ) - nums.begin();

                res = find_lower_bound( nums.begin() + pivot + 1, nums.end(), target ) - nums.begin();
                if( *(nums.begin() + res) != target )
                    res = -1;
            }
            else {
                //if(binary_search( nums.begin(), nums.begin() + pivot, target ))
                //    res = lower_bound( nums.begin(), nums.begin() + pivot, target ) - nums.begin();

                res = find_lower_bound( nums.begin(), nums.begin() + pivot, target ) - nums.begin();
                if( *(nums.begin() + res) != target )
                    res = -1;
            }

        }

        return res;
    }
};

int main()
{
    vector<int> nums = { 4,5,6,7,8,1,2,3 };
    Solution s;
    cout << s.search(  nums, 8 ) << endl;
    return 0;
}
