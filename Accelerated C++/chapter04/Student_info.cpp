//#include "Student_info.h"
//
//using std::istream;
//using std::vector;
//
//bool compare(const Student_info& x, const Student_info& y){
//	return x.name < y.name;
//}
//
//istream& read(istream& in, Student_info& s){
//	in >> s.name >> s.midterm >> s.final;
//	read_hw(in, s.homework);
//	return in;
//}
//
//istream& read_hw(istream& in, vector<double>& hw){
//	if(in){
//		//清除原先内容
//		hw.clear();
//
//		double x;
//		while(in >> x){
//			hw.push_back(x);
//		}
//		//清除流以便输入动作对下一个学生有效
//		in.clear();
//	}
//	return in;
//}