#pragma once
#include <vector>

using namespace std;

template <typename T>
class list
{
public:
	template <typename T> struct List_iterator;
	typedef List_iterator<T> Iterator;

	list();
	~list();

	//Adding elements//
	void push_back(T data);
	void push_back(vector<T> data);
	void push_front(T data);
	void insert(T data, int pos);
	void insert(T data, int count, int pos);
	void insert(vector<int> vec, int pos);
	/*void insert(T data, Iterator pos);
	void insert(T data, int count, Iterator pos);
	void insert(vector<int> vec, Iterator pos);*/
	////

	//Removing
	void clear();
	void removeAt(int pos);
	void pop_front();
	void pop_back();
	////

	//Geting info//
	Iterator* begin() { return Begin; }
	Iterator* end() { return End; }
	bool empty();
	T front();
	T back();
	int getSize() { return size; }
	T& operator[](const int index);
	////
private:
	size_t size;
	Iterator* End;
	Iterator* Begin;
	template<typename T>
	struct List_iterator
	{
		List_iterator* pNext;
		T data;
	public:

		List_iterator(Iterator* source_iterator) : current_iterator(source_iterator) {};
		List_iterator() : current_iterator(NULL) { }

		T& operator*()
		{
			return current_iterator->pNext;
		}
		Iterator& operator=(Iterator* source_it)
		{
			this->current_iterator = source_it;
			return *this;
		}
		bool operator==(Iterator* source_it) const
		{
			return current_iterator == source_it;
		}
		bool operator<=(Iterator* source_it) const
		{
			return current_iterator <= source_it;
		}
		bool operator>=(Iterator* source_it) const
		{
			return current_iterator >= source_it;
		}
		bool operator!=(Iterator* source_it) const
		{
			return current_iterator == source_it;
		}
		Iterator& operator++()
		{
			current_iterator = current_iterator->pNext;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator it = *this;
			++* this;
			return it;
		}
		Iterator& operator--()
		{
			
			Iterator* it = Begin;
			for (; it->pNext != current_iterator; it++)
				it = it->pNext;
			current_iterator = it;
			return *this;
		}
		/*Iterator operator--(int)
		{

		}*/

	private:
		Iterator* current_iterator;
	};
};

template<typename T>
list<T>::list()
{
	size = 0;
	End = nullptr;
	Begin = nullptr;
}

template<typename T>
list<T>::~list()
{
	clear();
}

template<typename T>
void list<T>::push_back(T data)
{
	Iterator* temp = new Iterator;
	temp->data = data;
	temp->pNext = NULL;
	if (Begin == NULL)
	{
		Begin = temp;
		End = temp;
		temp = NULL;
	}
	else
	{
		End->pNext = temp;
		End = temp;
	}
	size++;
}

template <typename T>
void list<T>::push_back(vector<T> data)
{
	Iterator* temp;

	for (int i = 0; i < data.size(); i++)
	{
		temp = new Iterator;
		temp->data = data[i];
		temp->pNext = NULL;
		if (Begin == NULL)
		{
			Begin = temp;
			End = temp;
			temp = NULL;
		}
		else
		{
			End->pNext = temp;
			End = temp;
		}
	}
	size += data.size();
}

template<typename T>
void list<T>::push_front(T data)
{
	Iterator* temp = Begin;
	Begin = new Iterator;
	Begin->data = data;
	Begin->pNext = temp;
	size++;
}

template<typename T>
void list<T>::pop_front()
{
	Iterator* temp = Begin;
	Begin = Begin->pNext;
	delete temp;
	End = Begin;
	if (End != nullptr)
	{
		while (End->pNext != nullptr)
		{
			End = End->pNext;
		}
	}
	size--;
}

template<typename T>
void list<T>::pop_back()
{
	removeAt(size - 1);
}

template<typename T>
void list<T>::insert(T data, int pos)
{
	Iterator* temp = new Iterator;
	Iterator* temp1 = new Iterator;
	if (pos == 0)
	{
		push_front(data);
	}
	else
	{
		Iterator* previous = this->Begin;
		for (int i = 0; i < pos - 1; i++)
		{
			previous = previous->pNext;
		}
		temp1 = previous->pNext;
		temp->data = data;
		previous->pNext = temp;
		temp->pNext = temp1;
	}
	size++;
}

template<typename T>
void list<T>::insert(T data, int count, int pos)
{
	if (pos == 0 || pos == size - 1)
	{
		if (pos == 0)
		{
			for (int i = 0; i < count; i++)
			{
				push_front(data);
			}
		}
		if (pos == size - 1)
		{
			for (int i = 0; i < count; i++)
			{
				push_back(data);
			}
		}
	}
	else
	{
		Iterator* previous = this->Begin;
		Iterator* temp = new Iterator;
		vector<T> sData(count, data);

		for (int i = -1; i < pos - 1; i++)
		{
			previous = previous->pNext;
		}

		temp = End;
		End = previous;
		previous = previous->pNext;

		push_back(sData);

		End->pNext = previous;
		End = temp;
	}

}

template<typename T>
void list<T>::insert(vector<int> vec, int pos)
{
	if (pos == 0 || pos == size - 1)
	{
		if (pos == 0)
		{
			for (int i = vec.size() - 1; i >= 0; i--)
			{
				push_front(vec[i]);
			}
		}
		if (pos == size - 1)
		{
			for (int i = 0; i < vec.size(); i++)
			{
				push_back(vec);
			}
		}
	}
	else
	{
		Iterator* previous = this->Begin;
		Iterator* temp = new Iterator;

		for (int i = -1; i < pos - 1; i++)
		{
			previous = previous->pNext;
		}

		temp = End;
		End = previous;
		previous = previous->pNext;

		push_back(vec);

		End->pNext = previous;
		End = temp;
	}
}

//template<typename T>
//void list<T>::insert(T data, Iterator pos)
//{
//	Node<T>* temp = new Node<T>;
//	Node<T>* temp1 = new Node<T>;
//	if (pos == 0)
//	{
//		push_front(data);
//	}
//	else
//	{
//		/*Node<T>* previous = this->Begin;
//		for (int i = 0; i < pos - 1; i++)
//		{
//			previous = previous->pNext;
//		}*/
//		temp1 = pos;
//		temp->data = data;
//		previous->pNext = temp;
//		temp->pNext = temp1;
//	}
//	size++;
//}
//
//template<typename T>
//void list<T>::insert(T data, int count, Iterator pos)
//{
//}
//
//template<typename T>
//void list<T>::insert(vector<int> vec, Iterator pos)
//{
//}

template<typename T>
void list<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
void list<T>::removeAt(int pos)
{
	if (pos == 0)
	{
		pop_front();
	}
	else
	{
		Iterator* previous = this->Begin;
		for (int i = 0; i < pos - 1; i++)
		{
			previous = previous->pNext;
		}

		Iterator* to_delete = previous->pNext;
		previous->pNext = to_delete->pNext;
		delete to_delete;
		End = previous;
		while(End->pNext != nullptr)
		{ 
			End = End->pNext;
		}
	}
	size--;
}

template<typename T>
bool list<T>::empty()
{
	if (Begin == End)
	{
		return 0;
	}
	return 1;
}

template<typename T>
T list<T>::front()
{
	return Begin->data;
}

template<typename T>
T list<T>::back()
{
	return End->data;
}

template<typename T>
T& list<T>::operator[](const int index)
{
	int counter = 0;
	Iterator* current = this->Begin;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}
