/* 빌드 하는 법
	g++ test1.cpp
	cl test1.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(int a, int b) : x(a), y(b)
{
}
	
void Point::set(int a, int b)
{
	x = a;
	y = b;
}
	
void Point::print() const
{
	cout << x << ", " << y << endl;
}