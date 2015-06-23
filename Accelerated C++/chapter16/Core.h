//#pragma once
//
//#include<algorithm>
//#include<iostream>
//#include<string>
//#include<vector>
//#include<iostream>
//
//#include"grade.h"
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
//	virtual bool fullfil_reqs() const {
//		return (std::find(homework.begin(), homework.end(), 0.0) == homework.end());
//	}
//	virtual ~Core(){};
//protected:
//	std::istream& read_common(std::istream&);
//	std::string n;
//	double midterm, final;
//	std::vector<double> homework;
//
//	virtual Core* clone() const{ return new Core(*this); }
//};
//
//class Grad:public Core{
//public:
//	Grad():thesis(0){ };
//	Grad(std::istream& is){ read(is); };
//
//	double grade() const;
//	bool fullfil_reqs() const{
//		return thesis > 0.0;
//	}
//
//	std::istream& read(std::istream&);
//protected:
//	Grad* clone() const{ return new Grad(*this); }
//private:
//	double thesis;
//};
//
//class PassFail:public Core{
//public:
//	PassFail(){}
//	PassFail(std::istream& is){ read(is); }
//	
//	double grade(){
//		if(homework.size() > 0)
//			return ::grade(midterm, final, homework);
//		else
//			return (midterm + final)/2;
//	}
//
//	bool vaild() const{ return true; }
//	bool fullfil_reqs() const{ return true; }
//private:
//	PassFail* clone() const{ return new PassFail(*this); }
//};
//
//class Audit:public Core{
//public:
//	Audit(){}
//	Audit(std::istream& is){ read(is); }
//
//	double grade() const{ return 0.0; }
//
//	bool vaild() const{ return true; }
//	bool fullfil_reqs() const{ return true; }
//
//	std::istream& read(std::istream&);
//private:
//	Audit* clone() const{ return new Audit(*this); }
//};
//
//bool compare(const Core&, const Core&);
//bool compare_core_ptrs(const Core* cp1, const Core* cp2);
//std::string letter_grade(double);