#include"include/first_element_intersection.hpp"
#include<vector>
#include<iostream>

using container = std::vector<int>;

int main(){
	container v,v2;
	v = {1,2,6};
	v2 = {3,4,6,8};
	auto it = set_algos::first_element_intersection(v.begin(),v.end(),
			v2.begin(),v2.end());
	std::cout<<*it<<'\n';
}
