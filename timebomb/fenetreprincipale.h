#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QStackedWidget>
#include <fstream>
#include "home.h"
#include "regles.h"
#include "jeuenligne.h"
#include "creationsalon.h"
#include "salononline.h"
#include "jeulocal.h"
#include "reveal.h"
#include "plateau.h"
#include "options.h"
#include "credits.h"


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
    static Plateau *plateau;
    Options *options;
    static Reveal *reveal;
    Credits *credits;

    QString pseudo;
    QString nomSalon;

    static std::fstream& getOptionStream()
    {
      static std::fstream optionsFile;
      return optionsFile;
    }

public slots:
    void goRegles();
    void goHome();
    void goJeuEnLigne();
    void goCreationSalon();
    void goSalonOnline();
    void goJeuLocal();
    void goCredits();
    void recupertaionPseudo(QString);
    void recuperationNomSalon(QString);
    void recuperationnbrJoueur();
    static void goPlateau(int nbPlayers, std::vector<QString> users);
    void goOptions();
    void goQuit();
    void changeLangue();
    static void goReveal(int nbPlayers, std::vector<QString> users);
//    static void returnToReveal(int nbCard);


signals:
    void changerNom(QString);
    void changerNomSalon(QString);
    void changerNbrJoueur(int);
};

#endif // FENETREPRINCIPALE_H
