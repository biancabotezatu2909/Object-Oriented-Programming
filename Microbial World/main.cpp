#include "BacteriaManagement.h"
#include <QtWidgets/QApplication>
#include "BiologistWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo("biologists.txt","bacteria.txt");
    //BacteriaTableModel* mdl = new BacteriaTableModel(repo);
   // std::vector<BacteriaTableModel*>models;
    std::vector<BiologistWidget*> windows;
    for (auto it : repo.get_biologists()) {
        BacteriaTableModel* mdl = new BacteriaTableModel(repo, it);
        BiologistWidget* bwd = new BiologistWidget(mdl, repo, it);
        windows.push_back(bwd);
    }
    for (auto it : windows)
        it->show();
    return a.exec();
}
