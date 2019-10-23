#include "jeulocal.h"
#include "ui_jeulocal.h"

JeuLocal::JeuLocal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JeuLocal)
{
    ui->setupUi(this);

    connect(ui->retour, SIGNAL(clicked()), parent, SLOT(goHome()));
}

JeuLocal::~JeuLocal()
{
    delete ui;
}
