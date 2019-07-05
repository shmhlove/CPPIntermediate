/* 빌드 하는 법
	g++ test7.cpp
	cl test7-subject.cpp /nologo /EHsc
	
	주의! VC++ 확장 문법 사용을 사용해야함.
	/Za 옵션을 사용하면 컴파일 안됨
*/

#include <iostream>
#include <string>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

#include <map>

class Window
{
	static map<int, Window*> this_map;
	
public:
	void Create()
	{
		int h1 = ec_make_window(OnMessageProcess);
		this_map[h1] = this;
	}
	static int OnMessageProcess(int hwnd, int msg, int param1, int param2)
	{
		Window * const self = this_map[hwnd];
		switch(msg)
		{
			case WM_LBUTTONDOWN:
				self->OnLButtonDown();
				break;
			case WM_KEYDOWN:
				self->OnKeyDown();
				break;
		}
		
		return 0;
	}
	
	virtual void OnLButtonDown(){}
	virtual void OnKeyDown(){}
};
map<int, Window*> Window::this_map;

class MyWindow : public Window
{
	virtual void OnLButtonDown()
	{
		cout << "L Button Down" << endl;
	}
	virtual void OnKeyDown()
	{
		cout << "Key Button Down" << endl;
	}
};

int main()
{
	MyWindow w;
	w.Create();
	
	ec_process_message();
}