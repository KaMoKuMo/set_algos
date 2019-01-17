#ifndef __INCLUDES__HPP
#define __INCLUDES__HPP

#include"first_element_intersection.hpp"
namespace set_algos{
	template<typename InputIterator1, typename InputIterator2>
	inline bool set_include(InputIterator1 f1, InputIterator1 l1,
			InputIterator2	f2, InputIterator2 l2)
	{
		return first_element_difference(f1,l1,f2,l2).first == l1;
	}
}
#endif
