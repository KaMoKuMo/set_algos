#ifndef __SET_SHARE_ELEMENT__HPP
#define __SET_SHARE_ELEMENT__HPP

namespace set_algos{
	template<typename InputIterator1, typename InputIterator2>
	bool set_share_element(InputIterator1 f1, InputIterator1 l1,
			InputIterator2	f2, InputIterator2 l2)
	{
		while(f1!=l1 && f2!=l2){
			if(*f1 < *f2) f1++;
			else if(*f2 < *f1) f2++;
			else return true;
		}
		return false;
	}
}
#endif
