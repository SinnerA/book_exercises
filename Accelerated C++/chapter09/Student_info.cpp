//#include<iostream>
//
//#include"Student_info.h"
//#include"grade.h"
//
//using namespace std;
//
////Ĭ�Ϲ��캯��
//Student_info::Student_info():midterm(0),final(0){}
//
////���������������
//Student_info::Student_info(istream& is){read(is);}
//
////�ɼ�
//double Student_info::grade() const{
//	return  ::grade(midterm, final, homework);
//}
//
////�Ƚ�����
//bool compare(const Student_info& x, const Student_info& y){
//	return x.name() < y.name();
//}
//
////����������ȡ��ͥ��ҵ�ɼ�
//istream& read_hw(istream& in, vector<double>& hw){
//	if(in){
//		hw.clear();
//
//		double x;
//		while(cin >> x){
//			hw.push_back(x);
//		}
//
//		in.clear();
//	}
//	return in;
//}
//
////��ȡ��Ϣ
//istream& Student_info::read(istream& in){
//	in >> n >> midterm >> final;
//	read_hw(in, homework);
//	return in;
//}
//
