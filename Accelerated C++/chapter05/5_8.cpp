//#include<iostream>
//#include<string>
//#include<vector>
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
//vector<string> hcat(const vector<string>& left, const vector<string>& right){
//	vector<string> ret;
//	vector<string>::size_type i = 0, j = 0;
//	string::size_type maxlen = width(left);
//
//	string s;
//	while(i != left.size() || j != right.size()){
//		//string s;
//		if(i != left.size()){
//			s = left[i++];
//		}
//
//		if(s.size() > maxlen)
//			s.clear();
//		s += string(maxlen - s.size() + 1, ' ');
//
//		if(j != right.size()){
//			s += right[j++];
//		}
//
//		ret.push_back(s);
//	}
//
//	return ret;
//}
//
//int main(){
//	vector<string> left, right;
//	left.push_back("*");
//	left.push_back("**");
//	left.push_back("***");
//	left.push_back("******");
//
//	right.push_back("---");
//	right.push_back("---");
//	right.push_back("---");
//	right.push_back("---");
//	right.push_back("------");
//
//	vector<string> ret = hcat(left, right);
//
//	for(vector<string>::const_iterator iter = ret.begin(); iter != ret.end(); ++iter){
//		cout << *iter << endl;
//	}
//	return 0;
//}