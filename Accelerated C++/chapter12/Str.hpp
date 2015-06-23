//#pragma once
//
//#include<cstring>
//#include<iterator>
//#include<memory>
//
//class Str{
//public:
//	typedef std::size_t size_type;
//	typedef char* iterator;
//	typedef const char* const_iterator;
//
//	//构造函数
//	Str(){ create(0, '\0'); }
//	Str(char c, size_type n){ create(n, c); }
//	Str(const char* p){ create(p, p + strlen(p)); }
//	template <class In> Str(In i, In j){ create(i, j); }
//
//	//复制构造函数
//	Str(const Str& s){ create(s.begin(), s.end()); }
//	//复制运算符函数
//	Str& operator=(const Str&);
//	//析构函数
//	~Str(){ uncreate(); }
//
//	//索引运算符函数
//	char& operator[](size_type i) { return *(chars + i); }
//	char& operator[](size_type i) const { return *(chars + i); }
//	size_type size() const { return length - 1; }
//
//	//返回迭代器
//	iterator begin(){ return chars; }
//	const iterator begin() const{ return chars; }
//
//	iterator end(){  return chars + length; }
//	const iterator end() const{ return chars + length; }
//
//	Str& operator+=(const Str&);
//	operator bool() const { return (size() > 0); }
//
//	Str& substr(size_type, size_type) const;
//	template <class In> void insert(iterator, In, In);
//
//	//3个函数，用于从string类型对象中获得一个字符数组
//	const char* c_str() const { return chars; }
//	const char* data() const { return chars; }
//	size_type copy(iterator, size_type, size_type = 0) const;
//
//private:
//	//包含'\0'
//	size_type length;
//	iterator chars;
//
//	//内存分配工具
//	std::allocator<char> alloc;
//	//支持push_back的函数
//	void grow(size_type);
//
//	void create(size_type, char);
//	template <class In> void create(In, In);
//	void uncreate();
//};
//
////Class public functions-----------------------------------------------------------------------
//template <class In> void Str::insert(iterator p, In i, In j){
//	size_type new_length = length + j - i;
//	iterator new_chars = alloc.allocate(new_length);
//	uninitialized_copy(chars, p, new_chars);
//	uninitialized_copy(i, j, new_chars + (p - chars));
//	uninitialized_copy(p, chars + length - 1, new_chars + ((p - chars) + (j - i)));
//	alloc.construct(new_chars + new_length - 1, '\0');
//
//	uncreate();
//
//	length = new_length;
//	chars = new_chars;
//}
//
////Class private functions-----------------------------------------------------------------------
//template <class In> void Str::create(In i, In j){
//	length = j - i;
//	chars = alloc.allocate(length);
//	uninitialized_copy(i, j, chars);
//	alloc.construct(chars + length, '\0');
//}
//
////Other functions-----------------------------------------------------------------------
//
////输入输出运算符函数
//std::ostream& operator<<(std::ostream&, const Str&);
//std::ostream_iterator<char>& operator<<(std::ostream_iterator<char>&, const Str&);
//std::istream& operator>>(std::istream&, Str&);
//std::istream& getline(std::istream&, Str&);
//
////加法运算符函数
//Str operator+(const Str&, const Str&);
//Str operator+(const Str&, const char*);
//Str operator+(const char*, const Str&);
//
////比较大小
//inline bool operator<(const Str& lhs, const Str& rhs){
//	return (strcmp(lhs.c_str(), rhs.c_str()) < 0);
//}
//inline bool operator>(const Str& lhs, const Str& rhs){
//	return (strcmp(lhs.c_str(), rhs.c_str()) > 0);
//}
//inline bool operator<=(const Str& lhs, const Str& rhs){
//	return (strcmp(lhs.c_str(), rhs.c_str()) <= 0);
//}
//inline bool operator>=(const Str& lhs, const Str& rhs){
//	return (strcmp(lhs.c_str(), rhs.c_str()) >= 0);
//}
//inline bool operator==(const Str& lhs, const Str& rhs){
//	return (strcmp(lhs.c_str(), rhs.c_str()) == 0);
//}
//inline bool operator!=(const Str& lhs, const Str& rhs){
//	return (strcmp(lhs.c_str(), rhs.c_str()) != 0);
//}