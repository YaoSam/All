#pragma  once
#include "list.h"

TEMP
list<T>::list(T const a[] /* = NULL */, unsigned int n /* = 0 */) :
head(new node<T>),
length(n)
{
	node<T>* temp=head; 
	re(i, n)
		temp = (temp->next = new node<T>(a[i]));
	return;
}

TEMP
list<T>::list(list<T> const & other):
head(new node<T>),
length(other.length)
{
	node<T>* othertemp = other.head->next,*temp=head;
	while (othertemp != NULL)
	{
		temp->next = new node<T>(othertemp->data);
		temp = temp->next;
		othertemp = othertemp->next;
	}
	return;
}

TEMP 
list<T>::~list()
{
	node<T>* temp=head;
	while (head->next != NULL)
	{
		head = temp->next;
		delete temp;
		temp = head;
	}
	delete temp;
}

TEMP
list<T>& list<T>::operator=(list<T> const & other)
{
	if (this == &other)return *this;
	node<T>* temp = head;
	node<T>* othertemp = other.head->next;
	while (head->next != NULL)
	{
		head = temp->next;
		delete temp;
		temp = head;
	}
	delete temp;
	temp=head = new node < T > ;
	while (othertemp != NULL)
	{
		temp->next = new node<T>(othertemp->data);
		temp = temp->next;
		othertemp = othertemp->next;
	}
	length = other.length;
	return *this;
}

TEMP
void list<T>::HeadInsert(T const &x)
{
	node<T>* temp = head->next;
	head->next = new node<T>(x, temp);
	length++;
	return;
}

TEMP
node<T>* list<T>::last()const
{
	node<T>* temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	return temp;
}

TEMP
void list<T>::RearInsert(T const &x)
{
	last()->next = new node<T>(x);
	length++;
}