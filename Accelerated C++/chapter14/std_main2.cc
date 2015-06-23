//#include<iomanip>
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<vector>
//#include<stdexcept>
//
//#include"Ref_handle.h"
//#include"Student_info.h"
//
//using namespace std;
//
//bool compare_core_handles(const Ref_handle<Core>& lhs, const Ref_handle<Core>& rhs){
//	return compare(*lhs, *rhs);
//}
//
//int main(){
//	vector<Ref_handle<Core> > students;
//	Ref_handle<Core> record;
//	char ch;
//	string::size_type maxlen = 0;
//
//	//读出并存储数据
//	while(cin >> ch){
//		if(ch == 'U')
//			record = new Core;
//		else
//			record = new Grad;
//		record->read(cin);
//		maxlen = max(record->name().size(), maxlen);
//		students.push_back(record);
//	}
//
//	//排序
//	sort(students.begin(), students.end(), compare_core_handles);
//
//	//输出学生姓名和成绩
//	for(vector<Ref_handle<Core> >::size_type i = 0; i != students.size(); ++i){
//		cout << students[i]->name()
//			 << string(maxlen + 1 - students[i]->name().size(), ' ');
//		try{
//			double final_grade = students[i]->grade();
//			streamsize prec = cout.precision();
//			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
//		} catch(domain_error e){
//			cout << e.what() << endl;
//		}
//	}
//
//	return 0;
//}