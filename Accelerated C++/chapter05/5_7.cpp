//#include<iostream>
//#include<string>
//#include<vector>
//#include<list>
//
//using namespace std;
//
//string::size_type width(const vector<string>& v){
//	string::size_type maxlength = 0;
//	for(string::size_type i = 0; i != v.size(); i++){
//		maxlength = max(v[i].size(), maxlength);
//	}
//	return maxlength;
//}
//
//vector<string> frame(const vector<string>& v){
//	vector<string> ret;
//	string::size_type maxlen = width(v);
//	string boder(maxlen + 4, '*');
//
//	//ио╠ъ©Р
//	ret.push_back(boder);
//
//	for(vector<string>::size_type i = 0; i != v.size(); ++i){
//		string s= "* " + v[i] + string(maxlen - v[i].size(), ' ') + "*";
//		ret.push_back(s);
//	}
//
//	//об╠ъ©Р
//	ret.push_back(boder);
//	return ret;
//}
//
//int main(){
//	vector<string> ret, v;
//	ret = frame(v);
//
//	for(vector<string>::const_iterator iter = ret.begin(); iter != ret.end(); ++iter){
//		cout << *iter << endl;
//	}
//
//	return 0;
//}