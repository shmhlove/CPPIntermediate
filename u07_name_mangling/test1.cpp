/* 빌드 하는 법
	g++ test1.cpp
	cl test1.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int square(int n)
{
    return n * n;
}

double square(double d)
{
    return d * d;
}

int main()
{
    printf("%d\n", square(3));
    printf("%f\n", square(3.3));
}