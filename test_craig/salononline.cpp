#include "salononline.h"
#include "ui_salononline.h"

SalonOnline::SalonOnline(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SalonOnline)
{
    ui->setupUi(this);

    connect(ui->retour, SIGNAL(clicked()), parent, SLOT(goJeuEnLigne()));
    connect(ui->lancer, SIGNAL(clicked()), parent, SLOT(goSalonOnline()));
}

SalonOnline::~SalonOnline()
{
    delete ui;
}

void SalonOnline::setSalonDe(QString nom)
{
    ui->salonDe->setText(nom);
}
