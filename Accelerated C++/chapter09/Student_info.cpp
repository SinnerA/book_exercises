//#include<iostream>
//
//#include"Student_info.h"
//#include"grade.h"
//
//using namespace std;
//
////默认构造函数
//Student_info::Student_info():midterm(0),final(0){}
//
////从输入流构造对象
//Student_info::Student_info(istream& is){read(is);}
//
////成绩
//double Student_info::grade() const{
//	return  ::grade(midterm, final, homework);
//}
//
////比较姓名
//bool compare(const Student_info& x, const Student_info& y){
//	return x.name() < y.name();
//}
//
////从输入流读取家庭作业成绩
//istream& read_hw(istream& in, vector<double>& hw){
//	if(in){
//		hw.clear();
//
//		double x;
//		while(cin >> x){
//			hw.push_back(x);
//		}
//
//		in.clear();
//	}
//	return in;
//}
//
////读取信息
//istream& Student_info::read(istream& in){
//	in >> n >> midterm >> final;
//	read_hw(in, homework);
//	return in;
//}
//
