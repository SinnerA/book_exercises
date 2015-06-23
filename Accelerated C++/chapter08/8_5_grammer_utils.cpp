//#include<iostream>
//#include<iterator>
//
//#include"8_5_grammer_utils.hpp"
//#include"split.h"
//
//using namespace std;
//
////��һ���ض����������ж����ķ�
//Grammer read_grammer(istream& in){
//	Grammer ret;
//	string line;
//
//	while(getline(in, line)){
//		vector<string> entry;
//		split(line, back_inserter(entry));
//
//		if(!entry.empty()){
//			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
//		}
//	}
//	return ret;
//}
//
////��鵥���Ƿ���������
//bool bracketed(const string& s){
//	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
//}
//
////����[0,n)��һ���������
//int nrand(int n){
//	if(n <= 0 || n > RAND_MAX)
//		throw domain_error("Argument to nrand is out of range!");
//	
//	//�洢Ͱ��С
//	const int bucket_size = RAND_MAX / n;
//	
//	int r;//�洢Ͱ�ı��
//	do
//	  r = rand() / bucket_size;
//	while(r >= n);
//
//	return r;
//}