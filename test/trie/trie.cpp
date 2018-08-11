#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct TrieNode {
	wchar_t data;
	vector<TrieNode*> children;
	bool isTail;
	TrieNode(wchar_t x) :data(x), children(NULL),isTail(false) {
	}
	TrieNode(wchar_t x,bool y) :data(x), children(NULL), isTail(y) {
	}
	TrieNode *findNode(wchar_t ch) {
		for (TrieNode* item : children) {
			if (item->data == ch)return item;
		}
		return nullptr;
	}
	void insert(wchar_t ch) {
		children.push_back(new TrieNode(ch));
	}
	void insert(wchar_t ch,bool t) {
		children.push_back(new TrieNode(ch,t));
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode('#');
		counts = 0;
	}
	bool insert(wstring s) {
		TrieNode *t = root;
		TrieNode *temp;
		bool exist = true;
		for (wstring::iterator i = s.begin(); i != s.end(); ++i) {
			if (exist && (temp = t->findNode(*i))) {
				if (i == (s.end() - 1)) {
					if (temp->isTail) 
						return false;
					else {
						temp->isTail = true;
						counts++;
						return true;
					}
				}
				t = temp;
			}
			else {
				exist = false;
				if (i == (s.end() - 1)) {
					t->insert(*i, true);
					counts++;
					return true;
				}
				else {
					t->insert(*i);
					t = *(t->children.end() - 1);
				}
			}
		}
	}
	bool isExist(wstring s) {
		TrieNode *t = root;
		for (wstring::iterator i = s.begin(); i != s.end(); ++i) {
			if (t = t->findNode(*i)) {
				if (i == (s.end() - 1) && t->isTail) return true;
			}
			else return false;
		}
		return false;
	}
	vector<wstring> matchPrefix(wstring prefix) {
		if (prefix.size() == 0)return{};
		TrieNode *t = root;
		for (wstring::iterator i = prefix.begin(); i != prefix.end(); ++i) {
			if (!(t = t->findNode(*i))) return {};
		}
		bucket.clear();
		stick.clear();
		prefix.pop_back();
		stick = prefix;
		traverse(t);
		return bucket;
	}
	unsigned int getCounts() {
		return counts;
	}
	vector<wstring> dump() {
		bucket.clear();
		stick.clear();
		for (vector<TrieNode*>::iterator i = root->children.begin(); i != root->children.end(); ++i) {
			traverse(*i);
			stick.clear();
		}
		return bucket;
	}
private:
	unsigned int counts;
	TrieNode *root;
	vector<wstring> bucket;
	wstring stick;
	void traverse(TrieNode *t) {
		stick += t->data;
		wstring recover = stick;
		if (t->isTail)bucket.push_back(stick);
		for (vector<TrieNode*>::iterator i = t->children.begin(); i != t->children.end(); ++i) {
			traverse(*i);
			stick=recover;
		}
	}
};

int main() {
	std::wcout.imbue(std::locale("chs"));
	Trie dict;
	dict.insert(L"shopp");
	dict.insert(L"hello");
	dict.insert(L"world");
	dict.insert(L"word");
	dict.insert(L"shop");
	dict.insert(L"androidkasdfdasghjkhgfdsfgf");
	dict.insert(L"and");
	dict.insert(L"哈哈哈");
	dict.insert(L"哈哈哈嘿嘿额hi");
	dict.insert(L"and红了樱桃");
	dict.insert(L"绿了吧唧");
	cout << "正在读取词库...";
	wifstream in("D:/data/dict.txt");
	in.imbue(std::locale("chs"));
	wcout.imbue(std::locale("chs"));
	if (!in.is_open()) {
		cout << "Error open file!" << endl;
		return 0;
	}
	wstring buffer;
	while (!in.eof()) {
		getline(in, buffer);
		dict.insert(buffer.substr(0,buffer.find_first_of('[')));
		//dict.insert(buffer);
	}
	in.close();

	cout <<"共"<< dict.getCounts() <<"个单词"<< endl;
	/*vector<wstring> bucket = dict.dump();
	for (wstring s : bucket) {
		wcout << s << endl;
	}*/
	wstring x;
	cout << "输入单词前缀:";
	while (wcin >> x) {
		vector<wstring> result = dict.matchPrefix(x);
		for (wstring s : result) {
			wcout << s << endl;
		}
		cout << "以";
		wcout << x;
		cout<< "为开头的单词共" << result.size() << "个" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "输入单词前缀:";
	}
	
	system("pause");
	return 0;
}