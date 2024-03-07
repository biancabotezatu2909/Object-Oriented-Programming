#include "Tests.h"
#include "Repository.h"
#include "Service.h"
#include "Ui.h"
#define _CRT_DBG_MAP_ALLOC
#include <crtdbg.h>


int main() {
    testAll();
    Repository* repo = createRepository(30);
    Service* service = createService(repo);
    Ui* ui = createUi(service);

    start(ui);
    destroyUi(ui);
    _CrtDumpMemoryLeaks();

    return 0;
}
