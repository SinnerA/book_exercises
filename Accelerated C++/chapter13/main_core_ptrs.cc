//#include<iomanip>
//
//#include"Core.h"
//#include"Student_info.h"
//
//using namespace std;
//
//int main(){
//	vector<Core*> students;
//	Core* record;
//	char ch;
//	string::size_type maxlen = 0;
//
//	//�������洢����
//	while(cin >> ch){
//		if(ch == 'U'){
//			record = new Core;
//		} else {
//			record = new Grad;
//		}
//		record->read(cin);
//		maxlen = max(record->name().size(), maxlen);
//		students.push_back(record);
//	}
//
//	//����
//	sort(students.begin(), students.end(), compare_core_ptrs);
//
//	//���ѧ�������ͳɼ�
//	for(vector<Core*>::size_type i = 0; i != students.size(); ++i){
//		cout << students[i]->name()
//			 << string(maxlen + 1 - students[i]->name().size(), ' ');
//		try{
//			double final_grade = students[i]->grade();
//			streamsize prec = cout.precision();
//			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
//		} catch(domain_error e){
//			cout << e.what() << endl;
//		}
//		//�ͷŶ��ļ�ʱ��������ʱ����
//		delete students[i];
//	}
//
//	return 0;
//}