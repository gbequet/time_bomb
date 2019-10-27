#include "jeulocal.h"
#include "ui_jeulocal.h"

JeuLocal::JeuLocal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JeuLocal)
{
    ui->setupUi(this);

    connect(ui->retour, SIGNAL(clicked()), parent, SLOT(goHome()));

    connect(ui->nbrJoueur4, SIGNAL(clicked()), this, SLOT(unSeulJoueur()));
    connect(ui->nbrJoueur5, SIGNAL(clicked()), this, SLOT(unSeulJoueur()));
    connect(ui->nbrJoueur6, SIGNAL(clicked()), this, SLOT(unSeulJoueur()));
    connect(ui->nbrJoueur7, SIGNAL(clicked()), this, SLOT(unSeulJoueur()));
    connect(ui->nbrJoueur8, SIGNAL(clicked()), this, SLOT(unSeulJoueur()));
}

JeuLocal::~JeuLocal()
{
    delete ui;
}

void JeuLocal::unSeulJoueur()
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

    QLineEdit *line[4];
    line[0] = ui->joueur5;
    line[1] = ui->joueur6;
    line[2] = ui->joueur7;
    line[3] = ui->joueur8;

    QPushButton *bot[5];
    bot[0] = ui->bot5;
    bot[1] = ui->bot6;
    bot[2] = ui->bot7;
    bot[3] = ui->bot8;

    int nbr = btn->text().toInt();
    for(i=8; nbr<i; i--)
    {
        line[i-5]->setText("");
        line[i-5]->setReadOnly(true);
        bot[i-5]->setCheckable(false);
    }
    while(i!=4)
    {
        line[i-5]->setReadOnly(false);
        bot[i-5]->setCheckable(true);
        line[i-5]->setText("joueur"+QVariant(i).toString());
        i--;
    }
}
