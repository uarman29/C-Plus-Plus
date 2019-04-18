#include <iostream>
#include "Uddin_A_HW1.h"
using namespace std;

int main()
{
	Point p1;
	Point p2(1.7,2.6,3.5);
	Point p3(p2);
	p1.print();
	p2.print();
	p3.print();

	p3.setX(10.1);
	p3.setY(25.6);
	p3.setZ(76.95);
	p3.print();

	p3.setXY(1.4,2.1);
	p3.print();
	p3.setXZ(3.4,5.7);
	p3.print();
	p3.setYZ(10,8);
	p3.print();
	p3.setXYZ(5.2,10.5,62.8);
	p3.print();

	cout<<"("<<p3.getX()<<","<<p3.getY()<<","<<p3.getZ()<<")\n";
	cout<<"Distance from origin: "<<p3.distance()<<"\n";

	Point p4 = p2 + p3;
	p4.print();

	p4 = p3-p2;
	p4.print();

	Point points[4] = {p1,p2,p3,p4};
	cout<<"The centroid of the points is: ";
	centroid(points,4).print();
	cout<<"\n";
	
	Point p5(3.4,5.2,7.0);
	cout<<"Is Colinear: "<<p2.line(p3)<<"\n";
	cout<<"Is Colinear: "<<p2.line(p5)<<"\n";
	cout<<"Is Colinear: "<<p2.line(Point(-1.7,-2.6,-3.5))<<"\n";
	cout<<"Is Colinear: "<<p2.line(Point(5,5,0))<<"\n";
	cout<<"Is Colinear: "<<Point(0,1,0).line(Point(0,2,0))<<"\n";
	cout<<"Is Colinear: "<<Point(0,0,1).line(Point(0,0,1))<<"\n";
	cout<<"Is Colinear: "<<Point(1,0,0).line(Point(2,0,0))<<"\n";
	cout<<"Is Colinear: "<<Point(1,1,0).line(Point(2,2,0))<<"\n";
	cout<<"Is Colinear: "<<Point(0,1,1).line(Point(0,2,2))<<"\n";
	cout<<"Is Colinear: "<<Point(1,0,0).line(Point(2,0,0))<<"\n";
	cout<<"Is Colinear: "<<Point(1,0,0).line(Point(0,0,0))<<"\n";


	cout<<p2.cross(p3);
	//cin>>p1;
	//cout<<p1;
	Point p6(1,2,0);
	Point points2[3] = {Point(.5,1,1.5),Point(2,1,0),Point(.5,.5,2)};
	cout<<"Is point on plane: "<<plane(points2,p6)<<"\n";

	Point points3[7] = {Point(0,0,0),Point(4.2,6.2,5.2),Point(5,0,0),Point(1,2,3),Point(0,5,0),Point(6,6,6),Point(5,5,0)};
	cout<<"Do these points make a square: "<<square(points3,7)<<"\n";

	Point points4[4] = {Point(20,10),Point(10,20),Point(20,20),Point(10,10)};
	cout<<"Do these points make a square: "<<square(points4,4)<<"\n";

	Point points5[4] = {Point(10,20),Point(20,20),Point(0,20),Point(10,20-sqrt(200))};
	cout<<"Do these points make a square: "<<square(points5,4)<<"\n";

	Point points6[5] = {Point(1,1),Point(3,5),Point(7,7),Point(5,3),Point(100,20)};
	cout<<"Do these points make a square: "<<square(points6,5)<<"\n";

	return 0;
}