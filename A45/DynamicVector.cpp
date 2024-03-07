#include "DynamicVector.h"

DynamicVector::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}

DynamicVector::DynamicVector(const DynamicVector& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

DynamicVector::~DynamicVector()
{
	delete[] this->elems;
}

DynamicVector& DynamicVector::operator=(const DynamicVector& v)
{

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

void DynamicVector::add(const TElement& e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

void DynamicVector::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}


int DynamicVector::getSize()  const
{
	return this->size;
}

int DynamicVector::getCapacity() const
{
	return this->capacity;
}


TElement DynamicVector::get(int position)
{
	return this->elems[position];
}

void DynamicVector::remove(const int& position)
{
	if (position != -1)
	{
		for (int i = position; i < this->size - 1; i++)
			this->elems[i] = this->elems[i + 1];
		this->size--;
	}

}

bool DynamicVector::update(const int& position, TElement& m)
{
	this->elems[position] = m;
	return true;
}



