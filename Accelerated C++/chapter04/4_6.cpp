//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<iomanip>
//
//using namespace std;
//
////ѧ����Ϣ
//struct Student_info{
//	string name;
//	double grade;
//};
//
////���ͥ��ҵ��ֵ
//double median(vector<double> homeworks){
//	if(homeworks.size() == 0){
//		throw domain_error("median of an empty vector");
//	}
//
//	//����
//	sort(homeworks.begin(), homeworks.end());
//
//	typedef vector<double>::size_type vc_size;
//	vc_size size = homeworks.size();
//	vc_size mid = size/2;
//
//	return size%2 == 0 ? (homeworks[mid] + homeworks[mid-1])/2 : homeworks[mid];
//}
//
////�������
//double grade(double midterm, double final, double median){
//	return 0.2 * midterm + 0.4 * final + 0.4 * median;
//}
//
//double grade(double midterm, double final, const vector<double>& homeworks){
//	if(homeworks.size() == 0){
//		throw domain_error("student has done no homewor");
//	}
//	return grade(midterm, final, median(homeworks));
//}
//
//double grade(const Student_info& s){
//	return s.grade;
//}
//
////��ȡ��ͥ��ҵ����
//istream& read_hw(istream& in, vector<double>& hw){
//	if(in){
//		hw.clear();
//
//		double x;
//		while(in >> x){
//			hw.push_back(x);
//		}
//		//������Ա����һ��ѧ��������Ч
//		in.clear();
//	}
//	return in;
//}
//
////����ѧ����Ϣ
//istream& read(istream& in, Student_info& s){
//
//	double midterm, final;
//	vector<double> hw;
//
//	in >> s.name >> midterm >> final;
//	read_hw(in, hw);
//
//	if(in)
//		s.grade = grade(midterm, final, hw);
//
//	return in;
//}
//
////��������
//bool compare(Student_info& a, Student_info& b){
//	return a.name < b.name;
//}
//
//int main(){
//
//	Student_info record;
//	vector<Student_info> students;
//	string::size_type maxlength = 0;
//
//	//�����name�ĳ���
//	try{
//		while(read(cin, record)){
//			students.push_back(record);
//			maxlength = max(record.name.size(), maxlength);
//		}
//	} catch(domain_error e){
//		cout << e.what() << endl;
//	}
//
//	//����
//	sort(students.begin(), students.end(), compare);
//
//	//���ѧ����Ϣ
//	for(vector<Student_info>::size_type i = 0; i != students.size(); i++){
//		//����
//		cout << students[i].name << string(maxlength-students[i].name.size()+1, ' ');
//
//		//����
//		streamsize prec = cout.precision();
//		cout << setprecision(3)
//			 << grade(students[i])
//			 << setprecision(prec)
//			 << endl;
//	}
//
//	return 0;
//}