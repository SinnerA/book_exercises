#pragma once

#include<algorithm>
#include<memory>
#include<cstddef>

template <class T>
class Vec{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;
	typedef std::ptrdiff_t difference_type;

	//构造函数
	Vec(){ create();};
	explicit Vec(size_type n, const T& val = T()){create(n, val);}
	//复制构造函数
	Vec(const Vec& v){ create(v.begin(), v.end()); }

	//赋值运算符
	Vec& operator=(const Vec&);

	//析构函数
	~Vec(){ uncreate();}
	
	//大小与索引
	size_type size() const {return avail-data;}

	T& operator[](size_type i){return data[i];}
	const T& operator[](size_type i) const {return data[i];}
	
	//返回迭代器
	iterator begin(){return data;}
	const iterator begin() const {return data;}

	iterator end(){return avail;}
	const iterator end() const {return avail;}

	void push_back(const T& val){
		if(avail == limit){
			grow();
		}
		unchecked_append(val);
	}

	//清理
	void clear() { uncreate(); }
	
	bool empty() const{return data == avail;}
	
	iterator erase(iterator position){
		//整体前移一个位置
		for(iterator i = position; i != avail; ++i){
			alloc.destory(i);
			if((i+1) != avail){
				alloc.construct(i, *(++i));
			}
		}
		--avail;
		return position;
	}

private:
	iterator data;
	iterator avail;
	iterator limit;

	//内存分配工具
	allocator<T> alloc;

	//为底层数组分配空间并初始化
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	//删除数组中元素并释放其占用内存
	uncreate();

	//支持push_back的函数
	void grow();
	void uncheck_append(const T&);
};

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs){
	//判断是否进行自我赋值
	if(&rhs != this){
		uncreate();
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

template <class T>
void Vec<T>::create(){
	data = limit = avail = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T& val){
	data = alloc.allocate(n);
	limit = avail = data + n;
	uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator begin, const_iterator end){
	data = alloc.allocate(end - begin);
	limit = avail = uninitialized_copy(begin, end, data);
}

template <class T>
void Vec<T>::uncreate(){
	if(data){
		//相反顺序，删除元素
		iterator it = avail;
		while(it != data){
			alloc.destory(--it);
		}

		//释放所有占有的内存空间
		alloc.deallocate(data, limit - data);
	}
	data = limit = avail = 0;
}

template <class T>
void Vec<T>::grow(){
	//扩展大小时，分配实际使用2倍大小的内存空间
	size_type new_size = max(2*(limit - data), ptrdiff_t(1));
	//分配新的空间，并将原来对象元素复制到新空间中
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = uninitialed_copy(data, avail, new_data);

	//释放原来内存空间
	uncreate();

	//重置指针
	data = new_data;
	avail = new_avail;
	limit = new_data + new_size;
}

template <class T>
void Vec<T>::uncheck_append(const T& val){
	alloc.construct(avail++, val);
}
