//#include<iostream>
//#include<algorithm>
//#include<ios>
//#include<iomanip>
//#include<stdexcept>
//#include<string>
//#include<vector>
//#include<map>
//#include "chapter4\grade.h"
//#include "chapter4\Student_info.h"
//
//using namespace std;
//
////成绩分级
//string get_letter_grade(double final_grade){
//	if(final_grade >= 90.0 && final_grade <= 100.0){
//		return "A";
//	} else if(final_grade >= 80.0 && final_grade < 90.0){
//		return "B";
//	} else if(final_grade >= 70.0 && final_grade < 80.0){
//		return "C";
//	} else if(final_grade >= 60.0 && final_grade < 70.0){
//		return "D";
//	}
//	return "F";
//}
//			
//int main(){
//	
//	map<string, int> classify_students;
//	vector<Student_info> students;
//	Student_info record;
//	string::size_type maxlen = 0;
//
//	//读入并存储所有学生的数据
//	while(read(cin, record)){
//		maxlen = max(maxlen, record.name.size());
//		students.push_back(record);
//	}
//
//	//名字排序
//	sort(students.begin(), students.end(), compare);
//
//	for(vector<Student_info>::size_type i = 0; i != students.size(); i++){
//		try{
//			double final_grade = grade(students[i]);
//			++classify_students[get_letter_grade(final_grade)];
//		}catch(domain_error e){
//			cout << e.what();
//		}
//	}
//
//	//按分数范围评出等级，列出每一种有多少学生
//	for(map<string, int>::const_iterator i = classify_students.begin(); i != classify_students.end(); ++i){
//		cout << i->first << ": " << i->second << endl;
//	}
//
//	return 0;
//}