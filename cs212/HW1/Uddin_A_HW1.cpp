#include "Uddin_A_HW1.h"

Point::Point()
{
	x = 0;
	y = 0;
	z = 0;
}

Point::Point(double inX,double inY,double inZ)
{
	x = inX;
	y = inY;
	z = inZ;
}

//Needs some explaining
Point::Point(const Point &other)
{
	(*this).x = other.x;
	(*this).y = other.y;
	(*this).z = other.z;
}

void Point::setX(double inX){x = inX;}
void Point::setY(double inY){y = inY;}
void Point::setZ(double inZ){z = inZ;}

void Point::setXY(double inX,double inY)
{
	x = inX;
	y = inY;
}
void Point::setXZ(double inX,double inZ)
{
	x = inX;
	z = inZ;
}
void Point::setYZ(double inY,double inZ)
{
	y = inY;
	z = inZ;
}

void Point::setXYZ(double inX,double inY,double inZ)
{
	x = inX;
	y = inY;
	z = inZ;
}

double Point::getX() const{return x;}
double Point::getY() const{return y;}
double Point::getZ() const{return z;}

void Point::print()
{
	cout<<"("<<x<<","<<y<<","<<z<<")\n";
}

double Point::distance()
{
	return sqrt(x*x+y*y+z*z);
}

double Point::distance(const Point &other)
{
	return sqrt(pow(x-other.x,2)+pow(y-other.y,2)+pow(z-other.z,2));
}

bool Point::line(const Point &other)
{
	double multiple;

	if(x==0 && y==0 && z==0)
		return false;
	if(other.x==0 && other.y==0 && other.z==0)
		return true;


	if(x!=0 && other.x!=0)
	{
		multiple = other.x/x;
		return y*multiple == other.y && z*multiple==other.z;
	}
	else if(y!=0 && other.y!=0)
	{
		multiple = other.y/y;
		return x*multiple == other.x && z*multiple==other.z;
	}
	else if(z!=0 && other.z!=0)
	{
		multiple = other.z/z;
		return y*multiple == other.y && x*multiple==other.x;
	}

	return false;
}

Point Point::cross(const Point &other)
{
	return Point(y*other.z - z*other.y,-1*(x*other.z - z*other.x),x*other.y - y*other.x);
}

Point Point::operator+(const Point &other)
{
	return Point(other.x+x,other.y+y,other.z+z);
}

Point Point::operator-(const Point &other)
{
	return Point(x-other.x,y-other.y,z-other.z);
}

istream& operator>>(istream& ins,Point &pt)
{
	ins >> pt.x >> pt.y >> pt.z;
	return ins;
}

ostream& operator<<(ostream& outs,const Point &pt)
{
	outs <<"("<<pt.x <<","<< pt.y <<","<< pt.z<<")\n";
	return outs;
}


bool plane(Point* points,const Point & pt)
{
	Point u(points[1]-points[0]);
	Point v(points[2]-points[0]);
	Point normal(u.cross(v));
	double result = normal.getX()*(pt.getX()-points[0].getX()) + normal.getY()*(pt.getY()-points[0].getY()) + normal.getZ()*(pt.getZ()-points[0].getZ());
	return result == 0;
}

int factorial(int n)
{
	if(n == 0||n==1)
		return 1;
	return factorial(n-1)*n;
}

int combos(int size)
{
	return factorial(size)/(24*factorial(size-4));
}

bool square(Point* points,int size)
{
	assert(size>=4);
	int length = combos(size);
	int sets[length][4] = {{}};
	int count = 0;
	for(int i = 0;i<size;i++)
	{
		for(int j = i+1;j<size;j++)
		{
			for(int k = j+1;k<size;k++)
			{
				for(int l = k+1;l<size;l++)
				{
					
					sets[count][0] = i;
					sets[count][1] = j;
					sets[count][2] = k;
					sets[count][3] = l;
					count++;
				}
			}
		}
	}
	double d12;
	double d13;
	double d14;
	double d23;
	double d24;
	double d34;
	for(int i = 0;i<length;i++)
	{
		d12 = points[sets[i][0]].distance(points[sets[i][1]]);
		d13 = points[sets[i][0]].distance(points[sets[i][2]]);
		d14 = points[sets[i][0]].distance(points[sets[i][3]]);
		d23 = points[sets[i][1]].distance(points[sets[i][2]]);
		d24 = points[sets[i][1]].distance(points[sets[i][3]]);
		d34 = points[sets[i][2]].distance(points[sets[i][3]]);

		if(d12 == d13 && d14 == sqrt(2)*d12 && d23 == sqrt(2)*d12 && d24 == d34 && d24 == d12)
			return true;
		if(d12 == d14 && d13 == sqrt(2)*d12 && d24 == sqrt(2)*d12 && d23 == d34 && d34 == d12)
			return true;
		if(d13 == d14 && d12 == sqrt(2)*d13 && d34 == sqrt(2)*d13 && d24 == d23 && d24 == d13)
			return true;
	}
	return false;
}

Point centroid(Point* points,int size)
{
	double xTotal = 0;
	double yTotal = 0;
	double zTotal = 0;

	for(int i = 0;i<size;i++)
	{
		xTotal += points[i].getX();
		yTotal += points[i].getY();
		zTotal += points[i].getZ();
	}
	return Point(xTotal/size,yTotal/size,zTotal/size);
}