#pragma once
#include <iostream>
#include <vector>
#include <string>

template <typename T>
class verify
{
public:
	void verifySize(int pos, string mesg);
	void verifyIter(list<int>::Iterator pos, string mesg);
};