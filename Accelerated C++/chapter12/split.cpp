//#include"split.h"
//#include"Str.hpp"
//
//using namespace std;
//
//vector<Str> split(const Str& s){
//
//	vector<Str> ret;
//	typedef Str::size_type str_size;
//	str_size i = 0;
//
//	while(i != s.size()){
//		
//		//�ҵ����ʿ�ʼλ��
//		while(i != s.size() && isspace(s[i]))
//			++i;
//
//		str_size j = i;
//		//�ҵ����ʽ���λ��
//		while(j != s.size() && !isspace(s[j]))
//			++j;
//
//		//�ҵ�һ�����ʣ����洢
//		if(i != j){
//			ret.push_back(s.substr(i, j-i));
//		    i = j;
//		}
//	}
//
//	return ret;
//}