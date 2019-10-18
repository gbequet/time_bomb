#include "jeulocal.h"
#include "ui_jeulocal.h"
#include "home.h"

JeuLocal::JeuLocal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JeuLocal)
{
    ui->setupUi(this);

    connect(ui->retour, SIGNAL(clicked()), this, SLOT(goHome()));
}

JeuLocal::~JeuLocal()
{
    delete ui;
}

void JeuLocal::goHome()
{
    (new home())->showFullScreen();
    delete this;
}
