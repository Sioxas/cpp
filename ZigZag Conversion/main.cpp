/**
 * 6. ZigZag Conversion
 * https://leetcode.com/problems/zigzag-conversion/description/
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given 
 * number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * Example 2:
 * Input: s = "PAYPALISHIRING", numRows = 4
 *             
 *             
 * Output:    "PINALSIGYAHRPI"
 *             
 * Explanation:
 * P     I     N
 * A   L S   I G
 * Y A   H R
 * P     I
 * 
 */

#include <iostream>
#include <string>
using namespace std;

string convert(string s, int numRows)
{
    if(numRows<=1)
        return s;
    const size_t cyc_length = numRows * 2 - 2;
    const size_t n = s.size();
    const size_t cyc_mid = numRows - 1;
    string c = "";
    c.reserve(n);
    for (size_t i = 0; i < numRows; i++)
    {
        if (i == 0)
        {
            for (size_t j = 0; j < n; j += cyc_length)
            {
                c += s[j];
            }
        }
        else if (i == cyc_mid)
        {
            for (size_t j = cyc_mid; j < n; j += cyc_length)
            {
                c += s[j];
            }
        }
        else
        {
            const size_t offset = cyc_mid - i;
            for (size_t j = i; j < n; j += cyc_length)
            {
                c += s[j];
                const size_t t = j + 2 * offset;
                if (t < n)
                {
                    c += s[t];
                }
            }
        }
    }
    return c;
}

int main()
{
    string s = convert("A",1);
    cout << s << endl;
    return 0;
}

/**
 * Result:
 * Runtime: 16 ms
 * 
 * Your runtime beats 96.99 % of cpp submissions.
 * 
 */