#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[]) {
    vector<int> stu;
    string ss;
    cin >> ss;
    stringstream sstr(ss);
    string token;
    while (getline(sstr, token, ',')) {
        stu.push_back(stoi(token));
    }
    size_t n = stu.size();
    if(n<=2){
        cout << 0 << endl;
        return 0;
    }
    vector<int> value(n + 1);
    value[0] = 0;
    value[1] = 0;
    for (size_t i = 2; i < value.size();++i){
        value[i] = min(stu[i - 1] + value[i - 1], stu[i - 2] + value[i - 2]);
    }
    cout << *(value.end() - 1) << endl;
    return 0;
}
