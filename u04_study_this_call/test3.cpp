/* 빌드 하는 법
	g++ test3.cpp
	cl test3.cpp /nolog /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

#include <iostream>
#include <windows.h>
using namespace std;

DWORD __stdcall foo(void* p)
{
	return 0;
}

int main()
{
	CreateThread(0, 0, 
		foo, 			// 스레드로 수행할 함수
		(void*)"A", 	// 스레드 함수로 보낼 인자
		0, 0);
}