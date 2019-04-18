#include "Bag.h"

Bag::Bag()
{
	used = 0;
}

size_t Bag::size() const
{
	return used;
}

void Bag::print() const
{
	for(size_t i = 0;i<used-1;i++)
	{
		cout<<data[i]<<", ";
	}
	cout<<data[used-1]<<"\n";
}

size_t Bag::count(const Bag::bagDatatype& target) const
{
	size_t answer = 0;
	for(int i=0;i<used;i++)
		if(data[i]==target)
			answer++;
	return answer;
}

void Bag::insert(const Bag::bagDatatype& newEntry)
{
	assert(used<CAPACITY);
	data[used] = newEntry;
	used++;
}

bool Bag::eraseOne(const Bag::bagDatatype& target)
{
	size_t index = 0;
	while(index<used && data[index]!=target)
		index++;

	if(index == used)
		return false;
	used--;
	data[index] = data[used];
	return true;
}

size_t Bag::erase(const bagDatatype& target)
{
	size_t index = 0;
	size_t numRemoved = 0;
	while(index<used)
	{
		if(data[index]==target)
		{
			used--;
			data[0] = data[used];
			numRemoved++;
		}
		else
			index++;
	}
	return numRemoved;
}

void Bag::operator +=(const Bag& addend)
{
	assert(size()+addend.size()<=CAPACITY);
	size_t length = addend.used;
	for(size_t i = 0;i<length;i++)
	{
		data[used] = addend.data[i];
		used++;
	}
}