#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace Linked_List
{
	template<typename T>
	class list
	{
	public:
		template<typename T> struct Node;
		template <typename T> struct List_iterator;
		typedef List_iterator<T> Iterator;

		template <typename T>
		struct List_iterator
		{
		public:

			typedef List_iterator<T> Iterator;

			List_iterator(Node<T>* source_iterator) : current_iterator(source_iterator) {};
			List_iterator() : current_iterator(0) { }

			T& operator*()
			{
				return current_iterator->data;
			}
			Iterator& operator=(List_iterator<T>* source_it)
			{
				this->current_iterator = (Node<T>*)source_it;
				return *this;
			}
			bool operator==(Node<T>* source_it) const
			{
				return current_iterator == source_it;
			}
			bool operator!=(Node<T>* source_it) const
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
		private:
			Node<T>* current_iterator;
		};

		list();
		~list();

		//Adding elements//
		void push_back(T data);
		void push_back(vector<T> data);
		void push_front(T data);
		void insert(T data, int pos);
		void insert(T data, int count, int pos);
		void insert(vector<int> vec, int pos);
		////

		//Removing
		void clear();
		void removeAt(int pos);
		void pop_front();
		void pop_back();
		////

		//Geting info//
		Iterator* begin() { return (Iterator*)Begin; }
		Iterator* end() { return (Iterator*)End; }
		bool empty();
		T front();
		T back();
		int getSize() { return size; }
		T& operator[](const int index);
		////
	private:
		template<typename T>
		struct Node
		{
			Node* pNext;
			T data;
		};

		size_t size;
		Node<T>* End;
		Node<T>* Begin;

	};
}