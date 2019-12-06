#include <vector>
#include "jeulocal.h"
#include "ui_jeulocal.h"
#include "game_controller.h"
#include "fenetreprincipale.h"

using namespace std;

JeuLocal::JeuLocal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JeuLocal)
{
    ui->setupUi(this);

    connect(ui->retour, SIGNAL(clicked()), parent, SLOT(goHome()));
    connect(ui->jouer, SIGNAL(clicked()), parent, SLOT(goPlateau()));

    connect(ui->nbrJoueur4, SIGNAL(clicked()), this, SLOT(unSeulJoueur()));
    connect(ui->nbrJoueur5, SIGNAL(clicked()), this, SLOT(unSeulJoueur()));
    connect(ui->nbrJoueur6, SIGNAL(clicked()), this, SLOT(unSeulJoueur()));
    connect(ui->nbrJoueur7, SIGNAL(clicked()), this, SLOT(unSeulJoueur()));
    connect(ui->nbrJoueur8, SIGNAL(clicked()), this, SLOT(unSeulJoueur()));
    connect(ui->rev, &QPushButton::clicked, [this]{
        int n = getNbPlayer();
        qDebug() << n << endl;
        vector<QString> users = getUsers();
        FenetrePrincipale::goReveal(n, users);
    });
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

vector<QString> JeuLocal::getUsers()
{
    vector<QString> users;

    users.clear();
    users.push_back(ui->joueur1->text());
    users.push_back(ui->joueur2->text());
    users.push_back(ui->joueur3->text());
    users.push_back(ui->joueur4->text());
    users.push_back(ui->joueur5->text());
    users.push_back(ui->joueur6->text());
    users.push_back(ui->joueur7->text());
    users.push_back(ui->joueur8->text());

    return users;
}

int JeuLocal::getNbPlayer()
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
            return i+4;
        }
    }
}
