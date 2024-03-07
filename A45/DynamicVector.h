#ifndef DYNAMIC_VECTOR_H
#define DYNAMIC_VECTOR_H

#pragma once
#include "Movie.h"

typedef Movie TElement;

class DynamicVector
{
private:
	TElement* elems;
	int size;
	int capacity;

public:
	// default constructor for a DynamicVector
	DynamicVector(int capacity = 10);

	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& v);
	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& v);

	// Adds an element to the current DynamicVector.
	void add(const TElement& e);

	// return the size for the DynamicVector
	int getSize() const;

	// return the capacity for the DynamicVector
	int getCapacity() const;

	// returns the element on a given position
	// the position must be a valid one
	TElement get(int position);

	// Removes an element from the current DynamicVector.
	void remove(const int& position);

	// Updates an element from a given position.
	bool update(const int& position, TElement& m);

	// Increments the likes of a movie.
	//void updateLike(const int& position, const int& new_year);

private:
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);
};

#endif