//#include<iomanip>
//#include"Student_info.h"
//
//using namespace std;
//
//int main(){
//	vector<Student_info> students;
//	Student_info record;
//	string::size_type maxlen = 0;
//
//	//读入并储存数据
//	while(record.read(cin)){
//		maxlen = max(maxlen, record.name().size());
//		students.push_back(record);
//	}
//
//	//排序
//	sort(students.begin(), students.end(), Student_info::compare);
//
//	//输出
//	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
//    cout << students[i].name()
//	 << string(maxlen + 1 - students[i].name().size(), ' ');
//
//    try {
//      double final_grade = students[i].grade();
//      streamsize prec = cout.precision();
//      cout << setprecision(3) << final_grade
//	   << setprecision(prec) << endl;
//    } catch (domain_error e) {
//      cout << e.what() << endl;
//    }
//  }
//
//	return 0;
//}