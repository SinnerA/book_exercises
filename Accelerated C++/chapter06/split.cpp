//#include<iostream>
//#include<string>
//#include<vector>
//#include<cctype>
//#include<algorithm>
//#include"chapter5\split.h"
//
//using namespace std;
//
////�ո�
//bool space(char c){
//	return isspace(c);
//}
//
////�ǿո�
//bool not_space(char c){
//	return !isspace(c);
//}
//
//vector<string> split(const string& s){
//
//	vector<string> ret;
//	string s;
//
//	typedef string::const_iterator iter;
//	iter i = s.begin();
//	while(i != s.end()){
//		//�ҵ��ʿ�ͷ
//		i = find_if(i, s.end(), not_space);
//		//�ҵ��ʽ�β
//		iter j = find_if(i, s.end(), space);
//
//		if(i != s.end())
//			ret.push_back(string(i, j));
//		i = j;
//	}
//	return ret;
//}