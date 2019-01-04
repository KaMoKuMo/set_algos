#ifndef __SET_SHARE_ELEMENT__HPP
#define __SET_SHARE_ELEMENT__HPP

#include"first_element_intersection.hpp"
namespace set_algos{
	template<typename InputIterator1, typename InputIterator2>
	bool set_share_element(InputIterator1 f1, InputIterator1 l1,
			InputIterator2	f2, InputIterator2 l2)
	{
		return first_element_intersection(f1,l1,f2,l2).first != l1;
	}
}
#endif
