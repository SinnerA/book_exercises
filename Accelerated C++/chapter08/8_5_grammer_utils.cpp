//#include<iostream>
//#include<iterator>
//
//#include"8_5_grammer_utils.hpp"
//#include"split.h"
//
//using namespace std;
//
////从一个特定的输入流中读入文法
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
////检查单词是否被括号括起
//bool bracketed(const string& s){
//	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
//}
//
////返回[0,n)的一个随机整数
//int nrand(int n){
//	if(n <= 0 || n > RAND_MAX)
//		throw domain_error("Argument to nrand is out of range!");
//	
//	//存储桶大小
//	const int bucket_size = RAND_MAX / n;
//	
//	int r;//存储桶的编号
//	do
//	  r = rand() / bucket_size;
//	while(r >= n);
//
//	return r;
//}