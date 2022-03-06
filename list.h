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
	list(int count, T data);
	list(int count);
	list(vector<T> data);
	~list();

	//Adding elements//
	void push_back(T data);
	void push_back(vector<T> vec);
	void push_front(T data);
	void insert(T data, int pos);
	void insert(T data, int count, int pos);
	void insert(vector<T> vec, int pos);
	void insert(T data, Iterator pos);
	void insert(T data, int count, Iterator pos);
	void insert(vector<T> vec, Iterator pos); 
	void insert(Iterator secfpos, Iterator seclpos, Iterator pos);
	////

	//Removing
	void clear();
	void removeAt(int pos);
	void pop_front();
	void pop_back();
	void erase(Iterator pos);
	void erase(Iterator fpos, Iterator lpos);
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
		Iterator* current_iterator;
		List_iterator* pNext;
		List_iterator* pPrev;
		T data;
	public:

		List_iterator(Iterator* source_iterator) : current_iterator(source_iterator) {};
		List_iterator() : current_iterator(NULL) { }

		T& operator*()
		{
			return current_iterator->data;
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
		bool operator!=(Iterator* source_it) const
		{
			return current_iterator != source_it;
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
			current_iterator = current_iterator->pPrev;
			return *this;
		}
		Iterator operator--(int)
		{
			Iterator it = *this;
			--* this;
			return it;
		}
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
list<T>::list(int count, T data)
{
	for (int i = 0; i < count; i++)
	{
		push_back(data);
	}
}

template<typename T>
list<T>::list(int count)
{
	for (int i = 0; i < count; i++)
	{
		push_back(0);
	}
}

template<typename T>
list<T>::list(vector<T> data)
{
	push_back(data);
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
		Begin->pPrev = Begin;
		temp = NULL;
	}
	else
	{
		End->pNext = temp;
		End = temp;
		temp = Begin;
		while (temp->pNext != End)
			temp = temp->pNext;
		End->pPrev = temp;
	}
	size++;
}

template <typename T>
void list<T>::push_back(vector<T> vec)
{
	Iterator* temp;

	for (int i = 0; i < vec.size(); i++)
	{
		temp = new Iterator;
		temp->data = vec[i];
		temp->pNext = NULL;
		if (Begin == NULL)
		{
			Begin = temp;
			End = temp;
			Begin->pPrev = Begin;
			temp = NULL;
		}
		else
		{
			End->pNext = temp;
			temp->pPrev = End;
			End = temp;
		}
	}
	size += vec.size();
}

template<typename T>
void list<T>::push_front(T data)
{
	Iterator* temp = Begin;
	Begin = new Iterator;
	Begin->data = data;
	Begin->pNext = temp;
	Begin->pPrev = Begin;
	if (Begin->pNext == nullptr)
		End = Begin;
	size++;
}

template<typename T>
void list<T>::pop_front()
{
	Iterator* temp = Begin;
	Begin = Begin->pNext;
	if (Begin != nullptr)
		Begin->pPrev = temp->pNext;
	if (size == 1)
	{
		Begin = nullptr;
		End = nullptr;
	}
	delete temp;
	size--;
}

template<typename T>
void list<T>::pop_back()
{
	Iterator* temp = End;
	if (End != Begin)
	{
		End = End->pPrev;
		End->pNext = nullptr;
	}
	else
	{
		End = nullptr;
		Begin = nullptr;
	}
	delete temp;
	size--;
}

template<typename T>
void list<T>::erase(Iterator pos)
{
	Iterator* temp = &pos;
	temp = temp->current_iterator;
	if (temp == Begin)
	{
		pop_front();
	}
	else if (temp == End)
	{
		pop_back();
	}
	else {
		temp = temp->pPrev;
		Iterator* to_delete = temp->pNext;
		temp->pNext = to_delete->pNext;
		to_delete->pNext->pPrev = temp;
		delete to_delete;
		size--;
	}
}

template<typename T>
void list<T>::erase(Iterator fpos, Iterator lpos)
{
	Iterator* temp = &fpos;
	Iterator* temp1 = &lpos;
	temp = temp->current_iterator;
	temp1 = temp1->current_iterator;
	if (temp == Begin)
	{
		while (temp1 != Begin)
		{
			pop_front();
		}
		pop_front();
	}
	else if (temp1 == End)
	{
		while (temp != End)
		{
			pop_back();
		}
		pop_back();
	}
	else {
		Iterator* to_delete;
		Iterator* next_delete = temp;
		temp1 = temp1->pNext;
		temp = temp->pPrev;
		for (; next_delete != temp1; )
		{
			to_delete = next_delete;
			next_delete = next_delete->pNext;
			delete to_delete;
			size--;
		}
		temp->pNext = temp1;
		temp1->pPrev = temp;
	}
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
		temp->pPrev = previous;
		temp1->pPrev = temp;
		size++;
	}
}

template<typename T>
void list<T>::insert(T data, int count, int pos)
{
	if (pos == 0)
	{
		for (int i = 0; i < count; i++)
		{
			push_front(data);
		}
	}
	else	if (pos == size - 1)
	{
		for (int i = 0; i < count; i++)
		{
			push_back(data);
		}
	}
	else
	{
		Iterator* previous = this->Begin;
		Iterator* temp = new Iterator;
		vector<T> sData(count, data);

		for (int i = 0; i < pos - 1; i++)
		{
			previous = previous->pNext;
		}

		temp = End;
		End = previous;
		previous = previous->pNext;

		push_back(sData);

		End->pNext = previous;
		previous->pPrev = End;
		End = temp;
		End->pPrev = End->pPrev;
	}

}

template<typename T>
void list<T>::insert(vector<T> vec, int pos)
{
	if (pos == 0)
	{
		for (int i = vec.size() - 1; i >= 0; i--)
		{
			push_front(vec[i]);
		}
	}
	else if (pos == size - 1)
	{
		push_back(vec);
	}
	else
	{
		Iterator* previous = this->Begin;
		Iterator* temp = new Iterator;

		for (int i = 0; i < pos - 1; i++)
		{
			previous = previous->pNext;
		}

		temp = End;
		End = previous;
		previous = previous->pNext;

		push_back(vec);

		End->pNext = previous;
		previous->pPrev = End;
		End = temp;
		End->pPrev = End->pPrev;
	}
}

template<typename T>
void list<T>::insert(T data, Iterator pos)
{
	Iterator* temp = &pos;
	temp = temp->current_iterator;

	if (temp == Begin)
	{
		push_front(data);
	}
	else if (temp == End)
	{
		push_back(data);
	}
	else
	{
		Iterator* temp1 = new Iterator;
		temp1->data = data;
		temp1->pNext = temp;
		temp1->pPrev = temp->pPrev;
		temp->pPrev->pNext = temp1;
		temp->pPrev = temp1;
		size++;
	}
}

template<typename T>
void list<T>::insert(T data, int count, Iterator pos)
{
	Iterator* temp = &pos;
	temp = temp->current_iterator;

	if (temp == Begin)
	{
		for (int i = 0; i < count; i++)
		{
			push_front(data);
		}
	}
	else if (temp == End)
	{
		for (int i = 0; i < count; i++)
		{
			push_back(data);
		}
	}
	else
	{
		for (int i = 0; i < count; i++)
		{
			Iterator* temp1 = new Iterator;
			temp1->data = data;
			temp1->pNext = temp;
			temp1->pPrev = temp->pPrev;
			temp->pPrev->pNext = temp1;
			temp->pPrev = temp1;
			temp = temp1;
			size++;
		}
	}
}

template<typename T>
void list<T>::insert(vector<T> vec, Iterator pos)
{
	Iterator* temp = &pos;
	temp = temp->current_iterator;

	if (temp == Begin)
	{
		for (int i = vec.size() - 1; i > -1; i--)
		{
			push_front(vec[i]);
		}
	}
	else if (temp == End)
	{
		push_back(vec);
	}
	else
	{
		for (int i = vec.size() - 1; i > -1; i--)
		{
			Iterator* temp1 = new Iterator;
			temp1->data = vec[i];
			temp1->pNext = temp;
			temp1->pPrev = temp->pPrev;
			temp->pPrev->pNext = temp1;
			temp->pPrev = temp1;
			temp = temp1;
		}
		size += vec.size();
	}
}

template<typename T>
void list<T>::insert(Iterator secfpos, Iterator seclpos, Iterator pos)
{
	Iterator* fpos = &secfpos;
	Iterator* lpos = &seclpos;
	Iterator* currpos = &pos;
	fpos = fpos->current_iterator;
	lpos = lpos->current_iterator;
	currpos = currpos->current_iterator;
	int count = 1;

	for (Iterator* it = fpos; it != lpos; it = it->pNext)
		count++;

	if (currpos == Begin)
	{
		lpos->pNext = Begin;
		Begin->pPrev = lpos;
		Begin = fpos;
	}
	else if (currpos == End)
	{
		fpos->pPrev = End;
		End->pNext = fpos;
		End = lpos;
	}
	else
	{
		currpos->pPrev->pNext = fpos;
		fpos->pPrev = currpos->pPrev;
		currpos->pPrev = lpos;
		lpos->pNext = currpos;
	}
	size += count;
}

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
	else if (pos == size - 1)
	{
		pop_back();
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
		to_delete->pPrev = previous;
		delete to_delete;
	}
	size--;
}

template<typename T>
bool list<T>::empty()
{
	if (Begin == nullptr)
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
