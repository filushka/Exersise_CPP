#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        auto len_needle = needle.length();
        auto len_haystack = haystack.length();
        int res = -1;


        if( len_needle && len_haystack ) {
            if( len_needle > len_haystack )
                return res;
            else if( len_needle == len_haystack ) {
                if( !haystack.compare( needle ) )
                    res = 0;
            } else {

                if( !len_needle )
                    res = 0;
                else{

                    for( auto i = 0; i <= len_haystack - len_needle; i++ ) {
                        if( haystack.substr( i, len_needle ).compare( needle ) == 0 ) {
                            res = i;
                            break;
                        }
                    }
                }
            }
        }
        else if( len_needle && !len_haystack )
            res = -1;
        else if( !len_needle && len_haystack )
            res = 0;
        else if( !len_needle && !len_haystack )
            res = 0;

        return res;
    }
};

int main()
{
    Solution s;
    cout << s.strStr( "mississippi", "pi" ) << endl;
    return 0;
}
