//#include<iostream>
//#include<vector>
//
//#include"9_1_Student_info.hpp"
//#include"grade.h"
//
//using namespace std;
//
////构造函数
//Student_info::Student_info(){}
//
//Student_info::Student_info(istream& in){
//	read(in);
//}
//
////读家庭作业
//istream& read_hw(istream& in, vector<double> hw){
//	if(in){
//		hw.clear();
//
//		double x;
//		while(in >> x){
//			hw.push_back(x);
//		}
//
//		in.clear();
//	}
//	return in;
//}
//
////读入学生信息
//istream& Student_info::read(istream& in){
//	in >> n >> midterm >> final;
//	read_hw(in, homework);
//	g = ::grade(midterm, final, homework);
//	return in;
//}
//
////得到总成绩
//double Student_info::grade() const{
//	return g;
//}
//
////比较姓名
//bool compare(Student_info& x, Student_info& y){
//	return x.name() < y.name();
//}