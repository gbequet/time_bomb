#include "regles.h"
#include "ui_regles.h"

regles::regles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regles)
{
    ui->setupUi(this);

    connect(ui->retour, SIGNAL(clicked()), parent, SLOT(goHome()));
}

regles::~regles()
{
    delete ui;
}
