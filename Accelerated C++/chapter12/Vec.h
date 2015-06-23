//#pragma once
//
//#include<algorithm>
//#include<memory>
//#include<cstddef>
//
//template <class T>
//class Vec{
//public:
//	typedef T* iterator;
//	typedef const T* const_iterator;
//	typedef size_t size_type;
//	typedef T value_type;
//	typedef T& reference;
//	typedef const T& const_reference;
//	typedef std::ptrdiff_t difference_type;
//
//	//���캯��
//	Vec(){ create();}
//	explicit Vec(size_type n, const T& val = T()){create(n, val);}
//	template <class In> Vec(In i, In j){ create(i , j); }
//
//	//���ƹ��캯��
//	Vec(const Vec& v){ create(v.begin(), v.end()); }
//
//	//��ֵ�����
//	Vec& operator=(const Vec&);
//
//	//��������
//	~Vec(){ uncreate();}
//	
//	//��С������
//	size_type size() const {return avail-data;}
//
//	T& operator[](size_type i){return data[i];}
//	const T& operator[](size_type i) const {return data[i];}
//	
//	//���ص�����
//	iterator begin(){return data;}
//	const iterator begin() const {return data;}
//
//	iterator end(){return avail;}
//	const iterator end() const {return avail;}
//
//	void push_back(const T& val){
//		if(avail == limit){
//			grow();
//		}
//		unchecked_append(val);
//	}
//
//	//����
//	void clear() { uncreate(); }
//	bool empty() const{return data == avail;}
//
//	iterator erase(iterator position){
//		//����ǰ��һ��λ��
//		for(iterator i = position; i != avail; ++i){
//			alloc.destory(i);
//			if((i+1) != avail){
//				alloc.construct(i, *(++i));
//			}
//		}
//		--avail;
//		return position;
//	}
//
//	template <class In> void insert(iterator, In ,In);
//	template <class In> void assign(In, In);
//
//private:
//	iterator data;
//	iterator avail;
//	iterator limit;
//
//	//�ڴ���乤��
//	std::allocator<T> alloc;
//
//	//Ϊ�ײ��������ռ䲢��ʼ��
//	void create();
//	void create(size_type, const T&);
//	void create(const_iterator, const_iterator);
//
//	//ɾ��������Ԫ�ز��ͷ���ռ���ڴ�
//	void uncreate();
//
//	//֧��push_back�ĺ���
//	void grow();
//	void uncheck_append(const T&);
//};
//
////Class Public functions------------------------------------------------------------------------------
//template <class T>
//Vec<T>& Vec<T>::operator=(const Vec& rhs){
//	//�ж��Ƿ�������Ҹ�ֵ
//	if(&rhs != this){
//		uncreate();
//		create(rhs.begin(), rhs.end());
//	}
//	return *this;
//}
//
//template <class T> 
//template <class In> void Vec<T>::insert(iterator p, In i, In j){
//	size_type new_length = (avail - data) + (j - i);
//	iterator new_data = alloc.allocate(new_length);
//	uninitialized_copy(data, p, new_data);
//	uninitialized_copy(i, j, new_data + (p - data));
//	iterator new_avail = uninitialized_copy(p, avail, new_data + (p - data) + (j - i));
//
//	uncreate();
//
//	data = new_data;
//	avail = new_avail;
//	limit = data + new_length;
//}
//
//template <class T>
//template <class In> void Vec<T>::assign(In i, In j){
//	uncreate();
//	create(i , j);
//}
//
//
////Class Private functions------------------------------------------------------------------------------
//template <class T>
//void Vec<T>::create(){
//	data = limit = avail = 0;
//}
//
//template <class T>
//void Vec<T>::create(size_type n, const T& val){
//	data = alloc.allocate(n);
//	limit = avail = data + n;
//	uninitialized_fill(data, limit, val);
//}
//
//template <class T>
//void Vec<T>::create(const_iterator begin, const_iterator end){
//	data = alloc.allocate(end - begin);
//	limit = avail = uninitialized_copy(begin, end, data);
//}
//
//template <class T>
//void Vec<T>::uncreate(){
//	if(data){
//		iterator it = avail;
//		while(it != data){
//			alloc.destory(--it);
//		}
//		
//		alloc.deallocate(data, limit - data);
//	}
//	data = limit = avail = 0;
//}
//
//template <class T>
//void Vec<T>::grow(){
//	//��չ��Сʱ������ʵ��ʹ��2����С���ڴ�ռ�
//	size_type new_size = max(2*(limit - data), ptrdiff_t(1));
//	//�����µĿռ䣬����ԭ������Ԫ�ظ��Ƶ��¿ռ���
//	iterator new_data = alloc.allocate(new_size);
//	iterator new_avail = uninitialed_copy(data, avail, new_data);
//
//	//�ͷ�ԭ���ڴ�ռ�
//	uncreate();
//
//	//����ָ��
//	data = new_data;
//	avail = new_avail;
//	limit = new_data + new_size;
//}
//
//template <class T>
//void Vec<T>::uncheck_append(const T& val){
//	alloc.construct(avail++, val);
//}