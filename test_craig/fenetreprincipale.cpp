#include "fenetreprincipale.h"
#include <QPushButton>
#include <QVBoxLayout>

FenetrePrincipale::FenetrePrincipale()
{
    stack = new QStackedWidget();

    home = new Home(this);
    regle = new regles(this);
    jeuEnLigne = new JeuEnLigne(this);
    creationSalon = new CreationSalon(this);
    salonOnline = new SalonOnline(this);
    jeuLocal = new JeuLocal(this);

    stack->addWidget(home);
    stack->addWidget(regle);
    stack->addWidget(jeuEnLigne);
    stack->addWidget(creationSalon);
    stack->addWidget(salonOnline);
    stack->addWidget(jeuLocal);

    stack->setCurrentWidget(home);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(stack);
    setLayout(layout);

    connect(this, SIGNAL(changerNom(QString)), creationSalon, SLOT(setNom(QString)));
    connect(this, SIGNAL(changerNomSalon(QString)), salonOnline, SLOT(setSalonDe(QString)));
    connect(this, SIGNAL(changerNbrJoueur(int)), salonOnline, SLOT(setNbrJoueur(int)));
}

void FenetrePrincipale::goRegles()
{
    stack->setCurrentWidget(regle);
}

void FenetrePrincipale::goHome()
{
    stack->setCurrentWidget(home);
}

void FenetrePrincipale::goJeuEnLigne()
{
    stack->setCurrentWidget(jeuEnLigne);
}

void FenetrePrincipale::goCreationSalon()
{
    stack->setCurrentWidget(creationSalon);
}

void FenetrePrincipale::goSalonOnline()
{
    stack->setCurrentWidget(salonOnline);
}

void FenetrePrincipale::goJeuLocal()
{
    stack->setCurrentWidget(jeuLocal);
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
