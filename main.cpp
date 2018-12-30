#include"include/seggregate.hpp"

#include<vector>
#include<iostream>

using container = std::vector<int>;
void print(container v){
	for(auto val: v){
		std::cout<<val<<'\t';
	}
	std::cout<<'\n';
}

int main(){
	container v1,v2;
	v1 = {1,2,6};
	v2 = {3,4,6,8};
	container v3(v1.size()+v2.size());

	auto [it,it2,it3] = set_algos::set_seggregation(v1.begin(),v1.end()
			,v2.begin(),v2.end(),v3.begin());

	print(v1);
	print(v2);
	print(v3);

	std::cout<<*it<<'\t'<<*it2<<'\t'<<*it3<<'\n';

}

