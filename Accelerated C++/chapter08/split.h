//#pragma once
//
//#include<iostream>
//#include <algorithm>
//#include <cctype>
//#include <string>
//
////�ո�
//inline  bool space(char c){
//	return isspace(c);
//}
//
////�ǿո�
//inline bool not_space(char c){
//	return !isspace(c);
//}
//
//template <class Out> 
//void split(const std::string& str, Out os){
//	typedef string::const_iterator iter;
//	iter i = str.begin();
//	
//	while(i != str.end()){
//		//�ҵ����ʿ�ʼ
//		i = find_if(i, str.end(), not_space);
//		//�ҵ����ʽ���
//		iter j = find_if(i, str.end(), space);
//
//		if(i != str.end())
//			*os++ = std::string(i, j);
//		i = j;
//	}
//}