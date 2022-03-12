#include <iostream>
#include "list.h"
#include <chrono>

using namespace std;

double ms = 0;

class timer
{
public:
	timer()
	{
		startTimePoint = chrono::high_resolution_clock::now();
	}

	~timer()
	{
		stop();
	}

	void stop()
	{
		auto endTimePoint = chrono::high_resolution_clock::now();

		auto start = chrono::time_point_cast<chrono::microseconds>(startTimePoint).time_since_epoch().count();
		auto end = chrono::time_point_cast<chrono::microseconds>(endTimePoint).time_since_epoch().count();

		auto duration = end - start;
		ms += duration * 0.001;
	}
private:
	chrono::time_point<chrono::high_resolution_clock> startTimePoint;
};


int main()
{
	list<int> lst;
	list<int> lst2(1000, 1000);
	list<int>::Iterator it, it1, it2;
	vector<int> vec(1000, 1000);
	int data = 7;
	int n = 100;

	cout << "default constructor" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			list<int> lst1;
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;

	ms = 0;

	cout << "constructor with 'count' elements of default data" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			list<int> lst1(1000);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;

	ms = 0;

	cout << "constructor with 'count' elements of data 'data' " << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			list<int> lst1(1000, 1000);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "constructor with vector" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			list<int> lst1(vec);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "push_back(data)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.push_back(data);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "push_back(vector)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.push_back(vec);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "push_front(data)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.push_front(data);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "push_front(vector)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.push_front(vec);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;

	cout << "insert(data, integer position 0)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(1, 0);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "insert(data, iterator position begin)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(1, lst.begin());
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "insert(data, count, integer position 0)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(2, 2, 0);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "insert(data, count, iterator position begin)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(2, 2, lst.begin());
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "insert(vector, integer position 0)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(vec, 0);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "insert(vector, iterator position begin)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(vec, lst.begin());
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	//
	lst.clear();
	//

	cout << "insert(data, iterator position end)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(1, lst.end());
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "insert(data, count, integer position 1(end))" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(2, 2, 1);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "insert(data, count, iterator position end)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(2, 2, lst.end());
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "insert(vector, integer position 5(end))" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(vec, 5);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "insert(vector, iterator position end)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(vec, lst.end());
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	///
	ms = 0;
	///
	cout << "insert(data, integer position 0)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(1, 0);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	it = lst.begin();
	it++;

	cout << "insert(data, iterator position)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(1, it);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "insert(data, count, integer position 1(middle))" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(2, 2, 1);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	it = lst.begin();
	it++;

	cout << "insert(data, count, iterator position)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(2, 2, it);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "insert(vector, integer position 1(middle))" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(vec, 1);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	it = lst.begin();
	it++;

	cout << "insert(vector, iterator position)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(vec, it);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	///
	ms = 0;
	/// 
	cout << "insert(iterator secfpos, iterator seclpos, iterator pos(begin))" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(lst2.begin(), lst2.end(), lst.begin());
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "insert(iterator secfpos, iterator seclpos, iterator pos(end))" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(lst2.begin(), lst2.end(), lst.end());
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	it = lst.begin();
	it++;

	cout << "insert(iterator secfpos, iterator seclpos, iterator pos(middle))" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.insert(lst2.begin(), lst2.end(), it);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	/// 
	ms = 0;
	/// 

	cout << "erase(iterator fpos(begin), iterator lpos)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			it1 = lst.begin();

			for (int i = 0; i < 250; i++, it1++);
			it2 = it1;
			for (int i = 0; i < 250; i++, it2++);
			timer time;
			lst.erase(lst.begin(), it1);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "erase(iterator fpos, iterator lpos(end))" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			it1 = lst.end();
			for (int i = 0; i < 250; i++, it1--);

			timer time;
			lst.erase(it1, lst.end());
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;

	ms = 0;

	cout << "erase(iterator fpos, iterator lpos)" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			it1 = lst.begin();

			for (int i = 0; i < 250; i++, it1++);
			it2 = it1;
			for (int i = 0; i < 250; i++, it2++);

			timer time;
			lst.erase(it1, it2);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "erase(iterator pos(begin))" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.erase(lst.begin());
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "erase(iterator pos(end))" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.erase(lst.end());
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;

	cout << "erase(iterator pos(middle))" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			it = lst.begin();
			for (int i = 0; i < 250; i++, it++);
			timer time;
			lst.erase(it);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	/// 
	ms = 0;
	/// 
	cout << "removeAt(integer pos(250))" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.removeAt(250);
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "pop_back()" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.pop_back();
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "pop_front()" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.pop_front();
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
	ms = 0;
	cout << "clear()" << endl;
	for (int i = 0; i < n; i++)
	{
		{
			timer time;
			lst.clear();
		}
	}
	cout << "average duration = " << ms / n << " ms" << endl << endl;
}
