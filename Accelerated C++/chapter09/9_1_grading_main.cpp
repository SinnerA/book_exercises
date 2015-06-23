//#include<vector>
//#include<string>
//#include<algorithm>
//#include<iostream>
//#include<stdexcept>
//#include<iomanip>
//
//#include"9_1_Student_info.hpp"
//
//using namespace std;
//
//int main(){
//	vector<Student_info> students;
//	Student_info record;
//	string::size_type maxlen;
//
//	//读入数据
//	while(record.read(cin)){
//		maxlen = max(maxlen, record.name().size());
//		students.push_back(record);
//	}
//
//	//排序
//	sort(students.begin(), students.end(), compare);
//
//	//输出
//	for(string::size_type i = 0; i != students.size(); ++i){
//		cout << students[i].name()
//			 << string(maxlen + 1 - students[i].name().size(), ' ');
//
//		try{
//			streamsize prec = cout.precision();
//		    cout << setprecision(3) << students[i].grade()
//			     << setprecision(prec) << endl;
//		} catch(domain_error e){
//			cout << e.what() << endl;
//		}
//	}
//
//	return 0;
//}