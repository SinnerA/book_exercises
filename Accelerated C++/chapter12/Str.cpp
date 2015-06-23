//#include<vector>
//
//#include"Str.hpp"
//
//using namespace std;
//
////Class public functions----------------------------------------------------------------------
//
////��ֵ���캯��
//Str& Str::operator=(const Str& rhs){
//	if(rhs == *this){
//		//�Ƿ����Ҹ�ֵ
//		uncreate();
//		create(rhs.begin(), rhs.end());
//	}
//	return *this;
//}
//
////copy��������Str�ĵ�posλ�ÿ�ʼ������n��char����p��
//Str::size_type Str::copy(iterator p, size_type n, size_type pos) const{
//	if(pos > size())
//		throw out_of_range("pos > size()");
//	size_type copy_length = min(size() - pos, n);
//	::copy(chars + pos, chars + copy_length, p);
//	return copy_length;
//}
//
////�Լ����������
//Str& Str::operator+=(const Str& s){
//	size_type new_length = length + s.size();
//	iterator new_chars = alloc.allocate(new_length);
//	uninitialized_copy(chars, chars + length - 1, new_chars);
//	uninitialized_copy(s.begin(), s.end(), new_chars + length - 1);
//	alloc.construct(new_chars + new_length - 1, '\0');
//
//	uncreate();
//
//	length = new_length;
//	chars = new_chars;
//}
//
////��ȡ�ַ���
//Str& Str::substr(size_type pos, size_type n) const{
//	return Str(chars + pos, chars + pos + n);
//}
//
////Class Private functions-------------------------------------------------------------------------
//void Str::create(size_type n, char val){
//	length = n + 1;
//	chars = alloc.allocate(length);
//	uninitialized_fill(chars, chars + length - 1, val);
//	alloc.construct(chars + length - 1, '\0');
//}
//
//void Str::uncreate(){
//	if(chars){
//		iterator i = chars + length;
//		//ɾ��Ԫ��
//		while(i){
//			alloc.destroy(--i);
//		}
//		//�ͷſռ�
//		alloc.deallocate(chars, length);
//	}
//
//	length = 0;
//	chars = 0;
//}
//
////Other functions---------------------------------------------------------------------------
//ostream& operator<<(ostream& os, const Str& s){
//	for(Str::size_type i = 0; i!= s.size(); ++i){
//		os << s[i];
//	}
//	return os;
//}
//
//ostream_iterator<char>& operator<<(ostream_iterator<char>& os, const Str& s){
//	copy(s.begin(), s.end(), os);
//	return os;
//}
//
//static int is_newline(int c){
//	return (c == '\0');
//}
//
//static istream& read_until(istream& is, Str& s, int is_stop_char(int)){
//	vector<char> data;
//	char c;
//
//	while(is.get(c) && isspace(c));
//
//	do
//	    data.push_back(c);
//	while(is.get(c) && !is_stop_char(c));
//	if(is){
//		is.unget();
//	}
//	return is;
//}
//
//istream& operator>>(istream& is, Str& s){
//	return read_until(is, s, isspace);
//}
//
//istream& getline(istream& is, Str& s){
//	return read_until(is, s, is_newline);
//}
//
////�ӷ����������
//Str operator+(const Str& s, const Str& t){
//	Str r = s;
//	r += t;
//	return r;
//}
//
//Str operator+(const Str& s, const char* t){
//	Str r(t, t + strlen(t));
//	r += s;
//	return r;
//}
//
//Str operator+(const char* s, const Str& t){
//	Str r(s, s + strlen(s));
//	r += t;
//	return r;
//}
//
