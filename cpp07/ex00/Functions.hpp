#pragma once

#include <iostream>


/*
template <typename T> 
is a template declaration that allows the creation of generic code, 
enabling functions or classes to work with any data type (without 
rewriting the same code for different types). 
*/
template <typename T>
void	swap(T& a, T& b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	min(T a, T b)
{
	if (a < b)
		return (a);
	return b;
}

template <typename T>
T	max(T a, T b)
{
	if (a > b)
		return (a);
	return b;
}