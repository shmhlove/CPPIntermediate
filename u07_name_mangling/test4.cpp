/* 빌드 하는 법
	g++ test1.cpp
	cl test1.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

#include <stdio.h>
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
    // error
    //printf("%p\n", &square);
    // ok
    printf("%p\n", static_cast<int(*)(int)>(&square));
    printf("%p\n", static_cast<double(*)(double)>(&square));
    
    // error
    //auto p = &square;
    // ok
    int(*f)(int) = &square;
}