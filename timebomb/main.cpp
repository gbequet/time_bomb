#include <QApplication>
#include "fenetreprincipale.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator translator;
    translator.load(":/english.qm");

    FenetrePrincipale fenetre;
    fenetre.show();

    return app.exec();
}
