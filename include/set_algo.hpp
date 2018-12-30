#ifndef __GENEARL_SCHEME__HPP
#define __GENEARL_SCHEME__HPP

namespace set_algo{
	
	general_scheme(Iterator f1, Iterator l1, Iterator f2, Iterator f3,Observer)
	{
		bool not_done = true;
		Observer.allow_update(not_done);

		while(f1!=l1 && f2!=l2 && not_done)
		{
			if(*f1<*f2)
			{
				Operator_1(*f1);
				f1++;
			}
			else if(*f2 < *f1)
			{
				Operator_2(*f2);
				f2++;
			}
			else
			{
				Operator_3(*f1);
				f1++;
				f2++;
			}
		}
		Operator_1.final_op(f1);
		Operator_2.final_op(f2);
		Operator_3.final_op(f3);

}
#endif
