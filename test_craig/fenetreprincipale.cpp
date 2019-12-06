#include "fenetreprincipale.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <vector>

using namespace std;

QStackedWidget * FenetrePrincipale::stack;
Reveal * FenetrePrincipale::reveal;

FenetrePrincipale::FenetrePrincipale()
{

    FenetrePrincipale::stack =  new QStackedWidget();
    home = new Home(this);
    regle = new regles(this);
    jeuEnLigne = new JeuEnLigne(this);
    creationSalon = new CreationSalon(this);
    salonOnline = new SalonOnline(this);
    jeuLocal = new JeuLocal(this);
    FenetrePrincipale::reveal = new Reveal(this, nullptr);


    FenetrePrincipale::stack->addWidget(home);
    FenetrePrincipale::stack->addWidget(regle);
    FenetrePrincipale::stack->addWidget(jeuEnLigne);
    FenetrePrincipale::stack->addWidget(creationSalon);
    FenetrePrincipale::stack->addWidget(salonOnline);
    FenetrePrincipale::stack->addWidget(jeuLocal);
    FenetrePrincipale::stack->addWidget(FenetrePrincipale::reveal);

    FenetrePrincipale::stack->setCurrentWidget(home);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(FenetrePrincipale::stack);
    setLayout(layout);

    connect(this, SIGNAL(changerNom(QString)), creationSalon, SLOT(setNom(QString)));
    connect(this, SIGNAL(changerNomSalon(QString)), salonOnline, SLOT(setSalonDe(QString)));
    connect(this, SIGNAL(changerNbrJoueur(int)), salonOnline, SLOT(setNbrJoueur(int)));
}

void FenetrePrincipale::goRegles()
{
    FenetrePrincipale::stack->setCurrentWidget(regle);
}

void FenetrePrincipale::goHome()
{
    FenetrePrincipale::stack->setCurrentWidget(home);
}

void FenetrePrincipale::goJeuEnLigne()
{
    FenetrePrincipale::stack->setCurrentWidget(jeuEnLigne);
}

void FenetrePrincipale::goCreationSalon()
{
    FenetrePrincipale::stack->setCurrentWidget(creationSalon);
}

void FenetrePrincipale::goSalonOnline()
{
    FenetrePrincipale::stack->setCurrentWidget(salonOnline);
}

void FenetrePrincipale::goJeuLocal()
{

    FenetrePrincipale::stack->setCurrentWidget(jeuLocal);
}

void FenetrePrincipale::goPlateau()
{
    plateau = new Plateau(this);
    FenetrePrincipale::stack->addWidget(plateau);
    this->setWindowState(Qt::WindowFullScreen);
    FenetrePrincipale::stack->setCurrentWidget(plateau);
}

void FenetrePrincipale::goReveal(int nbPlayer, vector<QString> users)
{
    Game_Controller g(nbPlayer, users);
    FenetrePrincipale::reveal->setGame(&g);
    FenetrePrincipale::stack->setCurrentWidget(FenetrePrincipale::reveal);
}

void FenetrePrincipale::recupertaionPseudo(QString pseudo)
{
    this->pseudo = pseudo;

    this->nomSalon = "Salon de " + pseudo;

    emit changerNom(pseudo);
    emit changerNomSalon(this->nomSalon);
}

void FenetrePrincipale::recuperationNomSalon(QString nom)
{
    nomSalon = nom;
    emit changerNomSalon(this->nomSalon);
}

void FenetrePrincipale::recuperationnbrJoueur()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    int nbr = btn->text().toInt();
    emit changerNbrJoueur(nbr);
}
