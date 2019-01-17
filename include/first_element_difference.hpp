#ifndef __FIRST_ELEMENT_IN_DIFFERENCE__HPP
#define __FIRST_ELEMENT_IN_DIFFERENCE__HPP

#include<functional>
#include"detail/find_first.hpp"
namespace set_algos{

	template<class InputIterator1, class InputIterator2, class Comparison =
		std::less<> >
		auto first_element_difference(InputIterator1 f1, InputIterator1 l1,
				InputIterator2 f2, InputIterator2 l2, Comparison comp = Comparison()){
			return find_first<InputIterator1, InputIterator2,
			Comparison,WhichSet::first>(f1,l1,f2,l2,comp);
		}
	
}
#endif
