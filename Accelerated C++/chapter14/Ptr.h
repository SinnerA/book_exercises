//#pragma once
//
//#include<stdexcept>
//
//#include"Ref_count.hpp"
//
//template<class T> class Ptr{
//public:
//	//有条件复制对象
//	void make_unique(){
//		if(refptr.val() != 1){
//			--refptr;
//			refptr = Ref_count();
//			p = p ? clone(p) : 0;
//		}
//	}
//
//	Ptr():p(0){}
//	Ptr(T* t):p(t){}
//	Ptr(const Ptr& h):p(h.p),refptr(h.refptr){ ++refptr; }
//	
//	Ptr& operator=(const Ptr&);
//	~Ptr();
//	operator bool() const{ return p; }
//	T& operator*() const{
//		if(p)
//			return *p;
//		else
//			throw std::runtime_error("unbound Ref_handle");
//	}
//	T* operator->() const{
//		if(p)
//			return p;
//		else
//			throw std::runtime_error("unbound Ref_handle");
//	}
//
//private:
//	T* p;
//	Ref_count refptr;
//};
//
//template <class T>
//Ptr<T>& Ptr<T>::operator=(const Ptr<T>& rhs){
//	++rhs.refptr;
//	if(--refptr == 0){
//		delete p;
//		delete refptr;
//	}
//
//	p = rhs.p;
//	refptr = rhs.refptr;
//	return *this;
//}
//
//template <class T>
//Ptr<T>::~Ptr(){
//	if(--refptr == 0){
//		delete p;
//		delete refptr;
//	}
//}
//
//template <class T>
//T* clone(const T* tp){
//	return tp->clone();
//}