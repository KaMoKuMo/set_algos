#ifndef __FIND_FIRST__HPP
#define __FIND_FIRST__HPP

namespace set_algos{
	
	enum class WhichSet:char{first,both,exor};
/* General purpose algorithm to traverse up to point where the predicate
 * (implicitly given by the comparison and the WhichSet choice) is met. 
 *	The return type is chosen to be a pair of iterators, similar to the search
 *	algorithms in std. 
 */
	template<class InputIterator1, class InputIterator2, class Comparison, WhichSet decision>
		auto find_first(InputIterator1 f1, InputIterator1 l1,
				InputIterator2 f2, InputIterator2 l2, Comparison comp){
			while(f1!=l1 && f2!=l2)
			{
				if(comp(*f1,*f2)){
					if constexpr(decision!=WhichSet::both){break;}
					f1++;
				}else if(comp(*f2,*f1)){
					if constexpr(decision==WhichSet::exor){break;}
					f2++;
				}else{
					if constexpr(decision==WhichSet::both){break;}
					f1++;
					f2++;
				}
			}
			return std::make_pair(f1,f2);
		}
}

#endif
