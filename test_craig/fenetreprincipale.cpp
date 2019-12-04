#include "fenetreprincipale.h"
#include <QPushButton>
#include <QVBoxLayout>

QStackedWidget * FenetrePrincipale::stack;

FenetrePrincipale::FenetrePrincipale()
{

    FenetrePrincipale::stack =  new QStackedWidget();
    home = new Home(this);
    regle = new regles(this);
    jeuEnLigne = new JeuEnLigne(this);
    creationSalon = new CreationSalon(this);
    salonOnline = new SalonOnline(this);
    jeuLocal = new JeuLocal(this);
    plateau = new Plateau(this);

    FenetrePrincipale::stack->addWidget(home);
    FenetrePrincipale::stack->addWidget(regle);
    FenetrePrincipale::stack->addWidget(jeuEnLigne);
    FenetrePrincipale::stack->addWidget(creationSalon);
    FenetrePrincipale::stack->addWidget(salonOnline);
    FenetrePrincipale::stack->addWidget(jeuLocal);
    FenetrePrincipale::stack->addWidget(plateau);

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
    FenetrePrincipale::stack->setCurrentWidget(plateau);


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
