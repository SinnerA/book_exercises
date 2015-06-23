//#include<algorithm>
//#include<iterator>
//#include<numeric>
//#include"analysis.h"
//#include"..\chapter4\grade.h"
//#include"..\chapter4\median.h"
//
//using namespace std;
//
////是否做完所有家庭作业
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
////中值分析
//double median_analysis(const vector<Student_info>& students){
//	vector<double> grades;
//
//	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
//	return median(grades);
//}
//
////平均值分析
//double average_analysis(const vector<Student_info>& students){
//	vector<double> grades;
//
//	transform(students.begin(), students.end(), back_inserter(grades), average_grade);
//	return median(grades);
//}
//
////乐观分析
//double optimistic_median_analysis(const vector<Student_info>& students){
//	vector<double> grades;
//
//	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
//	return median(grades);
//}
//
////分析两个学生集合
//void write_analysis(ostream& out, const string& name, double analysis(const vector<Student_info>&), 
//	const vector<Student_info>& did, const vector<Student_info>& didnt){
//		out << name << ": median(did) = " << analysis(did)
//			        << ", median(didnt) = " << analysis(didnt) << endl;
//}