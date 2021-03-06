//#pragma once
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<map>
//#include<string>
//#include<iterator>
//
//template <class OutputIterator>
//OutputIterator xref(std::istream& in,
//	                void find_words(const std::string&, std::back_insert_iterator<std::vector<std::string> >), 
//	                OutputIterator d){
//	std::string line;
//	int line_num = 0;
//	std::map<std::string, std::vector<int> > ret;
//	
// 	while(getline(in, line)){
//		++line_num;
//
//		std::vector<std::string> words;
//		find_words(line, back_inserter(words));
//
//		for(std::vector<std::string>::const_iterator i = words.begin(); i != words.end(); ++i){
//			ret[*i].push_back(line_num);
//		}
//	}
//	copy(ret.begin(), ret.end(), d);
//	return d;
//}
//
//// adapter to attach map<string, vector<int>> output iterator to std out
//template <class T, class charT = char, class traits = std::char_traits<charT> >
//class my_ostream_iterator :
//  public std::iterator<std::output_iterator_tag, void, void, void, void>
//{
//  std::basic_ostream<charT, traits>* out_stream;
//  const charT* delim;
//
//public:
//  typedef charT char_type;
//  typedef traits traits_type;
//  typedef std::basic_ostream<charT, traits> ostream_type;
//  my_ostream_iterator(ostream_type& s) : out_stream(&s), delim(0) {}
//  my_ostream_iterator(ostream_type& s, const charT* delimiter)
//    : out_stream(&s), delim(delimiter) { }
//  my_ostream_iterator(const my_ostream_iterator<T, charT, traits>& x)
//    : out_stream(x.out_stream), delim(x.delim) {}
//  ~my_ostream_iterator() {}
//
//  // print pair<string, vector<int>> to std out
//  my_ostream_iterator<T, charT, traits>& operator=(const T& value) {
//    *out_stream << value.first << ": ";
//    for (int i = 0; i != value.second.size(); ++i)
//      *out_stream << value.second[i] << delim;
//    *out_stream << std::endl;
//    return *this;
//  }
//
//  my_ostream_iterator<T, charT, traits>& operator*() { return *this; }
//  my_ostream_iterator<T, charT, traits>& operator++() { return *this; }
//  my_ostream_iterator<T, charT, traits>& operator++(int) { return *this; }
//};