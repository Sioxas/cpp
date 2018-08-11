/**
 * 171. Excel Sheet Column Number  QuestionEditorial Solution  My Submissions
 *
 * Difficulty: Easy
 *
 * Related to question Excel Sheet Column Title
 *
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 *
 * For example:
 *
 *     A -> 1
 *     B -> 2
 *     C -> 3
 *     ...
 *     Z -> 26
 *     AA -> 27
 *     AB -> 28
 */

#include <iostream>
#include <cmath>

using namespace std;

int titleToNumber(string s) {
    int result=0;
    for(int i=s.length()-1,j=0;i>=0;i--,j++){
        result+=(s[i]-'@')*pow(26,j)+0.5;
        //pow使用泰勒公式来计算幂
        //26^1=25.99999999....精度很高....
        //double类型转int为向下取整，+0.5后可以转为四舍五入方式
    }
    return result;
}

int main() {
    string s;
    while(cin>>s){

        cout<<titleToNumber(s)<<endl;
    }
    return 0;
}