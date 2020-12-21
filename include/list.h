#pragma once

#include <iostream>

template <class T>
class List
{
private:
	template <class T>
	struct Node {
		T data;
		Node *next;
		Node(T data_ = {})
		{
			data = data_;
			next = nullptr;
		}
	};
	Node<T> *first;
	size_t Size;
public:
	
	List();
	List(const List<T> &l);
	~List();
	bool empty();
	size_t size() { return Size; }
	void append(const T& elem);
	void remove();
	void clear();
	List<T>& operator=(const List<T> &l);
	bool operator==(const List<T> &l);
	bool operator!=(const List<T> &l);
};

template <class T>
List<T>::List()
{
	Size = 0;
	first = nullptr;
}

template <class T>
List<T>::List(const List<T> &l)
{
	Size = l.Size;
	first = nullptr;
	Node<T> *temp = l.first;
	while (temp != nullptr)
	{
		append(temp->data);
		temp = temp->next;
	}
}

template <class T>
List<T>::~List()
{
	while (first != nullptr)
	{
		Node<T> *temp = first;
		first = first->next;
		delete temp;
	}
}

template <class T>
bool List<T>::empty()
{
	if (first == nullptr) return true;
	return false;
}

template <class T>
void List<T>::append(const T& elem)
{
	if (empty())
	{
		first = new Node<T>(elem);
	}
	else
	{
		Node<T>* temp = this->first;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = new Node<T>(elem);
	}
	Size++;
}

template <class T>
void List<T>::remove()    // revoves first element
{
	if (empty()) throw "Error";
	Node<T>* temp = this->first;
	first = first->next;
	delete temp;
	Size--;
}

template <class T>
void List<T>::clear()
{
	while (first != nullptr)
	{
		Node<T> *temp = first;
		first = first->next;
		delete temp;
	}
	Size = 0;
}

template <class T>
List<T>& List<T>::operator=(const List<T> &l)
{
	clear();
	Node<T> *temp = l.first;
	while (temp != nullptr)
	{
		append(temp->data);
		temp = temp->next;
	}
	return *this;
}

template <class T>
bool List<T>::operator==(const List<T> &l)
{
	if (l.Size != Size)	return false;
	Node<T> *temp1 = first;
	Node<T> *temp2 = l.first;
	while (temp1 != nullptr)
	{
		if (temp1->data == temp2->data)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else return false;
	}
	return true;
}

template <class T>
bool List<T>::operator!=(const List<T> &l)
{
	return !(*this == l);
}
