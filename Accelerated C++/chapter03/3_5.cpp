//#include<iostream>
//#include<string>
//#include<vector>
//#include<iomanip>
//#include<ios>
//
//using std::cout;
//using std::cin;
//using std::endl;
//using std::string;
//using std::vector;
//using std::streamsize;
//using std::setprecision;
//
////��ͥ��ҵ����
//#define NUM_HOMEWORK 2
//
//int main(){
//
//	//���������ճɼ�
//	vector<string> names;
//	vector<double> final_grades;
//	bool done = false;
//	
//	while(!done){
//		//����
//		cout << "Enter names:��";
//		string name;
//		cin >> name;
//		cout << "Hello, " + name << endl;
//		names.push_back(name);
//
//		//���У���ĩ����
//		cout << "Enter your midterm and final exam grades: ";
//		double midterm,final;
//		cin >> midterm >> final;
//
//		//��ͥ��ҵ����
//		cout << "Enter your homework grades: ";
//		int count = 0;
//		double sum = 0;
//		double x;
//
//		while(count < NUM_HOMEWORK){
//			cin >> x;
//			sum += x;
//			++count;
//		}
//
//		//�ܳɼ�
//		double final_grade = 0.2*midterm + 0.4*final + 0.4*sum/count;
//
//		final_grades.push_back(final_grade);
//
//		cout << "More?(Y/N)";
//		string s;
//		cin >> s;
//
//		if(s != "Y"){
//			done = true;
//		}
//	}
//
//	//������
//	for(vector<string>::size_type i = 0; i < names.size(); ++i){
//		streamsize prec = cout.precision();
//		cout << names[i] << "'s final grade is " << setprecision(3) 
//			 << final_grades[i] 
//		     << setprecision(prec) << endl;
//	}
//
//	return 0;
//}