//#include<iostream>
//#include<vector>
//
//#include"9_1_Student_info.hpp"
//#include"grade.h"
//
//using namespace std;
//
////���캯��
//Student_info::Student_info(){}
//
//Student_info::Student_info(istream& in){
//	read(in);
//}
//
////����ͥ��ҵ
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
////����ѧ����Ϣ
//istream& Student_info::read(istream& in){
//	in >> n >> midterm >> final;
//	read_hw(in, homework);
//	g = ::grade(midterm, final, homework);
//	return in;
//}
//
////�õ��ܳɼ�
//double Student_info::grade() const{
//	return g;
//}
//
////�Ƚ�����
//bool compare(Student_info& x, Student_info& y){
//	return x.name() < y.name();
//}