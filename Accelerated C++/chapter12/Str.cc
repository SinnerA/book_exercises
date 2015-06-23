//#include<vector>
//#include"Str.h"
//
//using namespace std;
//
////输入运算符函数
//istream& operator>>(istream& is, Str& s){
//	s.data.clear();
//
//	char c;
//	//忽略前面空格
//	while(is.get(c) && isspace(c))
//		;
//
//	//如果读到非空格字符，再寻找空格字符
//	if(is){
//		do
//		    s.data.push_back(c);
//		while(is.get(c) && !isspace(c));
//
//		if(is)
//			is.unget();
//	}
//	return is;
//}
//
////输出运算符函数
//ostream& operator<<(ostream& os, const Str& s){
//	for(Str::size_type i = 0; i != s.size(); ++i){
//		os << s[i];
//	}
//	return os;
//}
//
////加号运算符函数
//Str operator+(const Str& s, const Str& t){
//	Str r = s;
//	r += t;
//	return r;
//}
//
////读取一行并保存
//static int is_newline(int c){
//	return (c == '\n');
//}
//
//static istream& read_until(istream& is, Str& s, int is_stop_char(int)){
//	vector<char> data;
//	char c;
//
//	//跳过空格
//	while(is.get(c) && isspace(c));
//
//	if(is){
//		do
//			data.push_back(c);
//		while(is.get(c) && !is_stop_char(c));
//		if(is)
//			is.unget();
//	}
//
//	s = Str(data.begin(), data.end());
//	return is;
//}
//
//istream& getline(istream& is, Str& s){
//	read_until(is, s, is_newline);
//}
//
//
//
//
