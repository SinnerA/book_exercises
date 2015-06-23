//#include"pics.h"
//#include<algorithm>
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
//vector<string> frame(const vector<string>& v){
//	vector<string> ret;
//	string::size_type maxlen = width(v);
//	string boder(maxlen + 4, '*');
//
//	//上边框
//	ret.push_back(boder);
//
//	for(vector<string>::size_type i = 0; i != v.size(); ++i){
//		string s= "* " + v[i] + string(maxlen - v[i].size(), ' ') + "*";
//		ret.push_back(s);
//	}
//
//	//下边框
//	ret.push_back(boder);
//	return ret;
//}
//
//vector<string> vcat(const vector<string>& top, const vector<string>& bottom){
//	vector<string> ret = top;
//	for(vector<string>::const_iterator iter = bottom.begin(); iter != bottom.end(); ++iter){
//		ret.push_back(*iter);
//	}
//	
//	//ret.insert(ret.end(), bottom.begin(), bottom.end());//同样效果
//	return ret;
//}
//
//vector<string> hcat(const vector<string>& left, const vector<string>& right){
//	vector<string> ret;
//	vector<string>::size_type i, j = 0;
//	string::size_type maxlen = width(left);
//
//	while(i != left.size() || j != right.size()){
//		string s;
//		if(i != left.size()){
//			s = left[i++];
//		}
//
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