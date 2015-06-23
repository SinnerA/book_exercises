//#include<algorithm>
//#include<vector>
//
//#include"pics.h"
//#include"Str.hpp"
//
//using namespace std;
//
//Str::size_type width(const vector<Str>& v){
//	Str::size_type maxlength = 0;
//	for(Str::size_type i = 0; i != v.size(); i++){
//		maxlength = max(v[i].size(), maxlength);
//	}
//	return maxlength;
//}
//
//vector<Str> frame(const vector<Str>& v){
//	vector<Str> ret;
//	Str::size_type maxlen = width(v);
//	Str boder(maxlen + 4, '*');
//
//	//上边框
//	ret.push_back(boder);
//
//	for(vector<Str>::size_type i = 0; i != v.size(); ++i){
//		Str s= "* " + v[i] + Str(maxlen - v[i].size(), ' ') + "*";
//		ret.push_back(s);
//	}
//
//	//下边框
//	ret.push_back(boder);
//	return ret;
//}
//
//vector<Str> vcat(const vector<Str>& top, const vector<Str>& bottom){
//	vector<Str> ret = top;
//	for(vector<Str>::const_iterator iter = bottom.begin(); iter != bottom.end(); ++iter){
//		ret.push_back(*iter);
//	}
//	
//	//ret.insert(ret.end(), bottom.begin(), bottom.end());//同样效果
//	return ret;
//}
//
//vector<Str> hcat(const vector<Str>& left, const vector<Str>& right){
//	vector<Str> ret;
//	vector<Str>::size_type i, j = 0;
//	Str::size_type maxlen = width(left);
//
//	while(i != left.size() || j != right.size()){
//		Str s;
//		if(i != left.size()){
//			s = left[i++];
//		}
//
//		s += Str(maxlen - s.size() + 1, ' ');
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