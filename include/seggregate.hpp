#ifndef __SEGGREGATION_OF_SETS_SET_ALGOS__HPP
#define __SEGGREGATION_OF_SETS_SET_ALGOS__HPP

#include<algorithm>
#include<utility>

namespace set_algos{
	//for a serious version of this algorithm please visit the repo:
	//	https://github.com/joboccara/sets/tree/master
	//inplace version
	template<class InputIterator1, class InputIterator2>
	std::pair<InputIterator1,InputIterator2> set_seggregation
	(InputIterator1 f1, InputIterator1 l1, InputIterator2 f2, InputIterator2 l2)
	{
		auto m1 = f1;
		auto m2 = f2;
		while(f1!=l1 && f2!=l2)
		{
			if((*f1)<(*f2)){
				f1++;
			}else{
				if((*f2)<(*f1)){
					f2++;
				}else{
					std::rotate(m1++,f1,f1+1);
					std::rotate(m2++,f2,f2+1);
					f1++;
					f2++;
				}
			}
		}
		return std::make_pair(m1,m2);
	}

	//For the output version: Since the intersection of the set is unknown
	//writting into more than one set would need resizing of all these sets.
	//However, for a single set the upper bound of the size is given by the added
	//sizes. Therefore the output version writes into one location assuming this
	//size. The output container will be partitioned according to:
	// set1/set2 | intersection | set2/set1
	// in which "/" denotes the set difference operation. And will return three
	// Iterators:
	// 	1. beginning of intersection
	// 	2. end of intersection/beginning of set2/set1
	// 	3. end of set2/set1.
	//enableling easy splitting of the three disjoint sets. 
	template<class OutputIterator>
	struct IteratorTriplet{
		OutputIterator f1,f2,f3;
		IteratorTriplet(OutputIterator _f1,OutputIterator _f2, OutputIterator
				_f3):
			f1(_f1),f2(_f2),f3(_f3){}
	};
	
	//output has size == input1.size + input2.size (a priori the lower limit of size)
	template<class InputIterator1, class InputIterator2, class OutputIterator>
	IteratorTriplet<OutputIterator> set_seggregation(InputIterator1 f1, InputIterator1 l1,
			InputIterator2 f2, InputIterator2 l2,
	 		OutputIterator f3)
	{
		auto m1 = f3 + (l1 - f1);
		auto end_intersect = m1;

		auto m2 = m1 + (l2 - f2) - 1;
		const auto end_of_output = m2+1;
		
		while(f1!=l1 && f2!=l2)
		{
			if((*f1)<(*f2)){
				*f3 = *f1;
				f1++;
				f3++;
			}else{
				if((*f2)<(*f1)){
					*m1 = *f2;
					f2++;
					m1++;
				}else{
					*m2 = *f1;
					f1++;
					f2++;
					m2--;
				}
			}
		}
		f3 = std::copy(f1,l1,f3);
		m1 = std::copy(f2,l2,m1);
		m2 = std::reverse_copy(m2+1,end_of_output,f3);

		return IteratorTriplet<OutputIterator>(f3,end_intersect,m1);
	}
}
#endif
