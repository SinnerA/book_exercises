//#pragma once
//
//#include<algorithm>
//#include<iterator>
//
//template <class InputIterator1, class InputIterator2> 
//bool my_equal(InputIterator1 b, InputIterator1 e, InputIterator2 b2){
//	while(b != e){
//		if(*b++ != *b2++){
//			return false;
//		}
//	}
//	return true;
//}
//
//template <class ForwardIterator1, class ForwardIterator2>
//ForwardIterator1 my_search(ForwardIterator1 b, ForwardIterator1 e, ForwardIterator2 b2, ForwardIterator2 e2){
//	while(b != e){
//		if(my_equal(b2, e2, b)){
//			return b;
//		}
//		++b;
//	}
//	return e;
//}
//
//template <class InputIterator, class Type>
//InputIterator my_find(InputIterator b, InputIterator e, const Type& t){
//	while(b != e){
//		if(*b == x){
//			return b;
//		}
//		++b;
//	}
//	return e;
//}
//
//template <class InputIterator, class Predicate>
//InputIterator my_find_if(InputIterator b, InputIterator e, Predicate p){
//	while(b != e){
//		if(f(*b)){
//			return b;
//		}
//		++b;
//	}
//	return e;
//}
//
//template <class InputIterator, class OutputIterator>
//OutputIterator my_copy(InputIterator b, InputIterator e, OutputIterator d){
//	while(b != e){
//		*d++ = *b++;
//	}
//	return d;
//}
//
//template <class InputIterator, class OutputIterator, class Type>
//OutputIterator my_remove_copy(InputIterator b, InputIterator e, OutputIterator d, const Type& t){
//	while(b != e){
//		if(*b != x){
//			*d++ = *b;
//		}
//		++b;
//	}
//	return d;
//}
//
//template <class InputIterator, class OutputIterator, class Predicate>
//OutputIterator my_remove_copy_if(InputIterator b, InputIterator e, OutputIterator d, Predicate p){
//	while(b != e){
//		if(!p(*b)){
//			*d++ = *b;
//		}
//		++b;
//	}
//	return d;
//}
//
//template <class ForwardIterator, class Type>
//ForwardIterator my_remove(ForwardIterator b, ForwardIterator e, const Type& t){
//	//first_failure指向最后一个不等于p的元素后面一个位置
//	ForwardIterator first_failure = b;
//	while(b != e){
//		if(*b != t){
//			*first_failure++ = *b;
//		}
//		++b;
//	}
//	return first_failure;
//}
//
//template <class InputIterator, class OutputIterator, class Function>
//OutputIterator my_transform(InputIterator b, InputIterator e, OutputIterator d, Function f){
//	while(b != e){
//		*d++ = f(*b++);
//	}
//	return d;
//}
//
//template <class ForwardIterator, class Predicate>
//ForwardIterator my_partition(ForwardIterator b, ForwardIterator e, Predicate p){
//	//first_failure指向最后一个符合p的元素后面一个位置
//	ForwardIterator first_failure = b;
//	while(b != e){
//		if(p(*b)){
//			swap(*first_failure++, *b);
//		}
//		++b;
//	}
//	return first_failure;
//}
//
//template <class InputIterator, class Type>
//Type my_accumulate(InputIterator b, InputIterator e, Type& t){
//	while(b != e){
//		t += *b++;
//	}
//	return t;
//}
