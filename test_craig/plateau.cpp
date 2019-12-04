#include "plateau.h"
#include "ui_plateau.h"
#include "game_controller.h"
#include "fenetreprincipale.h"

Plateau::Plateau(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Plateau)
{
    parent->setWindowState(Qt::WindowFullScreen);
    ui->setupUi(this);
}


Plateau::~Plateau()
{
    delete ui;
}
