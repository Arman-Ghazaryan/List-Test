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
			Assert::IsTrue(lst.begin() == NULL, L"begin() unsuccess");
			Assert::IsTrue(lst.end() == NULL, L"end() unsuccess");
			Assert::IsTrue(lst.getSize() == 0, L"getSize() unsuccess");
			Assert::IsTrue(it == NULL, L"Iterator() unsuccess");
			Assert::AreEqual(lst.empty(), false, L"empty() unsuccess");
			
			list<int> lst1(3);
			list<int> lst2(3, 7);
			list<int> lst3({ 0,1,2 });

			Assert::IsTrue(lst3.front() == 0, L"front() unsuccess");
			Assert::IsTrue(lst3.back() == 2, L"fback() unsuccess");

			for (int i = 0; i < lst1.getSize(); i++)
			{
				Assert::AreEqual(lst1[i], 0, L"list(count) unsuccess");
				Assert::AreEqual(lst2[i], 7, L"list(count, data) unsuccess");
				Assert::AreEqual(lst3[i], i, L"list(vector) unsuccess");
			}
		}
		TEST_METHOD(Removing_Functions)
		{
			list<int> lst(3, 3);
			vector<int> vec = { 12,35,2,4,35,0,12,35,15,345,355,1,2,3,5,9,6,89,52,34,8 };
			list<int>::Iterator it1, it2;


			lst.removeAt(1);
			Assert::IsTrue(lst.getSize() == 2, L"removeAt() unsuccess");

			lst.pop_back();
			Assert::IsTrue(lst.getSize() == 1, L"pop_back() unsuccess");

			lst.pop_front();
			Assert::IsTrue(lst.getSize() == 0, L"pop_front() unsuccess");

			lst.push_back(vec);
			it1 = lst.begin();
			it2 = lst.end();
			it1++;
			it2--;
			lst.erase(lst.begin());
			lst.erase(lst.end());

			Assert::IsTrue(lst.getSize() == vec.size() - 2, L"erase_begin_end_size unsuccess");
			Assert::IsTrue(lst.front() == *it1, L"after_erase_begin_data unsuccess");
			Assert::IsTrue(lst.back() == *it2, L"after_erase_end_data unsuccess");
			Assert::IsTrue(lst.begin() == it1.current_iterator, L"after_erase_begin_address unsuccess");
			Assert::IsTrue(lst.end() == it2.current_iterator, L"after_erase_end_address unsuccess");

			while (*it2 != 3)
				--it2;
			while (*it1 != 0)
				++it1;
			--it1;
			++it2;

			lst.erase(lst.begin(), it1);
			lst.erase(it2, lst.end());

			it1 = lst.begin();
			it2 = lst.end();

			while (*it2 != 355)
				--it2;
			++it1;

			lst.erase(it1, it2);
			for (int i = 0; i < lst.getSize(); i++)
			{
				Assert::AreEqual(lst[i], i, L"Erase from [begin,end] [begin, lastPos] [firstPos, end] [firstPos, lastPos] unsuccess");
			}

			lst.erase(lst.begin(), lst.end());
			Assert::AreEqual(lst.getSize(), 0, L"Erase from [begin,end] unsuccess");

			lst.push_back(vec);
			Assert::IsTrue(lst.getSize() != 0);

			lst.clear();
			Assert::IsTrue(lst.getSize() == 0, L"clear() unsuccess");
			Assert::IsTrue(lst.begin() == NULL, L"after_clear_begin unsuccess");
			Assert::IsTrue(lst.end() == NULL, L"after_clear_end unsuccess");
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

			lst.insert(lst1.begin(), lst1.end(), lst.begin());
			for (int i = 0; i < lst1.getSize(); i++)
			{
				Assert::AreEqual(lst[i], i + 1, L"insert into begin from another list unsuccess");
			}

			it = lst.end();
			lst.insert(lst1.begin(), lst1.end(), lst.end());
			it++;
			for (int i = 1;it != lst.end(); it++, i++)
			{
				Assert::AreEqual(*it, i , L"insert into end from another list unsuccess");
			}

			it = lst.begin();
			it++;
			lst.insert(lst1.begin(), lst1.end(), it);
			for (int i = 1; i <= lst1.getSize(); i++)
			{
				Assert::AreEqual(lst[i], i, L"insert into end from another list unsuccess");
			}
		}
		TEST_METHOD(Push_front_back)
		{
			list<int> lst;
			list<int>::Iterator it;
			vector<int> vec = {0,1,2,3,4};
			int size;

			for (int i = 1; i < 5; i++)
			{
				lst.push_back(i);
				lst.push_front(i);
			}

			Assert::IsTrue(lst.getSize() == 8, L"Push_front_back size unsuccess");

			size = lst.getSize();

			for (int i = 0; i < size / 2; i++)
			{
				Assert::AreEqual(lst[i], size / 2 - i, L"push_front(data) unsuccess");
				Assert::AreEqual(lst[size - i - 1], size / 2 - i, L"push_back(data) unsuccess");
			}

			it = lst.end();

			lst.push_back(vec);
			lst.push_front(vec);

			Assert::IsTrue(lst.getSize() == size + vec.size() * 2, L"Push_front_back_vector size unsuccess");

			for (int i = 0; i < vec.size(); i++)
			{
				it++;
				Assert::AreEqual(lst[i], i, L"push_front(vector) unsuccess");
				Assert::AreEqual(*it, i, L"push_back(vector) unsuccess");
			}
		}
	};
}
