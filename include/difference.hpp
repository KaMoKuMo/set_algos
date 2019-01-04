#ifndef __SET_ALGO_DIFFERENCE__HPP
#define __SET_ALGO_DIFFERENCE__HPP

//playing purpose only!! not to be used in real code

#include"first_element_difference.hpp"
#include<functional>
#include<algorithm>
namespace set_algos{

	template<class InputIterator1, class InputIterator2, class OutputIterator,
		class Comparison = std::less<> >
		OutputIterator difference(InputIterator1 f1, InputIterator1 l1,
				InputIterator2 f2, InputIterator2 l2, OutputIterator o1, 
				Comparison comp = Comparison())
		{
			for(;;)
			{
				if(auto [m1,m2] = first_element_difference(f1,l1,f2,l2);
						m1!=l1 && m2!=l2){
					*o1 = *m1;
					o1++;
					f1 = ++m1;
					f2 = ++m2;
				}
				else{
					break;
				}
			}
			o1 = std::copy(f1,l1,o1);
			return o1;
		}
	
}

#endif
