//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<iomanip>
//#include<stdexcept>
//
//#include"letter_grade.hpp"
//#include"..\chapter9\9_1_Student_info.hpp"
//
//using namespace std;
//
//int main(){
//	vector<Student_info> students;
//	Student_info record;
//	string::size_type maxlen = 0;
//
//	// ‰»Î
//	while(record.read(cin)){
//		maxlen = max(maxlen, record.name().size());
//		students.push_back(record);
//	}
//
//	//≈≈–Ú
//	sort(students.begin(), students.end(), compare);
//
//	// ‰≥ˆ
//	for(vector<Student_info>::const_iterator i = students.begin(); i != students.end(); ++i){
//		cout << i->name()
//			<< string(maxlen - i->name().size(), ' ');
//
//		try{
//			string grade = letter_grade(i->grade());
//			streamsize prec = cout.precision();
//			cout << setprecision(3) << grade
//				 << setprecision(prec) << endl;
//		} catch(domain_error e){
//			cout << e.what() << endl;
//		}
//	}
//
//	return 0;
//}