/* 빌드 하는 법
	g++ test1.cpp
	cl test1.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

// 팁
// 1. 함수 오버로딩을 이용해서
//    상수멤버함수와 비상수멤버함수를 만들 수 있다.
//    
// 2. 구현부가 분리되어 있을때
//    상수멤버함수에 const를 붙혀주는것을 잊지말자.
//    잘 놓치는 부분이다.

#include <stdio.h>
#include <iostream>
using namespace std;

struct Test
{
	void foo()			{ cout << "foo()" << endl; }
	void foo()	const	{ cout << "foo() const" << endl; }
	
	void goo()	const;
};

void Test::goo() const
{
	 cout << "goo() const" << endl; 
}

int main()
{
	Test t1;
	t1.foo();
	t1.goo();
	
	const Test t2;
	t2.foo();
	t2.goo();
}