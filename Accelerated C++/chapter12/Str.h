//#include<iterator>
//
//#include"..\chapter11\Vec.h"
//
//class Str{
//	friend std::istream& operator>>(std::istream&, Str&);
//	friend std::istream& getline(std::istream&, Str&);
//public:
//	typedef Vec<char>::size_type size_type;
//	typedef char* iterator;
//	typedef const char* const_iterator;
//	
//	//���캯��
//	Str(){}
//	Str(size_type n, char c):data(n, c){}
//	Str(const char* cp){
//		std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
//	}
//	template <class In>
//	Str(In b, In e){
//		std::copy(b, e, std::back_inserter(data));
//	}
//	
//	size_type size() const { return data.size(); }
//	//�������������
//	char& operator[](size_type i){ return data[i]; }
//	const char& operator[](size_type i) const { return data[i]; }
//
//	//�ӷ����������
//	Str& operator+=(const Str& s){
//		std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
//		return *this;
//	}
//
//	//���ص�����
//	iterator begin(){return data.begin();}
//	const iterator begin() const{return data.begin();}
//
//	iterator end(){return data.end();}
//	const iterator end() const{return data.end();}
//private:
//	Vec<char> data;
//};
//std::ostream& operator<<(std::ostream&, const Str&);
//Str operator+(const Str&, const Str&);
//
////��С�Ƚ����������
//inline bool operator<(const Str& lhs, const Str& rhs){
//	//���ֵ�˳��Ƚ���������
//	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
//}
//
//inline bool operator>(const Str& lhs, const Str& rhs){
//	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
//}
//
//inline bool operator<=(const Str& lhs, const Str& rhs){
//	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
//}
//
//inline bool operator>=(const Str& lhs, const Str& rhs){
//	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
//}
//
//inline bool operator==(const Str& lhs, const Str& rhs){
//	return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
//}
//
//inline bool operator!=(const Str& lhs, const Str& rhs){
//	return !(lhs == rhs);
//}