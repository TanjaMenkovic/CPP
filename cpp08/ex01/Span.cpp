#include "Span.hpp"

Span::Span(): size(0) {}

Span::Span(unsigned int N): size(N) {}

Span::Span(const Span &src): size(src.size)
{
	*this = src;
}

Span::~Span() {}

Span	&Span::operator=(const Span &src)
{
	if (this != &src)
	{
		this->size = src.size;
		this->storage = src.storage;
	}
	return *this;
}

void Span::addNumber(int num)
{
	if (this->storage.size() >= this->size)
		throw NotEnoughSpaceException();
	else
		this->storage.push_back(num);
}

void Span::addRange(int start, int end)
{
	if (start >= end)
		throw NotRangeException();
	else if (this->storage.size() + (end - start + 1) > this->size)
		throw NotEnoughSpaceException();
	else
	{
		for(int i = start; i <= end; i++)
			this->storage.push_back(i);
	}
}

int Span::shortestSpan()
{
	int min = std::numeric_limits<int>::max();

	if (this->storage.size() < 2)
		throw NoSpanException();
	else
	{
		std::sort(this->storage.begin(), this->storage.end());
		for(unsigned int i = 0; i < this->storage.size() - 1; i++)
		{
			int dist = this->storage[i + 1] - this->storage[i];
			if (dist < min)
				min = dist;
		}
	}

	return min;
}

int Span::longestSpan()
{
	if (this->storage.size() < 2)
		throw NoSpanException();

	int s = this->storage.size();
	std::sort(this->storage.begin(), this->storage.end());

	return this->storage[s - 1] - this->storage[0];
}

void Span::printSpan()
{
    for(unsigned int i = 0; i < this->storage.size(); i++)
		std::cout << this->storage[i] << " ";
	
	std::cout << std::endl;
}