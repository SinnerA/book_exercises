//#pragma once
//
//#include<algorithm>
//#include<iostream>
//#include<vector>
//#include<string>
//
//#include"Ptr.h"
//
//class Picture;
//
////class Pic_base--------------------------------------------------------------
//class Pic_base{
//	friend std::ostream& operator<<(std::ostream&, const Picture&);
//	friend class Frame_Pic;
//	friend class HCat_Pic;
//	friend class VCat_Pic;
//	friend class String_Pic;
//	friend class Picture;
//public:
//	virtual ~Pic_base(){}
//private:
//	typedef std::vector<std::string>::size_type ht_sz;
//	typedef std::string::size_type wd_sz;
//
//	virtual wd_sz width() const = 0;
//	virtual ht_sz height() const = 0;
//	virtual void display(std::ostream&, ht_sz, bool) const = 0;
//	virtual void reframe(char, char, char) = 0;
//protected:
//	static void pad(std::ostream& os, wd_sz beg, wd_sz end){
//		while(beg != end){
//			os << " ";
//			++beg;
//		}
//	}
//};
//
////class Picture---------------------------------------------------------------
//class Picture{
//	friend std::ostream& operator<<(std::ostream&, const Picture&);
//	friend Picture frame(const Picture&);
//	friend Picture hcat(const Picture&, const Picture&);
//	friend Picture vcat(const Picture&, const Picture&);
//public:
//	Picture(const std::vector<std::string>& = std::vector<std::string>());
//	void reframe(char c, char t_b, char s){ p->reframe(c, t_b, s); }
//private:
//	//用于将Pic_base*转换成Picture
//	Picture(Pic_base* ptr):p(ptr){}
//	Ptr<Pic_base> p;
//};
//
////Picture的functions-----------------------------------------------------------
//Picture frame(const Picture&);
//Picture hcat(const Picture&, const Picture&);
//Picture vcat(const Picture&, const Picture&);
//std::ostream& operator<<(std::ostream&, const Picture&);
//
////Pic_base的继承类---------------------------------------------------------------
//class String_Pic:public Pic_base{
//	friend Picture::Picture(const std::vector<std::string>&);
//private:
//	std::vector<std::string> data;
//	String_Pic(const std::vector<std::string>& v):data(v){}
//
//	wd_sz width() const;
//	ht_sz height() const;
//	void display(std::ostream&, ht_sz, bool) const;
//	void reframe(char, char, char){};
//};
//
//class Frame_Pic:public Pic_base{
//	friend Picture frame(const Picture&);
//private:
//	Ptr<Pic_base> p;
//	char corner;
//	char top_bottom;
//	char slide;
//
//	Frame_Pic(const Ptr<Pic_base>& pic):p(pic),corner('*'),top_bottom('-'),slide('|'){}
//
//	wd_sz width() const;
//	ht_sz height() const;
//	void display(std::ostream&, ht_sz, bool) const;
//	void reframe(char, char, char);
//};
//
//class VCat_Pic:public Pic_base{
//	friend Picture vcat(const Picture&, const Picture&);
//private:
//	Ptr<Pic_base> bottom, top;
//	VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b):bottom(b),top(t){}
//
//	wd_sz width() const;
//	ht_sz height() const;
//	void display(std::ostream&, ht_sz, bool) const;
//	void reframe(char, char, char);
//};
//
//class HCat_Pic:public Pic_base{
//	friend Picture hcat(const Picture&, const Picture&);
//private:
//	Ptr<Pic_base> left, right;
//	HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r):left(l),right(r){}
//
//	wd_sz width() const;
//	ht_sz height() const;
//	void display(std::ostream&, ht_sz, bool) const;
//	void reframe(char, char, char);
//};