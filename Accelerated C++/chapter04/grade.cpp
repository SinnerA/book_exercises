//#include "grade.h"
//#include "median.h"
//#include "Student_info.h"
//#include<stdexcept>
//#include<vector>
//
//using std::vector;
//using std::domain_error;
//
//double grade(double midterm, double final, double homework){
//	return 0.2*midterm + 0.4*final + 0.4*homework;
//}
//
//double grade(double midterm, double final, const vector<double>& homeworks){
//	if(homeworks.size() == 0){
//		throw domain_error("student has done no homework");
//	}
//	return grade(midterm, final, median(homeworks));
//}
//
//double grade(const Student_info& student){
//	return grade(student.midterm, student.final, student.homework);
//}
//
////�ж�ѧ���Ƿ񲻼���
//bool fgrade(const Student_info& s){
//	return grade(s) < 60;
//}
//
////�ж�ѧ���Ƿ񲻼���
//bool pgrade(const Student_info& s){
//	return !fgrade(s);
//}