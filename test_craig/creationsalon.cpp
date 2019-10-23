#include "creationsalon.h"
#include "ui_creationsalon.h"
#include "fenetreprincipale.h"

CreationSalon::CreationSalon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreationSalon)
{
    ui->setupUi(this);

    connect(ui->retour, SIGNAL(clicked()), parent, SLOT(goJeuEnLigne()));

    connect(ui->nbrJoueur4, SIGNAL(clicked()), this, SLOT(unSeulJoueur()));
    connect(ui->nbrJoueur5, SIGNAL(clicked()), this, SLOT(unSeulJoueur()));
    connect(ui->nbrJoueur6, SIGNAL(clicked()), this, SLOT(unSeulJoueur()));
    connect(ui->nbrJoueur7, SIGNAL(clicked()), this, SLOT(unSeulJoueur()));
    connect(ui->nbrJoueur8, SIGNAL(clicked()), this, SLOT(unSeulJoueur()));

    connect(ui->timer30, SIGNAL(clicked()), this, SLOT(unSeulTimer()));
    connect(ui->timer60, SIGNAL(clicked()), this, SLOT(unSeulTimer()));
    connect(ui->timer90, SIGNAL(clicked()), this, SLOT(unSeulTimer()));
    connect(ui->timer120, SIGNAL(clicked()), this, SLOT(unSeulTimer()));
    connect(ui->timerInfinity, SIGNAL(clicked()), this, SLOT(unSeulTimer()));

    connect(ui->nomSalon, SIGNAL(textEdited(QString)), parent, SLOT(recuperationNomSalon(QString)));
}

CreationSalon::~CreationSalon()
{
    delete ui;
}

void CreationSalon::unSeulJoueur()
{
    QPushButton *tab[5];
    tab[0] = ui->nbrJoueur4;
    tab[1] = ui->nbrJoueur5;
    tab[2] = ui->nbrJoueur6;
    tab[3] = ui->nbrJoueur7;
    tab[4] = ui->nbrJoueur8;

    int i;
    for(i=0; i<5; i++)
    {
        if(tab[i]->isChecked())
        {
            tab[i]->setChecked(false);
        }
    }

    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    btn->setChecked(true);
}

void CreationSalon::unSeulTimer()
{
    QPushButton *tab[5];
    tab[0] = ui->timer30;
    tab[1] = ui->timer60;
    tab[2] = ui->timer90;
    tab[3] = ui->timer120;
    tab[4] = ui->timerInfinity;

    int i;
    for(i=0; i<5; i++)
    {
        if(tab[i]->isChecked())
        {
            tab[i]->setChecked(false);
        }
    }

    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    btn->setChecked(true);
}

void CreationSalon::setNom(QString pseudo)
{
    ui->nomSalon->setText("Salon de " + pseudo);
}
