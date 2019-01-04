#ifndef __SET_ALGO_SYM_DIFFERENCE__HPP
#define __SET_ALGO_SYM_DIFFERENCE__HPP

//playing purpose only!! not to be used in real code

#include"first_element_intersection.hpp"
#include<functional>
#include<algorithm>
namespace set_algos{

	template<class InputIterator1, class InputIterator2,
		class OutputIterator, class OutputIterator2,
		class Comparison = std::less<> >
		auto sym_difference(InputIterator1 f1, InputIterator1 l1,
				InputIterator2 f2, InputIterator2 l2, OutputIterator o1,
				OutputIterator2 o2,
				Comparison comp = Comparison())
		{
			for(;;)
			{
				if(auto [m1,m2] = first_element_intersection(f1,l1,f2,l2);
						m1!=l1 && m2!=l2){
					o1 = std::copy(f1,m1,o1);
					o2 = std::copy(f2,m2,o2);
					f1 = ++m1;
					f2 = ++m2;
				}
				else{
					break;
				}
			}
			o1 = std::copy(f1,l1,o1);
			o2 = std::copy(f2,l2,o2);
			return std::make_pair(o1,o2);
		}
	
}

#endif
