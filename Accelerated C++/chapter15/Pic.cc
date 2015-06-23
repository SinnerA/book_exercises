//#include"Pic.h"
//
//using namespace std;
//
////class Picture functions--------------------------------------------------
//Picture::Picture(const Vec<Str>& v):p(new String_Pic(v)){}
//
//Picture frame(const Picture& pic){
//	return new Frame_Pic(pic.p);
//}
//
//Picture hcat(const Picture& l, const Picture& r){
//	return new HCat_Pic(l.p, r.p);
//}
//
//Picture vcat(const Picture& b, const Picture& t){
//	return new VCat_Pic(b.p, t.p);
//}
//
//ostream& operator<<(ostream& os, const Picture& pic){
//	const Pic_base::ht_sz ht = pic.p->height();
//	for(Pic_base::ht_sz i = 0; i != ht; ++i){
//		pic.p->display(os, i, false);
//		os << endl;
//	}
//	return os;
//}
//
////class String_Pic functions----------------------------------------------
//String_Pic::wd_sz String_Pic::width() const{
//	ht_sz ht = data.size();
//	string::size_type maxlength = 0;
//	for(ht_sz i = 0; i != ht; ++i){
//		maxlength = max(maxlength, data[i].size());
//	}
//	return maxlength;
//}
//
//String_Pic::ht_sz String_Pic::height() const{
//	return data.size();
//}
//
//void String_Pic::display(ostream& os, ht_sz row, bool do_pad) const{
//	wd_sz start = 0;
//	if(row < height()){
//		os << data[row];
//		start = data[row].size();
//	}
//
//	//如有必要，填充空格
//	if(do_pad){
//		pad(os, start, width());
//	}
//}
//
////class Frame_Pic functions---------------------------------------------------
//Frame_Pic::wd_sz Frame_Pic::width() const{
//	return p->width() + 4;
//}
//
//Frame_Pic::ht_sz Frame_Pic::height() const{
//	return p->height() + 4;
//}
//
//void Frame_Pic::display(ostream& os, ht_sz row, bool do_pad) const{
//	if(row >= height()){
//		if(do_pad)
//			pad(os, 0, width());
//	} else {
//		if(row == 0 || row == height() - 1){
//			os << corner;
//			os << Str(width() - 2, top_bottom);
//			os << corner;
//		} else if(row == 1 || row == height() - 2){
//			os << slide;
//			pad(os, 1, width() - 1);
//			os << slide;
//		} else {
//			os << slide << " ";
//			p->display(os, row - 2, true);
//			os << " " << slide;
//		}
//	}
//}
//
//void Frame_Pic::reframe(char c, char t_b, char s){
//	p->reframe(c, t_b, s);
//
//	corner = c;
//	top_bottom = t_b;
//	slide = s;
//}
//
////class VCat_Pic functions---------------------------------------------------
//VCat_Pic::wd_sz VCat_Pic::width() const{
//	return max(bottom->width(), top->width());
//}
//
//VCat_Pic::ht_sz VCat_Pic::height() const{
//	return bottom->height() + top->height();
//}
//
//void VCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const{
//	wd_sz start = 0;
//	if(row < top->height()){
//		top->display(os, row, do_pad);
//		start = top->width();
//	} else if(row < height()){
//		bottom->display(os, row - top->height(), do_pad);
//		start = bottom->width();
//	}
//	if(do_pad){
//		pad(os, start, width());
//	}
//}
//
//void VCat_Pic::reframe(char c, char t_b, char s){
//	top->reframe(c, t_b, s);
//	bottom->reframe(c, t_b, s);
//}
//
////class HCat_Pic functions---------------------------------------------------
//HCat_Pic::wd_sz HCat_Pic::width() const{
//	return left->width() + right->width();
//}
//
//HCat_Pic::ht_sz HCat_Pic::height() const{
//	return max(left->height(), right->height());
//}
//
//void HCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const{
//	ht_sz left_row = row;
//	ht_sz right_row = row;
//	if(left->height() < right->height()){
//		ht_sz v_pad = (right->height() - left->height()) / 2;
//		left_row = (row < v_pad) ? left->height() : row - v_pad;
//	} else {
//		ht_sz v_pad = (left->height() - right->height()) / 2;
//		right_row = (row < v_pad) ? right->height() : row - v_pad;
//	}
//
//	left->display(os, left_row, do_pad || row < right->height());
//	right->display(os, right_row, do_pad);
//}
//
//void HCat_Pic::reframe(char c, char t_b, char s){
//	left->reframe(c, t_b, s);
//	right->reframe(c, t_b, s);
//}