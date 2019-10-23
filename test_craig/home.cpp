#include "home.h"
#include "ui_home.h"
#include "fenetreprincipale.h"

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);

    connect(ui->quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(ui->regles, SIGNAL(clicked()), parent, SLOT(goRegles()));
    connect(ui->jeuEnLigne, SIGNAL(clicked()), parent, SLOT(goJeuEnLigne()));
    connect(ui->jeuLocal, SIGNAL(clicked()), parent, SLOT(goJeuLocal()));
}

Home::~Home()
{
    delete ui;
}
