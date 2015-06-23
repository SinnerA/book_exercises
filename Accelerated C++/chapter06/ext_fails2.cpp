//#include<iostream>
//#include<algorithm>
//#include"chapter4\grade.h"
//#include"chapter4\Student_info.h"
//
//using namespace std;
//
//vector<Student_info> extract_fails(vector<Student_info>& students){
//	vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
//	vector<Student_info> fails(iter, students.end());
//	students.erase(iter, students.end());
//
//	return fails;
//}