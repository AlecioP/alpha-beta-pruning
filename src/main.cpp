#include <iostream>
#include "minmax.hpp"

using namespace minmax;

int main(int argc, char *argv[])
{
	Node l1 = Node(10,nullptr,nullptr);
	Node l2 = Node(5,nullptr,nullptr);
		Node lv3_1 = Node(-1,&l1,&l2);
	Node l3 = Node(7,nullptr,nullptr);
	Node l4 = Node(11,nullptr,nullptr);
		Node lv3_2 = Node(-2,&l3,&l4);
				Node lv2_1 = Node(-10,&lv3_1,&lv3_2);
	Node l5 = Node(12,nullptr,nullptr);
	Node l6 = Node(8,nullptr,nullptr);
		Node lv3_3 = Node(-3,&l5,&l6);
	Node l7 = Node(9,nullptr,nullptr);
	Node l8 = Node(8,nullptr,nullptr);
		Node lv3_4 = Node(-4,&l7,&l8);
				Node lv2_2 = Node(-20,&lv3_3,&lv3_4);
					Node lv1_1 = Node(-100,&lv2_1,&lv2_2);
	Node l9 = Node(5,nullptr,nullptr);
	Node l10 = Node(12,nullptr,nullptr);
		Node lv3_5 = Node(-5,&l9,&l10);
	Node l11 = Node(11,nullptr,nullptr);
	Node l12 = Node(12,nullptr,nullptr);
		Node lv3_6 = Node(-6,&l11,&l12);
				Node lv2_3 = Node(-30,&lv3_5,&lv3_6);
	Node l13 = Node(9,nullptr,nullptr);
	Node l14 = Node(8,nullptr,nullptr);
		Node lv3_7 = Node(-7,&l13,&l14);
	Node l15 = Node(7,nullptr,nullptr);
	Node l16 = Node(10,nullptr,nullptr);
		Node lv3_8 = Node(-8,&l15,&l16);
				Node lv2_4 = Node(-40,&lv3_7,&lv3_8);
					Node lv1_2 = Node(-200,&lv2_3,&lv2_4);
						Node lv0_1 = Node(-1000,&lv1_1,&lv1_2);

	Node* tree = &lv0_1;

	std::cout<<"Depth "<<tree->height()<<std::endl;

	std::cout<<"Min_max result: "<<tree->min_max()<<std::endl;
	std::cout<<"Alpha_beta result: "<<tree->alpha_beta()<<std::endl;

	std::string * txt_tree = tree->str();
	if(txt_tree == nullptr)
		std::cout<<"stringa vuota"<<std::endl;
	std::cout<<"Albero"<<std::endl<<(*txt_tree)<<std::endl;

	delete txt_tree;

	return 0;
}

