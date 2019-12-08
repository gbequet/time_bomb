#include "home.h"
#include "ui_home.h"
#include "fenetreprincipale.h"

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);

    connect(ui->regles, SIGNAL(clicked()), parent, SLOT(goRegles()));
    connect(ui->jeuEnLigne, SIGNAL(clicked()), parent, SLOT(goJeuEnLigne()));
    connect(ui->jeuLocal, SIGNAL(clicked()), parent, SLOT(goJeuLocal()));
    connect(ui->options, SIGNAL(clicked()), parent, SLOT(goOptions()));
    connect(ui->quitter, SIGNAL(clicked()), parent, SLOT(goQuit()));
    connect(ui->credits, SIGNAL(clicked()), parent, SLOT(goCredits()));
}

Home::~Home()
{
    delete ui;
}
