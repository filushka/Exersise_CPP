#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    string add( string num1, string num2 ) {
        string res;

        auto len1 = num1.length();
        auto len2 = num2.length();

        auto len = min( len1, len2 );

        auto res_len =  max( len1, len2 );
        for( auto i = 0; i <= res_len; i++ )
            res.append( 1, '0' );


        for( auto i = 0; i < len; i++ ){

            auto tmp = res[max( len1, len2 ) - i] - '0' + num1[len1 - 1 - i] - '0' + num2[len2 - 1 - i] - '0';
            res[ res_len  - i] = tmp%10 + '0';
            res[ res_len - 1 -  i ] = tmp/10 + '0';
        }

        auto tmp = 0;

        if( len1 != len2 ) {


            if( len == len1 ) {
                for( auto i = len2 - len1 - 1; i > 0; i-- ) {
                    tmp = res[ i + 1 ] - '0' + num2[ i ] - '0';
                    res[i + 1] = tmp%10 + '0';
                    res[i] = tmp/10 + '0';
                }

                tmp = res[ 1 ] - '0' + num2[ 0 ] - '0';
            }


            if( len == len2 ) {
                for( auto i = len1 - len2 - 1; i > 0; i--  ) {
                    tmp = res[ i + 1 ] - '0' + num1[ i ] - '0';
                    res[i + 1] = tmp%10 + '0';
                    res[i] = tmp/10 + '0' ;
                }

                tmp = res[ 1 ] - '0' + num1[ 0 ] - '0';
            }

            res[1] = tmp%10 + '0';
            res[0] = tmp/10 + '0';
        }

        while( res[ 0 ] - '0' == 0 )
            res.erase( 0, 1 );

        return res;
    }
    string multiply(string num1, string num2) {
        string res = "0";
        auto len1 = num1.length();
        auto len2 = num2.length();

        if( len1 == 0 )
            return num1;

        if( len2 == 0 )
            return num2;

        // Count and remove zeroes at the end of num1 and num2
        auto k = len1 - 1;
        auto zeroes1 = 0;
        auto zeroes2 = 0;

        while( num1[ k ] - '0' == 0 ){
            num1.erase( num1.begin() + k );
            --k;
            ++zeroes1;

            if( num1.empty() )
                return "0";
        }

        k = len2 - 1;
        while( num2[ k ] - '0' == 0 ){
            num2.erase( num2.begin() + k );
            --k;
            ++zeroes2;

            if( num2.empty() )
                return "0";

        }

        // Update length
        len1 = num1.length();
        len2 = num2.length();

        string tmp_num2 = num2;

        // start from first non zero at the end of num1
        for( auto i = len1 - 1; i > 0; i-- ){

            if( num1[i] - '0' != 0 ){

                for( int j = 0; j < num1[i] - '0'; j++ )
                    res = add( res, tmp_num2 );
            }

            tmp_num2.append( "0" );
        }

        for( int j = 0; j < num1[0] - '0'; j++ )
            res = add( res, tmp_num2 );

        for( auto i = 0; i < zeroes1+zeroes2; i++ )
            res.append( "0" );

        return res;
    }
};

int main()
{
    Solution s;
    //cout << s.add( "1234", "1435670"  ) << endl;
    //cout << s.add(  "1435670", "1234"  ) << endl;

    //cout << s.add( "13680", "456" );

    cout << s.multiply( "9133", "0" ) << endl;
    cout << s.multiply( "408", "5" ) << endl;
    cout <<  s.multiply( "123", "456" ) << endl; // 56088
    return 0;
}
