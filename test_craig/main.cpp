#include <QApplication>
#include "fenetreprincipale.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    static std::fstream optionsFile;

    FenetrePrincipale fenetre;
    fenetre.show();

    return app.exec();
}
