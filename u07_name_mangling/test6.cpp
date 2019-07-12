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

struct FLOAT
{
    // 변환 생성자
    // float => FLOAT로 변환허용
    FLOAT(float){}
};

//template<typename T>
//void foo(T  )       { printf("T"); }
//void foo(int)       { printf("int"); }
//void foo(double)    { printf("double"); }
//void foo(float)     { printf("float"); }
//void foo(FLOAT)     { printf("FLOAT"); }
void foo(...)       { printf("..."); }

int main()
{
    // exactly matching
    float f = 3.14f;
    foo(f);
    
    // 암시적변환 순서
    // float : 정확한 버전
    // template : 암시적 형변환이 가능한 버전
    // double : 데이터손실이 없는 버전
    // int : 데이터손실 우려는 있으나 가능한 버전
    // FLOAT : 변환생성자 버전
    // ... : 가변인자 버전
    
    // exactly matching
    // template
    // promotion
    // standard conversion
    // user define conversion
    // variadic argument
}