//#include<iostream>
//#include"List.h"
//
//using namespace std;
//
//int main(){
//	List<int> l0 = List<int>();
//	int arr1[] = {1, 2};
//	List<int> l1 = List<int>(arr1, arr1 + 2);
//	int arr2[] = {1, 2};
//	List<int> l2 = List<int>(arr2, arr2 + 2);
//	List<int> l3 = append(l1, l2);
//
//	cout << l0 << endl;
//	cout << is_null(l0) << endl;
//	cout << l1 << endl;
//	cout << list_ref(l1, 0) << endl;
//	cout << list_ref(l1, 1) << endl;
//	cout << l3 << endl;
//	cout << reverse(l3) << endl;
//	cout << member(2, l3) << endl;
//	cout << member(0, l3) << endl;
//
//	cout << cons(l1, cons(l2, List<List<int> >())) << endl;
//
//	return 0;
//}