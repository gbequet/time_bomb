#include <QApplication>
#include <iostream>
#include <QTextStream>
#include <QDebug>
#include "game.h"
#include "form.h"

using namespace std;

int main(int argc, char *argv[])
{
    vector<QString> users;
    users.push_back("Christian");
    users.push_back("Basile");
    users.push_back("Julien");
    users.push_back("Catherine");
    users.push_back("Pierre");
    users.push_back("David");

    Game game(6, users);

//    game.printDeck();
//    game.printPlayers();

    return 0;
}
