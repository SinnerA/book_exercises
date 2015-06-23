//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//#include<iterator>
//#include<numeric>
//#include"chapter4\grade.h"
//#include"chapter4\Student_info.h"
//#include"chapter4\median.h"
//#include"analysis.h"
//
//using namespace std;
//
//double grade_aux(const Student_info& s){
//	try{
//		return grade(s);
//	} catch(domain_error e){
//		return grade(s.midterm, s.final, 0);
//	}
//}
//
////homework求平均值
//double average(vector<double> homework){
//	return accumulate(homework.begin(), homework.end(), 0.0)/homework.size();
//}
//
////平均值作为中值
//double average_grade(const Student_info& s){
//	return grade(s.midterm, s.final, average(s.homework));
//}
//
////乐观计算分数
//double optimistic_median(const Student_info& s){
//	vector<double> nozero;
//
//	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nozero), 0);
//	if(nozero.size() == 0)
//		return grade(s.midterm, s.final, 0);
//	else
//		return grade(s.midterm, s.final, s.homework);
//}
//
////分3类，进行分数分析
//double analysis(const vector<Student_info>& students, double grade_function(const Student_info& s)){
//	vector<double> grades;
//	transform(students.begin(), students.end(), back_inserter(grades), grade_function);
//	return median(grades);
//}
//
//void write_analysis(ostream& out, const string& name, double grade_function(const Student_info&), 
//	                const vector<Student_info>& did, const vector<Student_info>& didnt){
//		out << name << ": median(did) = " << analysis(did, grade_function)
//			        << ", median(didnt) = " << analysis(didnt, grade_function) << endl;
//}