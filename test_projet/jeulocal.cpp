#include "jeulocal.h"
#include "ui_jeulocal.h"
#include "home.h"
#include "revealcard.h"

JeuLocal::JeuLocal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JeuLocal)
{
    ui->setupUi(this);

    connect(ui->retour, SIGNAL(clicked()), this, SLOT(goHome()));
    connect(ui->start, SIGNAL(clicked()), this, SLOT(goReveal()));
}

JeuLocal::~JeuLocal()
{
    delete ui;
}

void JeuLocal::goHome()
{
    (new home())->show();
    delete this;
}

void JeuLocal::goReveal()
{
    (new RevealCard())->show();
    delete this;
}
