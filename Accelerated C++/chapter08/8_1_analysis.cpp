//#include<iostream>
//#include<vector>
//#include<numeric>
//#include<stdexcept>
//
//#include"..\chapter4\Student_info.h"
//#include"..\chapter4\median.h"
//#include"..\chapter4\grade.h"
//#include"8_1_analysis.hpp"
//
//using namespace std;
//
////�Ƿ��������м�ͥ��ҵ
//bool did_all_hw(const Student_info& s){
//	return (find(s.homework.begin(), s.homework.end(), 0) == s.homework.end());
//}
//
//double grade_aux(const Student_info& s){
//	try{
//		return grade(s);
//	} catch(domain_error e){
//		return grade(s.midterm, s.final, 0);
//	}
//}
//
////homework��ƽ��ֵ
//double average(vector<double> homework){
//	return accumulate(homework.begin(), homework.end(), 0.0)/homework.size();
//}
//
////ƽ��ֵ��Ϊ��ֵ
//double average_grade(const Student_info& s){
//	return grade(s.midterm, s.final, average(s.homework));
//}
//
////�ֹۼ������
//double optimistic_median(const Student_info& s){
//	vector<double> nozero;
//
//	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nozero), 0);
//	if(nozero.size() == 0)
//		return grade(s.midterm, s.final, 0);
//	else
//		return grade(s.midterm, s.final, s.homework);
//}