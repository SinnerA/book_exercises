//#include<iostream>
//#include<string>
//#include<vector>
//
//using namespace std;
//
////判断单词是否小写
//bool is_lower(const string& s){
//	for(string::const_iterator iter = s.begin(); iter != s.end(); ++iter){
//		if(!islower(*iter)){
//			return false;
//		}
//	}
//	return true;
//}
//
////输出
//void print_string_vector(const vector<string>& vs){
//	for(vector<string>::const_iterator iter = vs.begin(); iter != vs.end(); ++iter){
//		cout << *iter << " ";
//	}
//}
//
//int main(){
//	vector<string> lowers, uppers;
//	string word;
//	while(cin >> word){
//		if(is_lower(word)){
//			lowers.push_back(word);
//		} else {
//			uppers.push_back(word);
//		}
//	}
//
//	print_string_vector(lowers);
//	print_string_vector(uppers);
//	cout << endl;
//
//	return 0;
//}