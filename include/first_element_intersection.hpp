#ifndef __FIRST_ELEMENT_IN_INTERSECTION__HPP
#define __FIRST_ELEMENT_IN_INTERSECTION__HPP

#include<functional>
#include"early_exit.hpp"
namespace set_algos{

	template<class InputIterator1, class InputIterator2, class Comparison =
		std::less<> >
		InputIterator1 first_element_intersection(InputIterator1 f1, InputIterator1 l1,
				InputIterator2 f2, InputIterator2 l2, Comparison comp = Comparison()){
			return early_exit<InputIterator1, InputIterator2,
			Comparison,WhichSet::both>(f1,l1,f2,l2,comp);
		}
	
}
#endif
