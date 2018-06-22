#include <iostream>
#include <BSTree.hpp>
#include <fstream>
#include <functional>

int main()
{
	std::ifstream is("input");
	BSTree tree(is);
/*	int d = 0;
	while(is >> d) {
		tree.insert(d);
	}
	*/
	std::function<void(int)> f = [](int d)
	{
		std::cout << d << " ";
	};
	std::cout << "mid iter" << std::endl;
	tree.midIter(f);
	std::cout << std::endl;
	std::cout << "prev iter" << std::endl;
	tree.prevIter(f);
	std::cout << std::endl;
	return 0;
}
