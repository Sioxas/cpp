/**
 * 13. Roman to Integer
 *
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */

#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

int romanToInt(string s) {
    map<char,int> roman;
    roman['I']=1;
    roman['V']=5;
    roman['X']=10;
    roman['L']=50;
    roman['C']=100;
    roman['D']=500;
    roman['M']=1000;
    int result=0;
    for(string::iterator it=s.end()-1;(it+1)!=s.begin();--it){
        if((*it=='I'||*it=='X'||*it=='C')&&(it!=s.end()-1)&&(roman[*it]<roman[*(it+1)])){
            result-=roman[*it];
        }else{
            result+=roman[*it];
        }
    }
    return result;
}

int main() {

    cout<<romanToInt("DCXXI")<<endl;//621
    system("pause");

    return 0;
}