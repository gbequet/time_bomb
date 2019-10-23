#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QStackedWidget>
#include "home.h"
#include "regles.h"
#include "jeuenligne.h"
#include "creationsalon.h"
#include "salononline.h"

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

    QString pseudo;
    QString nomSalon;

public slots:
    void goRegles();
    void goHome();
    void goJeuEnLigne();
    void goCreationSalon();
    void goSalonOnline();
    void recupertaionPseudo(QString);
    void recuperationNomSalon(QString);

signals:
    void changerNom(QString);
};

#endif // FENETREPRINCIPALE_H
