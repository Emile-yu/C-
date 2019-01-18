#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

bool comp(string word, string pattern, int size) {
	map<char,char> m;
	set<char> s;
	for(int i=0;i<size;i++) {
		if(m.count(pattern[i])) {
			if(m[pattern[i]] != word[i]) return false;
		}else {
			if(s.count(word[i])) return false;
			m[pattern[i]] = word[i];
			s.insert(word[i]);
		}
	}
	return true;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
	vector<string> res;
	for(int i=0;i<words.size();i++) {
		if(words[i].length() == pattern.length()) {
			if(comp(words[i], pattern, pattern.length())) {
				res.push_back(words[i]);
			}			
		}
	}
	return res;
}
int main() {
	vector<string> v,res;
	string pattern = "abb";
	v.push_back("abc");
	v.push_back("deq");
	v.push_back("mee");
	v.push_back("aqq");
	v.push_back("dkd");
	v.push_back("ccc");
	
	res = findAndReplacePattern(v,pattern);
	
	for(int i =0; i<res.size();i++) {
		cout<<res[i]<<endl;
	}
	return 0;
}
