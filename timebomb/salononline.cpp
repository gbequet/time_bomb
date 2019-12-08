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

void SalonOnline::setNbrJoueur(int nbr)
{
    QLineEdit *line[4];
    line[0] = ui->joueur5;
    line[1] = ui->joueur6;
    line[2] = ui->joueur7;
    line[3] = ui->joueur8;

    int i;
    for(i=8; nbr<i; i--)
    {
        line[i-5]->setStyleSheet("background-color: #3d595a;");
    }
    while(i!=4)
    {
        line[i-5]->setStyleSheet("background-color: #53230a;");
        i--;
    }
}
