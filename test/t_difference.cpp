#include<vector>
#include<iostream>
#include"../include/difference.hpp"

using container = std::vector<int>;
void print(container v){
	for(auto val: v){
		std::cout<<val<<'\t';
	}
	std::cout<<'\n';
}

int main(){
	container v1,v2;
	v1 = {1,2,6,8,10,11,15};
	v2 = {3,4,6,8,8,18};
	container v3(v1.size());

	set_algos::difference(v1.begin(),v1.end()
			,v2.begin(),v2.end(),v3.begin());

	print(v1);
	print(v2);
	print(v3);
}

