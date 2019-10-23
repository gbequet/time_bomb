#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QStackedWidget>
#include "home.h"
#include "regles.h"
#include "jeuenligne.h"
#include "creationsalon.h"
#include "salononline.h"
#include "jeulocal.h"

class FenetrePrincipale : public QWidget
{
    Q_OBJECT

public:
    FenetrePrincipale();
    QStackedWidget *stack;
    Home *home;
    regles *regle;
    JeuEnLigne *jeuEnLigne;
    CreationSalon *creationSalon;
    SalonOnline *salonOnline;
    JeuLocal *jeuLocal;


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

signals:
    void changerNom(QString);
    void changerNomSalon(QString);
};

#endif // FENETREPRINCIPALE_H
