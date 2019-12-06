#include "fenetreprincipale.h"
#include <QPushButton>
#include <QVBoxLayout>

QStackedWidget * FenetrePrincipale::stack;


FenetrePrincipale::FenetrePrincipale()
{
    getOptionStream().open("./options.txt", std::fstream::in | std::fstream::out | std::fstream::app);

    FenetrePrincipale::stack =  new QStackedWidget();
    home = new Home(this);
    regle = new regles(this);
    jeuEnLigne = new JeuEnLigne(this);
    creationSalon = new CreationSalon(this);
    salonOnline = new SalonOnline(this);
    jeuLocal = new JeuLocal(this);
    options = new Options(this);

    FenetrePrincipale::stack->addWidget(home);
    FenetrePrincipale::stack->addWidget(regle);
    FenetrePrincipale::stack->addWidget(jeuEnLigne);
    FenetrePrincipale::stack->addWidget(creationSalon);
    FenetrePrincipale::stack->addWidget(salonOnline);
    FenetrePrincipale::stack->addWidget(jeuLocal);
    FenetrePrincipale::stack->addWidget(options);

    std::string line; std::string param = ""; QString value = "";
    std::size_t found;
    if(getOptionStream().is_open())
    {
        while (getline(getOptionStream(), line))
        {
            found = line.find_first_of(":");
            param = line.substr(0, found);
            value = QString::fromStdString(line.substr(found+1));

            //rajouter ici les comparaisons et attributions de valeurs du fichier options.txt
            if(param.compare("lang") == 0)
                options->lang = value;

            printf("options->%s = %s\n", param.c_str(), value.toStdString().c_str());

        }
    }
    fflush(stdout);

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
    FenetrePrincipale::setWindowTitle(QString("Accueil"));
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

void FenetrePrincipale::goOptions()
{
    this->setWindowTitle("Options");
    FenetrePrincipale::stack->setCurrentWidget(options);
}

void FenetrePrincipale::goPlateau()
{
    plateau = new Plateau(this);
    FenetrePrincipale::stack->addWidget(plateau);
    this->setWindowState(Qt::WindowFullScreen);
    FenetrePrincipale::stack->setCurrentWidget(plateau);
}

void FenetrePrincipale::goQuit()
{
    getOptionStream().close();
    QApplication::quit();
}

void FenetrePrincipale::changeLangue()
{
    options->lang = options->tmp_lang;
    printf("langue modifiée %s\n", options->lang.toStdString().c_str());
    goHome();
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
