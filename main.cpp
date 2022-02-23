#include <iostream>
#include "MyOwnList.h"

using namespace std;
using namespace Linked_List;

int main()
{
	list<int> lst;
	list<int>::Iterator it;
	lst.push_back(0);
	lst.push_back(1);
	lst.push_back(2);
	it = lst.begin();
	it++;
	it++;
	//cout << *it;
}