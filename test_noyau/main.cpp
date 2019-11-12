#include <QApplication>
#include <iostream>
#include <QTextStream>
#include <QDebug>
#include "game.h"
#include "form.h"

using namespace std;

void simulationJeu(int nbjoueurs){
    vector<QString> users;
    users.push_back("Craig");
    users.push_back("Joren");
    users.push_back("Guillaume");
    users.push_back("Sam");
    users.push_back("Arthur");



    /*for(int j = 0; j < users.size();j++){
        qDebug() << users[j];
    }*/

    Game game(nbjoueurs, users);
}

int main(int argc, char *argv[])
{
    /*vector<QString> users;
    users.push_back("Christian");
    users.push_back("Basile");
    users.push_back("Julien");
    users.push_back("Catherine");
    users.push_back("Pierre");
    users.push_back("David");

    Game game(6, users);*/
    simulationJeu(4);

//    game.printDeck();
//    game.printPlayers();

    return 0;
}


