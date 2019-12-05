#include "plateau.h"
#include "ui_plateau.h"
#include "game_controller.h"
#include "fenetreprincipale.h"

Plateau::Plateau(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Plateau)
{
    ui->setupUi(this);


    connect(ui->player_button, SIGNAL(clicked()), this, SLOT(click_home()));


}

void Plateau::click_home(){
    qDebug() << "Ok boi";
}


Plateau::~Plateau()
{
    delete ui;
}
