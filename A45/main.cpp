#include "Movie.h"
#include "UI.h"
#include "Tests.h"
#include <Windows.h>
#include <crtdbg.h>

using namespace std;

int main()
{

	testAll();
	
	     {
		Repository repo{};
		Service service{ repo };
		UI ui{ service };
		ui.run();
	}
	
	
	_CrtDumpMemoryLeaks();

	return 0;
}