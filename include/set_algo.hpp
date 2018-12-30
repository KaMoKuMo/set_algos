#ifndef __GENEARL_SCHEME__HPP
#define __GENEARL_SCHEME__HPP

namespace set_algo{

	//Possible output iterators are contained in the temporary Operator classes
	template<class Iterator,class Observer,class Operator_1,class Operator_2, class Operator_3> 
	general_scheme(Iterator f1, Iterator l1, Iterator f2, Iterator f3,Observer)
	{
		bool not_done = true;
		Observer.allow_update(not_done);//take reference

		while(f1!=l1 && f2!=l2 && not_done)
		{
			if(*f1<*f2)
			{
				Operator_1(*f1);//if done set not_done = false through Observer
				f1++;
			}
			else if(*f2 < *f1)
			{
				Operator_2(*f2);//if done set not_done = false through Observer
				f2++;
			}
			else
			{
				Operator_3(*f1);//if done set not_done = false through Observer
				f1++;
				f2++;
			}
		}
		//For the motivation of these methods see seggregate with output.  
		Operator_1.final_op(f1);
		Operator_2.final_op(f2);
		Operator_3.final_op(f3);

		//return type is a hard one
		return 
	}

}
#endif
