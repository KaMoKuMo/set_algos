#ifndef __EARLY_EXIT_CODE__HPP
#define __EARLY_EXIT_CODE__HPP

namespace set_algos{

	enum class WhichSet{first,second,both};

	template<class InputIterator1, class InputIterator2, class Comparison, WhichSet decision>
		auto early_exit(InputIterator1 f1, InputIterator1 l1,
				InputIterator2 f2, InputIterator2 l2, Comparison comp){
			while(f1!=l1 && f2!=l2)
			{
				if(comp(*f1,*f2)){
					if constexpr(decision==WhichSet::first){ return f1;}
					f1++;
				}else if(comp(*f2,*f1)){
					if constexpr(decision==WhichSet::second){ return f2;}
					f2++;
				}else{
					if constexpr(decision==WhichSet::both){ return f1;}
					f1++;
					f2++;
				}
			}
			if constexpr(decision==WhichSet::second) return l2;
			else return l1;
		}
}

#endif
