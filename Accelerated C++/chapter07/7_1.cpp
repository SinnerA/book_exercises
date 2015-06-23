//#include<iostream>
//#include<string>
//#include<map>
//#include<vector>
//
//using namespace std;
//
//int main(){
//	map<int, vector<string> > words_by_freq;
//	map<string, int> counters;
//
//	string s;
//	while(cin >> s){
//		++counters[s];
//	}
//
//	for(map<string, int>::const_iterator i = counters.begin(); i != counters.end(); ++i){
//		words_by_freq[i->second].push_back(i->first);
//	}
//
//	for(map<int, vector<string> >::const_iterator i = words_by_freq.begin(); i != words_by_freq.end(); ++i){
//		cout << i->first << ": ";
//		vector<string> words = i->second;
//		for(vector<string>::const_iterator j = words.begin(); j != words.end(); ++j)
//			cout << *j << " ";
//		cout << endl;
//	}
//}