//#pragma once
//
//#include<iostream>
//#include <algorithm>
//#include <cctype>
//#include <string>
//
////空格
//inline  bool space(char c){
//	return isspace(c);
//}
//
////非空格
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
//		//找到单词开始
//		i = find_if(i, str.end(), not_space);
//		//找到单词结束
//		iter j = find_if(i, str.end(), space);
//
//		if(i != str.end())
//			*os++ = std::string(i, j);
//		i = j;
//	}
//}