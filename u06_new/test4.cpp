/* 빌드 하는 법
	g++ test1.cpp
	cl test2.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/
#include <stdio.h>
#include <iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) { printf("Point(%d, %d)\n", x, y); }
	~Point() { printf("~Point()\n"); }
};

int main()
{
    int iMaxObject = 10;
	Point* p1 = static_cast<Point*>(operator new(sizeof(Point) * iMaxObject));
    for (int iLoop = 0; iLoop < iMaxObject; ++iLoop)
    {
        new(&p1[iLoop]) Point(iLoop, iLoop);
    }

    for (int iLoop = 0; iLoop < iMaxObject; ++iLoop)
    {
        p1[iLoop].~Point();
    }
    operator delete(p1);
}