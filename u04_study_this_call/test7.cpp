/* 빌드 하는 법
	g++ test4.cpp
	cl test4.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

#include <iostream>
#include <string>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

int foo(int hwnd, int msg, int param1, int param2)
{
	cout << hwnd << " : " << msg << endl;

	return 0;
}

int main()
{
	int h1 = ec_make_window(foo);
	int h2 = ec_make_window(foo);
	
	ec_process_message();
}