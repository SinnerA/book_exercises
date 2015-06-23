//#pragma once
//
//#include<vector>
//#include<algorithm>
//#include<iterator>
//#include<iostream>
//#include"..\chapter4\Student_info.h"
//#include"..\chapter4\median.h"
//
//bool did_all_hw(const Student_info& s);
//
//double grade_aux(const Student_info& s);
//
//double average_grade(const Student_info& s);
//
//double optimistic_median(const Student_info& s);
//
////分析
//template<class Func>
//double analysis(const std::vector<Student_info>& students, Func grading_function){
//	std::vector<double> grades;
//
//	transform(students.begin(), students.end(), back_inserter(grades), grading_function);
//	return median(grades);
//}
//
////分析两个学生集合
//template<class Func>
//void write_analysis(std::ostream& out, const std::string& name, 
//	                Func grading_function, 
//					const std::vector<Student_info>& did, 
//					const std::vector<Student_info>& didnt){
//	out << name << ": median(did) = " << analysis(did, grading_function)
//			    << ", median(didnt) = " << analysis(didnt, grading_function) << endl;
//}