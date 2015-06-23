//#include<iostream>
//
//#include"Str.h"
//
//using namespace std;
//
//std::ostream& operator<<(std::ostream& os, const Str& s){
//	for(Str::size_type i = 0; i != s.size(); ++i){
//		os << s[i];
//	}
//	return os;
//}
//
//Str& operator+(const Str& s1, const Str& s2){
//	Str s = s1;
//	s += s2;
//	return s;
//}
//
//istream& getline(istream& is, Str& s) {
//	s.data->clear();
//
//	char c;
//	while(is.get(c) && isspace(c));
//
//	if (is) {
//		do
//			s.data->push_back(c);
//		while (is.get(c) && c != '\n');
//		if (is)
//			is.unget();
//	}
//
//	return is;
//}