//#pragma once
//
//#include<algorithm>
//#include<iostream>
//#include<string>
//#include<vector>
//#include<iostream>
//
//class Core{
//	friend class Student_info;
//public:
//	Core():midterm(0), final(0){}
//	Core(std::istream& is){ read(is); };
//
//	std::string name() const;
//	virtual std::istream& read(std::istream&);
//	virtual double grade() const;
//	virtual Core* clone() const{ return new Core(*this); }
//	virtual ~Core(){};
//protected:
//	double midterm, final;
//	std::vector<double> homework;
//	std::istream& read_common(std::istream&);
//private:
//	std::string n;
//};
//
//class Grad:public Core{
//public:
//	Grad():thesis(0){ };
//	Grad(std::istream& is){ read(is); };
//
//	double grade() const;
//
//	std::istream& read(std::istream&);
//protected:
//	Grad* clone() const{ return new Grad(*this); }
//private:
//	double thesis;
//};
//
//bool compare(const Core&, const Core&);
//bool compare_core_ptrs(const Core* cp1, const Core* cp2);