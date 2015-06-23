//#include<iomanip>
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<vector>
//#include<stdexcept>
//
//#include"Ptr.h"
//#include"Student_info.h"
//
//using namespace std;
//
//bool compare_core_handles(const Ptr<Core>& lhs, const Ptr<Core>& rhs){
//	return compare(*lhs, *rhs);
//}
//
//int main(){
//	vector<Ptr<Core> > students;
//	Ptr<Core> record;
//	char ch;
//	string::size_type maxlen = 0;
//
//	//�������洢����
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
//	//����
//	sort(students.begin(), students.end(), compare_core_handles);
//
//	//���ѧ�������ͳɼ�
//	for(vector<Ptr<Core> >::size_type i = 0; i != students.size(); ++i){
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