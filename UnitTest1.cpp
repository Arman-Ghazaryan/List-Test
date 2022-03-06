#include "pch.h"
#include "CppUnitTest.h"
#include "..\Link-List\list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(Default)
		{ 
			list<int> lst;
			list<int>::Iterator it;
			Assert::IsTrue(lst.begin() == NULL);
			Assert::IsTrue(lst.end() == NULL);
			Assert::IsTrue(lst.getSize() == 0);
			Assert::IsTrue(it == NULL);
			
			list<int> lst1(3);
			list<int> lst2(3, 7);
			list<int> lst3({ 0,1,2 });

			for (int i = 0; i < lst1.getSize(); i++)
			{
				Assert::AreEqual(lst1[i], 0, L"list(count) unsuccess");
				Assert::AreEqual(lst2[i], 7, L"list(count, data) unsuccess");
				Assert::AreEqual(lst3[i], i, L"list(vector) unsuccess");
			}
		}
		TEST_METHOD(Functions)
		{
			list<int> lst;
			list<int>::Iterator it;
			lst.push_back(0);
			Assert::AreEqual(lst.back(), 0, L"push_back(data) unsuccess");
			lst.push_back({ 1,2,3 });
			int i = 1;
			for (it = lst.begin(); it != lst.end(); i++)
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
		TEST_METHOD(Insert)
		{
			list<int> lst;
			list<int> lst1({1,2,3,4,5});
			list<int>::Iterator it;
			
			lst.insert(1, 0);
			lst.insert(1, lst.begin());
			lst.insert(2, 2, 0);
			lst.insert(2, 2, lst.begin());
			lst.insert({ 3,3,3 }, 0);
			lst.insert({ 3,3,3 }, lst.begin());

			for (int i = 3, j = 0, k = 0; i >= 1; i--)
			{
				for (; j < k + i * 2; j++)
				{
					Assert::AreEqual(lst[j], i, L"insert from begin unsuccess");
				}
				k = j;
			}

			lst.clear();
			lst.insert(1, 0);
			lst.insert(1, lst.end());
			lst.insert(2, 2, 1);
			lst.insert(2, 2, lst.end());
			lst.insert({ 3,3,3 }, 5);
			lst.insert({ 3,3,3 }, lst.end());

			for (int i = 1, j = 0, k = 0; i <= 3; i++)
			{
				for (; j < k + i * 2; j++)
				{
					Assert::AreEqual(lst[j], i, L"insert from end unsuccess");
				}
				k = j;
			}

			lst.insert(1, 1);
			it = lst.begin();
			it++;
			lst.insert(1, it);
			lst.insert(2, 2, 1);
			it = lst.begin();
			it++;
			lst.insert(2, 2, it);
			lst.insert({ 3,3,3 }, 1);
			it = lst.begin();
			it++;
			lst.insert({ 3,3,3 }, it);

			for (int i = 3, j = 0, k = 0; i >= 1; i--)
			{
				for (; j < k + i * 2; j++)
				{
					Assert::AreEqual(lst[j + 1], i, L"insert from middle unsuccess");
				}
				k = j;
			}
		}
	};
}
