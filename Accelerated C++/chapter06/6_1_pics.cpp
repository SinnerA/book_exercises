//#include<iostream>
//#include<string>
//#include<iterator>
//#include"6_1_pics.h"
//
//using namespace std;
//
////vector中最长字符串的宽度
//string::size_type width(const vector<string>& v){
//	string::size_type maxlen = 0;
//	for(vector<string>::const_iterator i = v.begin(); i != v.end(); ++i){
//		maxlen = max(maxlen, (*i).size());
//	}
//	return maxlen;
//}
//
////为字符加边框
//vector<std::string> frame(const vector<string>& v){
//	vector<string> ret;
//	string::size_type maxlen = width(v);
//	string border(maxlen + 4, '*');
//
//	ret.push_back(border);
//	for(vector<string>::const_iterator i = v.begin(); i != v.end(); ++i){
//		string s = "* " + *i + string(maxlen - i->size(), ' ') + " *";
//		ret.push_back(s);
//	}
//	ret.push_back(border);
//	return ret;
//}
//
////纵向连接
//vector<string> vcat(const vector<string>& top, const vector<string>& bottom){
//	vector<string> ret = top;
//	copy(bottom.begin(), bottom.end(), back_inserter(ret));
//	//ret.insert(ret.end(), bottom.begin(), bottom.end());
//	return ret;
//}
//
////横向连接
//vector<string> hcat(const vector<string>& left, const vector<string>& right){
//	vector<string> ret;
//	string::size_type left_width = width(left) + 1;
//	vector<string>::const_iterator i = left.begin(), j = right.begin();
//
//	while(i != left.end() || j != right.end()){
//		string s;
//		if(i != left.end()){
//			s = *(i++);
//		}
//
//		s += string(left_width - s.size(), ' ');
//
//		if(j != right.end()){
//			s += *(j++);
//		}
//		ret.push_back(s);
//	}
//	return ret;
//}