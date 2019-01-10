#ifndef __FIND_FIRST__HPP
#define __FIND_FIRST__HPP

namespace set_algos{
	
	enum class WhichSet:char{first,both};
/* General purpose algorithm to traverse up to point where the predicate
 * (implicitly given by the comparison and the WhichSet choice) is met. 
 *	The return type is chosen to be a pair of iterators, similar to the search
 *	algorithms in std. 
 *  If the predicate can not be fulfilled within the given ranges, the position
 *  of the Iterators is chosen to depending on the WhichSet decision:
 *	1. 
 				For decision == WhichSet::first this implies that the smaller ( or of equal
				size) range is completely included within the other range. The
				Iterators are chosen to point to the location where those ranges would
				diverge (one being at the end, but the other not necessarily).
				The question whether range A is included in range B can be answered
				with 
				return f_a == l_a ;
				afterwards - needing only one additional comparison.
				(The index "a" is either "1" or "2" in the given algorithm below.) 

		2.
				For decision == WhichSet::both this implies that both sets share no
				element. To be able to answer the question whether range A and B share
				at least one element with this algorithm as well, it was chosen that
				both returned iterators should be set to the end position. Making the
				answer 
				return f_1 == l_1; 
				afterwards correct.
 */
	template<class InputIterator1, class InputIterator2, class Comparison, WhichSet decision>
		auto find_first(InputIterator1 f1, InputIterator1 l1,
				InputIterator2 f2, InputIterator2 l2, Comparison comp){
			while(f1!=l1 && f2!=l2)
			{
				if(comp(*f1,*f2)){
					if constexpr(decision==WhichSet::first){ return std::make_pair(f1,f2);}
					f1++;
				}else if(comp(*f2,*f1)){
					f2++;
				}else{
					if constexpr(decision==WhichSet::both){ return std::make_pair(f1,f2);}
					f1++;
					f2++;
				}
			}
			if constexpr(decision==WhichSet::first){
				return std::make_pair(f1,f2);
			}else{
				return std::make_pair(l1,l2);
			}
		}
}

#endif
