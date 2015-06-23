//#include<algorithm>
//#include<iostream>
//
//#include"PF_grader.hpp"
//
//using namespace std;
//
//PF_grader::PF_grader(){};
//
//bool passing(const Student_info& s){//added
//	return s.passing();
//}
//
//void PF_grader::add_student(Student_info s){
//	students.push_back(s);
//	partition(students.begin(), students.end(), passing);//changed
//}
//
//void PF_grader::print_grades() const{
//	for(vector<Student_info>::size_type i = 0; i != students.size(); ++i){
//		string pf = (students[i].passing()) ? "P" : "F";
//		cout << students[i].name() << ": " << pf << endl;
//	}
//}
//
//int main(){
//	PF_grader pf_grader;
//
//	Student_info s;
//	while(s.read(cin)){
//		pf_grader.add_student(s);
//	}
//	pf_grader.print_grades();
//
//	return 0;
//}