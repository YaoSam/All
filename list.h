#pragma once
#include <iostream>
#include <time.h>
#define TEMP template <class T>
#define re(i,n) for(unsigned int i=0;i<n;i++)

TEMP 
struct node
{
	T data;
	node<T>* next;
public:
	node<T>(T const & D=T(), node<T>* N = NULL) : data(D), next(N){}
};

TEMP 
class list
{
	node<T>* head;
	unsigned int length;
	node<T>* last()const;
public:
	list(T const a[] = NULL, unsigned int n = 0);
	list(list<T> const & other);
	~list();
	list<T>& operator=(list<T> const &other);
	void HeadInsert(T const &x);
	void RearInsert(T const &x);
	friend std::ostream& operator<<(std::ostream& out, list<T> const & other)
	{
		node<T>* temp = other.head->next;
		while (temp != NULL)
		{
			out << temp->data << " ";
			temp = temp->next;
		}
		return out << std::endl;
	}
};