/**
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 * For example:
 *
 *     1 -> A
 *     2 -> B
 *     3 -> C
 *     ...
 *     26 -> Z
 *     27 -> AA
 *     28 -> AB
 */
#include <iostream>
#include <cstdlib>

using namespace std;

string convertToTitle(int n) {
    int N=n;
    char tmp;
    string result;
    while(N>26){
        if(N%26==0){
            tmp='Z';
            N=N/26-1;
        }else{
            tmp='A'+(N%26)-1;
            N=N/26;
        }

        result.insert(result.begin(),tmp);
    }
    tmp='A'+N-1;
    result.insert(result.begin(),tmp);
    return result;
}

int main() {
    int x;
    while(cin>>x){

        cout << convertToTitle(x) << endl;
    }
//    cout<<52%26<<endl;
    system("pause");
    return 0;
}