//#include<iostream>
//#include<vector>
//
//#include"10_2.hpp"
//
//using namespace std;
//
//int main(){
//	int test_arr[] = {1, 2, 8, 4, 5, 6, 7, 3, 9, 10};
//	vector<int> test_vec(test_arr, test_arr + 10);
//
//	//数组
//	cout << "Median: " <<  median<int>(test_arr, test_arr + 10) << endl;
//	cout << "test_arr: ";
//	for(size_t i = 0; i != 10; ++i){
//		cout << test_arr[i];
//	}
//	cout << endl;
//
//	//向量
//	cout << "Median: " << median<int>(test_vec.begin(), test_vec.end()) << endl;
//	cout << "test_vec: ";
//	for(size_t i = 0; i != test_vec.size(); ++i){
//		cout << test_vec[i];
//	}
//	cout << endl;
//	return 0;
//}