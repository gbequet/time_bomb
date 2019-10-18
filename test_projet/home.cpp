#include "home.h"
#include "ui_home.h"
#include "credits.h"
#include "jeulocal.h"

home::home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);

    connect(ui->power, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(ui->credits, SIGNAL(clicked()), this, SLOT(goCredit()));
    connect(ui->jeu_local, SIGNAL(clicked()), this, SLOT(goJeuLocal()));
}

home::~home()
{
    delete ui;
}


void home::goCredit()
{
    (new Credits())->showFullScreen();
    delete this;
}

void home::goJeuLocal()
{
    (new JeuLocal())->showFullScreen();
    delete this;
}
