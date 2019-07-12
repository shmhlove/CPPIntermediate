/* 빌드 하는 법
	g++ test1.cpp
	cl test1.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;

int square(int n)
{
    return n * n;
}

int main()
{
    // ok, 함수주소 꺼내기
    int(*f1)(int) = &square;
    // ok, 함수이름은 함수주소로 암시적 형변환
    int(*f2)(int) = square;
    
    // 함수 포인터 타입
    typedef void(*PF)(int);
    // 함수 타입
    typedef void F(int);
    
    // int (__cdecl*)(int)
    printf("%s\n", typeid(&square).name());
    // int __cdecl(int)
    printf("%s\n", typeid(square).name());
    
    // g++ 컴파일러로 컴파일된 exe에서 보면 mangling되어 버린다.
    // 타입을 정확히 보고싶으면 test5.exe | c++filt -t 옵션을 주면된다.    
}