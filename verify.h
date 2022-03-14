#pragma once
#include <iostream>
#include <vector>
#include <string>

template <typename T>
class verify
{
public:
	void verifySize(int pos, string mesg);
	void verifyIter(typename list<T>::Iterator pos, string mesg);
};

template<typename T>
void verify<T>::verifySize(int cond, string mesg)
{
	if (cond)
	{
	}
	else
	{
		cout << mesg;
		exit(cond);
	}
}

template<typename T>
void verify<T>::verifyIter(typename list<T>::Iterator pos, string mesg)
{

}
