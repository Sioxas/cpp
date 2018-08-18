/**
8. String to Integer (atoi)
https://leetcode.com/problems/string-to-integer-atoi/description/

Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until
the first non-whitespace character is found. Then, starting from this character,
takes an optional initial plus or minus sign followed by as many numerical
digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral
number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid
integral number, or if no such sequence exists because either str is empty or it
contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within
the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical value is
out of the range of representable values, INT_MAX (2^31 − 1) or INT_MIN (−2^31)
is returned.

Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a
numerical digit. Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical
             digit or a +/- sign. Therefore no valid conversion could be
performed. Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed
integer. Thefore INT_MIN (−2^31) is returned.

 */

#include <iostream>
#include <string>
using namespace std;

int myAtoi(string str) {
    bool is_positive = true;
    string::const_iterator i = str.begin();
    while (*i == ' ' && i != str.end())
        i++;
    if (*i == '-') {
        is_positive = false;
        i++;
    } else if (*i == '+') {
        i++;
    }
    while (i != str.end() && *i == '0')
        i++;
    int t;
    long long int result = 0;
    while (i != str.end()) {
        t = *i - '0';
        if (t >= 0 && t <= 9) {
            result = result * 10 + t;
            if (result > (long long int)(INT32_MAX) + 1)
                break;
            i++;
        } else {
            break;
        }
    }
    if (is_positive && result > INT32_MAX)
        return INT32_MAX;
    if (!is_positive && result > (long long int)(INT32_MAX) + 1)
        return INT32_MIN;
    return is_positive ? result : -result;
}

int main(int argc, char const *argv[]) {
    cout << myAtoi("42") << endl;
    cout << myAtoi("  -42") << endl;
    cout << myAtoi("  -0000042") << endl;
    cout << myAtoi("4193 with words") << endl;
    cout << myAtoi("words and 987") << endl;
    cout << myAtoi("-91283472332") << endl;
    cout << myAtoi("-6147483648") << endl;
    cout << myAtoi("6147483648") << endl;
    return 0;
}
