//#include<vector>
//#include"Str.h"
//
//using namespace std;
//
////�������������
//istream& operator>>(istream& is, Str& s){
//	s.data.clear();
//
//	char c;
//	//����ǰ��ո�
//	while(is.get(c) && isspace(c))
//		;
//
//	//��������ǿո��ַ�����Ѱ�ҿո��ַ�
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
////������������
//ostream& operator<<(ostream& os, const Str& s){
//	for(Str::size_type i = 0; i != s.size(); ++i){
//		os << s[i];
//	}
//	return os;
//}
//
////�Ӻ����������
//Str operator+(const Str& s, const Str& t){
//	Str r = s;
//	r += t;
//	return r;
//}
//
////��ȡһ�в�����
//static int is_newline(int c){
//	return (c == '\n');
//}
//
//static istream& read_until(istream& is, Str& s, int is_stop_char(int)){
//	vector<char> data;
//	char c;
//
//	//�����ո�
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
