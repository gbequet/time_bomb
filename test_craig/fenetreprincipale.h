#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QStackedWidget>
#include "home.h"
#include "regles.h"
#include "jeuenligne.h"
#include "creationsalon.h"
#include "salononline.h"
#include "jeulocal.h"
#include "reveal.h"
#include "plateau.h"

class FenetrePrincipale : public QWidget
{
    Q_OBJECT

public:
    FenetrePrincipale();
    static QStackedWidget *stack;
    Home *home;
    regles *regle;
    JeuEnLigne *jeuEnLigne;
    CreationSalon *creationSalon;
    SalonOnline *salonOnline;
    JeuLocal *jeuLocal;
    Plateau *plateau;


    QString pseudo;
    QString nomSalon;

public slots:
    void goRegles();
    void goHome();
    void goJeuEnLigne();
    void goCreationSalon();
    void goSalonOnline();
    void goJeuLocal();
    void recupertaionPseudo(QString);
    void recuperationNomSalon(QString);
    void recuperationnbrJoueur();
    void goPlateau(int);


signals:
    void changerNom(QString);
    void changerNomSalon(QString);
    void changerNbrJoueur(int);
};

#endif // FENETREPRINCIPALE_H
