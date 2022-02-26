#include "pch.h"
#include "CppUnitTest.h"
#include "..\Link-List\list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		list<int> lst;
		list<int>::Iterator it;
		TEST_METHOD(Default)
		{ 
			Assert::IsTrue(lst.begin() == NULL);
			Assert::IsTrue(lst.end() == NULL);
			Assert::IsTrue(lst.getSize() == 0);
			Assert::IsTrue(it == NULL);
		}
		TEST_METHOD(Functions)
		{
			lst.push_back(0);
			Assert::AreEqual(lst.back(), 0, L"push_back(data) unsuccess");
			lst.push_back({ 1,2,3 });
			int i = 1;
			for (it = lst.begin(); it <= lst.end(); i++)
			{
				it++;
				Assert::AreEqual(*it, i, L"push_back(vector) unsuccess");
			}
			lst.push_front(1);
			Assert::AreEqual(lst.front(), 1, L"push_front(data) unsuccess");

			Assert::AreEqual(lst[0], 1, L"operator[] unsuccess");
			Assert::AreEqual(lst.front(), 1, L"front() unsuccess");
			Assert::AreEqual(lst.back(), 3, L"back() unsuccess");

			lst.insert(4, 3);
			Assert::AreEqual(lst[3], 4, L"insert(data, position) unsuccess");

			Assert::AreEqual(lst.getSize(), 6, L"getSize() unsuccess");

			lst.clear();
			Assert::IsTrue(lst.getSize() == 0, L"clear() unsuccess");

			lst.insert({ 0,1,2 }, 0);
			for (i = 0; i < 3; i++)
			{
				Assert::AreEqual(lst[i], i, L"insert(vector, position) unsuccess");
			}

			lst.clear();
			lst.insert(3, 3, 0);
			it = lst.begin();
			for (int i = 0; i < 3; i++, it++)
			{
				Assert::AreEqual(*it, 3, L"insert(data, count, position) unsuccess");
			}

			lst.removeAt(1);
			Assert::IsTrue(lst.getSize() == 2, L"removeAt() unsuccess");

			lst.pop_back();
			Assert::IsTrue(lst.getSize() == 1, L"pop_back() unsuccess");

			lst.pop_front();
			Assert::IsTrue(lst.getSize() == 0, L"pop_front() unsuccess");
			
			Assert::AreEqual(lst.empty(), false, L"empty() unsuccess");
		}
	};
}
