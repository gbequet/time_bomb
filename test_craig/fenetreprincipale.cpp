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

    stack->addWidget(home);
    stack->addWidget(regle);
    stack->addWidget(jeuEnLigne);
    stack->addWidget(creationSalon);
    stack->addWidget(salonOnline);

    stack->setCurrentWidget(home);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(stack);
    setLayout(layout);

    connect(this, SIGNAL(changerNom(QString)), creationSalon, SLOT(setNom(QString)));
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

void FenetrePrincipale::recupertaionPseudo(QString pseudo)
{
    this->pseudo = pseudo;

    this->nomSalon = "Salon de " + pseudo;

    emit changerNom(pseudo);
}

void FenetrePrincipale::recuperationNomSalon(QString nom)
{
    nomSalon = nom;
}
