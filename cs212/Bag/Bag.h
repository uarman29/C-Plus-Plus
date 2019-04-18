#ifndef __BAG_H__
#define __BAG_H__
#include <iostream>
#include <cstdlib>
#include <assert.h>
using namespace std;


static const size_t CAPACITY = 50;

class Bag
{
	typedef int bagDatatype;
	private:
		bagDatatype data[CAPACITY];
		size_t used;

	public:
		Bag();
		size_t size() const;
		void print() const;
		size_t count(const bagDatatype& target) const;
		void insert(const bagDatatype& newEntry);
		bool eraseOne(const bagDatatype& target);
		size_t erase(const bagDatatype& target);
		void operator +=(const Bag& addend);
		friend Bag operator +(const Bag& b1,const Bag& b2);
		friend Bag operator -(const Bag& b1,const Bag& b2);

};
#endif