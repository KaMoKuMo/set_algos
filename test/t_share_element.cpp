#include<vector>
#include<iostream>
#include"../include/share_element.hpp"

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
	
	if(set_algos::set_share_element(v1.begin(),v1.end(),v2.begin(),v2.end())){
		std::cout<<"TRUE\n";
	}else{ std::cout<<"FAIL\n";}
	if(!set_algos::set_share_element(v1.begin(),v1.end(),v2.begin(),v2.begin()+1)){
		std::cout<<"TRUE\n";
	}else{ std::cout<<"FAIL\n";}
	
	print(v1);
	print(v2);

}

