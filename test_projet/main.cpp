#include <QApplication>
#include "home.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    home *fenetre;
    fenetre = new home();

    fenetre->showFullScreen();

    return app.exec();
}
