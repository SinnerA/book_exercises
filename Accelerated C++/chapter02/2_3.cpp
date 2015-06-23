//#include<iostream>
//#include<string>
//
//using std::cin;
//using std::cout;
//using std::endl;
//using std::string;
//
//int main(){
//
//	cout << "Please enter your first name: ";
//
//	string name;
//	cin >> name;
//
//	cout << "Please enter the pad: ";
//
//	//间隙数
//	int pad = 0;
//	cin >> pad;
//
//	const string greeting = "Hello, " + name + "!" ;
//	
//	//行和列
//	const int rows = pad*2 + 3;
//	const string::size_type cols = greeting.size() + pad*2 + 2;
//
//	//输出一个空白行，将输出和输入分开
//	cout << endl;
//
//	for(int r=0; r != rows; r++){
//	
//		//列
//		string::size_type c = 0;
//		while(c != cols){
//		
//			//是否应该输出问候语
//			if(r == pad+1 && c == pad+1){
//				cout << greeting;
//				c += greeting.size();
//			} else {
//				if(r == 0 || r == rows-1 || c == 0 || c == cols-1){
//					cout << "*";
//				} else {
//					cout << " ";
//				}
//				++c;
//			}
//		}
//		//一行结束
//		cout << endl;
//	}
//	return 0;
//}