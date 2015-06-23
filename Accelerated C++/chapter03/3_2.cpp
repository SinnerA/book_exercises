//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//
//using std::cout;
//using std::cin;
//using std::endl;
//using std::string;
//using std::vector;
//
//int main(){
//
//	//提示
//	cout << "Please enter some numbers, "
//		    "followed by end-of-file: ";
//	
//	//数字序列
//	vector<int> numbers;
//	int x;
//	while(cin >> x){
//		numbers.push_back(x);
//	}
//
//	//排序
//	sort(numbers.begin(), numbers.end());
//	
//	//分组
//	typedef vector<int>::size_type vc_size;
//	vc_size size = numbers.size();
//
//	//4个部分
//	vc_size i = 0;
//	vector<int> numbers1, numbers2, numbers3, numbers4;
//	while(i != size){
//		if(i < size/4)
//			numbers1.push_back(numbers[i]);
//		else if(i >= size/4 && i < size/2)
//			numbers2.push_back(numbers[i]);
//		else if(i >= size/2 && i < size*3/4)
//			numbers3.push_back(numbers[i]);
//		else
//			numbers4.push_back(numbers[i]);
//		++i;
//	}
//
//	//输出4个序列
//	i = 0;
//	cout << "numbers1 is: ";
//	while(i < numbers1.size())
//		cout << numbers1[i++] << " ";
//	cout << endl;
//
//	i = 0;
//	cout << "numbers2 is: ";
//	while(i < numbers2.size())
//		cout << numbers2[i++] << " ";
//	cout << endl;
//
//	i = 0;
//	cout << "numbers3 is: ";
//	while(i < numbers3.size())
//		cout << numbers3[i++] << " ";
//	cout << endl;
//
//	i = 0;
//	cout << "numbers4 is: ";
//	while(i < numbers4.size())
//		cout << numbers4[i++] << " ";
//	cout << endl;
//
//	return 0;
//}