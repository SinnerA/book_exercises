//#pragma once
//
//#include<algorithm>
//#include<string>
//#include<iostream>
//
//#include"list.hpp"
//
//using std::string;
//
//inline bool space(char c){
//	return isspace(c);
//}
//
//inline bool not_space(char c){
//	return !isspace(c);
//}
//
//list<string> split(const string& str){
//	list<string> ret;
//	string::const_iterator i, j = str.begin();
//
//	while(i != str.end()){
//		i = find_if(i, str.end(), not_space);
//
//		j = find_if(i, str.end(), space);
//
//		if(i != str.end()){
//			ret = cons(string(i, j), ret);
//		}
//		i = j;
//	}
//	return reverse(ret);
//} 
