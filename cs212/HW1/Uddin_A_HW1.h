#ifndef __UDDIN__A__HW1_H__
#define __UDDIN__A__HW1_H__
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

class Point
{
	private:
		double x,y,z;
	public:
		Point();
		Point(double inX,double inY,double inZ = 0);
		Point(const Point &other);
		void setX(double inX);
		void setY(double inY);
		void setZ(double inZ);
		void setXY(double inX,double inY);
		void setXZ(double inX,double inZ);
		void setYZ(double inY,double inZ);
		void setXYZ(double inX,double inY,double inZ);
		double getX() const;
		double getY() const;
		double getZ() const;
		void print();
		double distance();
		double distance(const Point &other);
		bool line(const Point &other);
		Point cross(const Point &other);
		Point operator+(const Point &other);
		Point operator-(const Point &other);
		friend istream& operator>>(istream& ins,Point &pt);
		friend ostream& operator<<(ostream& outs,const Point &pt);
};

bool plane(Point* points,const Point &pt);//Point array must be of size 3
bool square(Point* points,int size);
Point centroid(Point* points,int size);


#endif
