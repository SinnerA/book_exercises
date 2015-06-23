//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//const string ascenders = "bdfhklt";
//const string descender = "gjpqy";
//
//
//bool has_chars(const string& word, const string& chars){
//	for(string::const_iterator i = word.begin(); i != word.end(); ++i){
//		for(string::const_iterator j = chars.begin(); j != chars.end(); ++j){
//			if(*i == *j)
//				return true;
//		}
//	}
//	return false;
//}
//
//int main(){
//	vector<string> has_asc_or_dsc;
//	string longest_word_without_asc_or_dsc;
//	string s;
//
//	while(cin >> s){
//		cin >> s;
//		if(has_chars(s,ascenders) || has_chars(s,descender)){
//			has_asc_or_dsc.push_back(s);
//		} else if(longest_word_without_asc_or_dsc.size() < s.size()){
//			longest_word_without_asc_or_dsc = s;
//		}
//	}
//
//	cout << "\nHas ascenders or descenders: " << endl;
//	for(vector<string>::const_iterator iter = has_asc_or_dsc.begin(); iter != has_asc_or_dsc.end(); ++iter){
//		cout << *iter << endl;
//	}
//
//	cout << "The longest word without ascenders or descender is: " << longest_word_without_asc_or_dsc << endl;
//	
//	return 0;
//}