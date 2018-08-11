#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	wifstream in("D:/enwiktionary-latest-all-titles-ANSI");
	in.imbue(std::locale("chs"));
	wcout.imbue(std::locale("chs"));
	if (!in.is_open()) {
		cout << "Error open file!" << endl;
		return 0;
	}
	int i = 1000;
	wstring buffer;
	wstring::size_type position;
	wstring t;
	while (i--) {
		getline(in, buffer);
		t=buffer.substr(buffer.find_first_of('\t')+1);
		for (wchar_t c : t) {
			wcout << c << ' ';
		}
		cout << endl;
	}
	in.close();
	system("pause");
	return 0;
}