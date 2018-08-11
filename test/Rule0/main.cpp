#include <iostream>
#include <map>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

map<string,string> attr;

void init(){
	ifstream in;
	in.open("in.txt",ios::in);
	if(infile.fail())
		cout << "error open!" << endl;
	string a,b;
	while(!in.eof()){
		in>>a>>b;
		attr.insert(pair<string,string>(a,b));
	}
}

int main(int argc, char** argv) {
	
	
	cout<<attr[1]<<endl;
	return 0;
}
