//#include<iomanip>
//
//#include"Core.h"
//#include"Student_info.h"
//
//using namespace std;
//
//int main(){
//	vector<Core> students;
//	Core record;
//	string::size_type maxlen = 0;
//
//	//���벢�洢����
//	while(record.read(cin)){
//		maxlen = max(maxlen, record.name().size());
//		students.push_back(record);
//	}
//
//	//��ѧ����¼��������
//	sort(students.begin(), students.end(), compare);
//
//	//���ѧ�������ͳɼ�
//	for(vector<Core>::size_type i = 0; i != students.size(); ++i){
//		cout << students[i].name()
//			<< string(maxlen + 1 - students[i].name().size(), ' ');
//		try{
//			double final_grade = students[i].grade();
//			streamsize prec = cout.precision();
//			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
//		} catch(domain_error e){
//			cout << e.what() << endl;
//		}
//	}
//	return 0;
//}