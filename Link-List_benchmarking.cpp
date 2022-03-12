#include <iostream>
#include "list.h"
#include <chrono>

using namespace std;

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
		double ms = duration * 0.001;
		cout << duration << "us (" << ms << " ms)" << endl << endl;
	}
private:
	chrono::time_point<chrono::high_resolution_clock> startTimePoint;
};


int main()
{
	list<int> lst;
	list<int> lst2(1000,1000);
	list<int>::Iterator it,it1, it2;
	vector<int> vec(1000, 1000);
	int data = 7;

	cout << "default constructor" << endl;
	{
		timer time;
		list<int> lst1;
	}

	cout << "constructor with 'count' elements of default data" << endl;
	{
		timer time;
		list<int> lst1(1000);
	}

	cout << "constructor with 'count' elements of data 'data' " << endl;
	{
		timer time;
		list<int> lst1(1000, 1000);
	}

	cout << "constructor with vector" << endl;
	{
		timer time;
		list<int> lst1(vec);
	}

	cout << "push_back(data)" << endl;
	{
		timer time;
		lst.push_back(data);
	}

	cout << "push_back(vector)" << endl;
	{
		timer time;
		lst.push_back(vec);
	}

	cout << "push_front(data)" << endl;
	{
		timer time;
		lst.push_front(data);
	}

	cout << "push_front(vector)" << endl;
	{
		timer time;
		lst.push_front(vec);
	}

	
	cout << "insert(data, integer position 0" << endl;
	{
		timer time;
		lst.insert(1, 0);
	}

	cout << "insert(data, iterator position begin" << endl;
	{
		timer time;
		lst.insert(1, lst.begin());
	}

	cout << "insert(data, count, integer position 0" << endl;
	{
		timer time;
		lst.insert(2, 2, 0);
	}

	cout << "insert(data, count, iterator position begin" << endl;
	{
		timer time;
		lst.insert(2, 2, lst.begin());
	}

	cout << "insert(vector, integer position 0" << endl;
	{
		timer time;
		lst.insert(vec, 0);
	}

	cout << "insert(vector, iterator position begin" << endl;
	{
		timer time;
		lst.insert(vec, lst.begin());
	}

	//
	lst.clear();
	//

	cout << "insert(data, integer position 0" << endl;
	{
		timer time;
		lst.insert(1, 0);
	}

	cout << "insert(data, iterator position end" << endl;
	{
		timer time;
		lst.insert(1, lst.end());
	}

	cout << "insert(data, count, integer position 1(end)" << endl;
	{
		timer time;
		lst.insert(2, 2, 1);
	}

	cout << "insert(data, count, iterator position end" << endl;
	{
		timer time;
		lst.insert(2, 2, lst.end());
	}

	cout << "insert(vector, integer position 5(end)" << endl;
	{
		timer time;
		lst.insert(vec, 5);
	}

	cout << "insert(vector, iterator position end" << endl;
	{
		timer time;
		lst.insert(vec, lst.end());
	}
	///

	///
	cout << "insert(data, integer position 0" << endl;
	{
		timer time;
		lst.insert(1, 0);
	}

	it = lst.begin();
	it++;

	cout << "insert(data, iterator position" << endl;
	{
		timer time;
		lst.insert(1, it);
	}

	cout << "insert(data, count, integer position 1(middle)" << endl;
	{
		timer time;
		lst.insert(2, 2, 1);
	}

	it = lst.begin();
	it++;

	cout << "insert(data, count, iterator position" << endl;
	{
		timer time;
		lst.insert(2, 2, it);
	}

	cout << "insert(vector, integer position 1(middle)" << endl;
	{
		timer time;
		lst.insert(vec, 1);
	}

	it = lst.begin();
	it++;

	cout << "insert(vector, iterator position" << endl;
	{
		timer time;
		lst.insert(vec, it);
	}
	///
	
	/// 
	cout << "insert(iterator secfpos, iterator seclpos, iterator pos(begin)" << endl;
	{
		timer time;
		lst.insert(lst2.begin(), lst2.end(), lst.begin());
	}


	cout << "insert(iterator secfpos, iterator seclpos, iterator pos(end)" << endl;
	{
		timer time;
		lst.insert(lst2.begin(), lst2.end(), lst.end());
	}

	it = lst.begin();
	it++;

	cout << "insert(iterator secfpos, iterator seclpos, iterator pos(middle)" << endl;
	{
		timer time;
		lst.insert(lst2.begin(), lst2.end(), it);
	}
	/// 
	
	/// 
	it1 = lst.begin();
	it2 = lst.end();

	for (int i = 0; i < 250; i++, it1++);
	for (int i = lst.getSize(); i >= lst.getSize() - 250; i--, it2--);

	cout << "erase(iterator fpos(begin), iterator lpos" << endl;
	{
		timer time;
		lst.erase(lst.begin(), it1);
	}

	cout << "erase(iterator fpos, iterator lpos(end)" << endl;
	{
		timer time;
		lst.erase(it2, lst.end());
	}
	

	it1 = lst.begin();
	it2 = lst.end();

	for (int i = 0; i < 250; i++, it1++);
	for (int i = lst.getSize(); i >= lst.getSize() - 250; i--, it2--);

	cout << "erase(iterator fpos, iterator lpos)" << endl;
	{
		timer time;
		lst.erase(it1, it2);
	}

	cout << "erase(iterator pos(begin))" << endl;
	{
		timer time;
		lst.erase(lst.begin());
	}

	cout << "erase(iterator pos(end))" << endl;
	{
		timer time;
		lst.erase(lst.end());
	}

	it = lst.begin();
	for (int i = 0; i < 250; i++, it++);

	cout << "erase(iterator pos(middle))" << endl;
	{
		timer time;
		lst.erase(it);
	}
	/// 

	/// 
	cout << "removeAt(integer pos(250))" << endl;
	{
		timer time;
		lst.removeAt(250);
	}

	cout << "pop_back()" << endl;
	{
		timer time;
		lst.pop_back();
	}

	cout << "pop_front()" << endl;
	{
		timer time;
		lst.pop_front();
	}

	cout << "clear()" << endl;
	{
		timer time;
		lst.clear();
	}

}