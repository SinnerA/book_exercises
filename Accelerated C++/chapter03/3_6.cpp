//#include<iostream>
//#include<string>
//#include<vector>
//#include<ios>
//#include<iomanip>
//
//using std::cin;
//using std::cout;
//using std::endl;
//using std::string;
//using std::vector;
//using std::setprecision;
//using std::streamsize;
//
//int main(){
//	
//	//����
//	cout << "Enter your name: ";
//	string name;
//	cin >> name;
//	cout << "Hello! " << name << endl;
//
//	//���У���ĩ�ɼ�
//	cout << "Enter your midterm and final exam grades: ";
//	double midterm, final;
//	cin >> midterm >> final;
//
//	//��ͥ��ҵ
//	cout << "Enter your homework";
//	int count = 0;
//	double sum = 0;
//	double x;
//	while(cin >> x){
//		sum += x;
//		++count;
//	}
//
//	double homework_grade = (count > 0) ? sum/count : 0.0;
//
//	//���
//	streamsize prec = cout.precision();
//	cout << name << "'s final grade is " << setprecision(3) 
//		 << 0.2*midterm + 0.4*final + 0.4*homework_grade 
//		 << setprecision(prec) << endl;
//
//	return 0;
//}