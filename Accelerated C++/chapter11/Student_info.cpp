//#include<iostream>
//
//#include"Student_info.h"
//
//using namespace std;
//
//void print(const string& str){
//	cout << str << endl;
//}
//
//bool compare(const Student_info& a, const Student_info& b){
//	return a.name < b.name;
//}
//
//istream& read(istream& in, Student_info& s){
//	in >> s.name >> s.midterm >> s.final;
//	read_hw(in, s.homework);
//	return in;
//}
//
//istream& read_hw(istream& in, Vec<double>& hw){
//	if(in){
//		hw.clear();
//
//		double x;
//		while(in >> x){
//			hw.push_back(x);
//		}
//		in.clear();
//	}
//	return in;
//}