//#include<cstdlib>
//#include<stdexcept>
//#include<cmath>
//#include<iostream>
//
//#define MY_RAND_MAX 32767
//
//using namespace std;
//
////返回[0,n)的一个随机整数
//int nrand(int n){
//	if(n <= 0)
//		throw domain_error("Argument to nrand is out of range!");
//	
//	int r;//存储桶的编号
//	if(n <= MY_RAND_MAX){
//		//存储桶大小
//		const int bucket_size = MY_RAND_MAX / n;
//	
//		do
//		  r = rand() / bucket_size;
//		while(r >= n);
//	} else {
//		const int bucket_size = ceil((double)n / MY_RAND_MAX);
//
//		do {
//		  const int bucket = nrand(MY_RAND_MAX);
//		  const int remainder = nrand(bucket_size);
//		  r = (bucket - 1) * bucket_size + remainder;
//		} while (r >= n);
//	}
//	
//	return r;
//}
//
//int main(){
//	int limit;
//	
//	while(cin >> limit){
//		cout << nrand(limit) << endl;
//	}
//	return 0;
//}