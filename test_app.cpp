#include <stdio.h>

class CppTest
{
public:
	CppTest()
	{
		printf("Hello from C++!\n");
	}
};

static auto test = new CppTest;

extern "C" void graphics_app(void)
{
}

