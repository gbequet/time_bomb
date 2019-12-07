#include "fenetreprincipale.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <vector>

using namespace std;

#define OPTIONFILE "../test_craig/options.txt"
#define DEFAULTFILE "../test_craig/default.txt"

QStackedWidget * FenetrePrincipale::stack;
Reveal * FenetrePrincipale::reveal;
Plateau * FenetrePrincipale::plateau;

FenetrePrincipale::FenetrePrincipale()
{
    FenetrePrincipale::stack =  new QStackedWidget();
    home = new Home(this);
    regle = new regles(this);
    jeuEnLigne = new JeuEnLigne(this);
    creationSalon = new CreationSalon(this);
    salonOnline = new SalonOnline(this);
    jeuLocal = new JeuLocal(this);
    options = new Options(this);
    FenetrePrincipale::reveal = new Reveal(this, nullptr);
    FenetrePrincipale::plateau = new Plateau(this, nullptr);

    FenetrePrincipale::stack->addWidget(home);
    FenetrePrincipale::stack->addWidget(regle);
    FenetrePrincipale::stack->addWidget(jeuEnLigne);
    FenetrePrincipale::stack->addWidget(creationSalon);
    FenetrePrincipale::stack->addWidget(salonOnline);
    FenetrePrincipale::stack->addWidget(jeuLocal);
    FenetrePrincipale::stack->addWidget(options);
    FenetrePrincipale::stack->addWidget(FenetrePrincipale::reveal);
    FenetrePrincipale::stack->addWidget(FenetrePrincipale::plateau);

    // couleur de fond d'écran de tous les écrans
    this->setStyleSheet("background-color: #413425;");


    getOptionStream().open(OPTIONFILE, std::fstream::in);

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

            if((param.compare("lang") == 0))
                options->lang = value;

            printf("options->%s = %s\n", param.c_str(), value.toStdString().c_str());

        }
    }
    else
    {
        //Le fichier par défaut doit exister et être rempli avant de lancer le programme
        getOptionStream().open(DEFAULTFILE, std::fstream::in);

        while (getline(getOptionStream(), line))
        {
            found = line.find_first_of(":");
            param = line.substr(0, found);
            value = QString::fromStdString(line.substr(found+1));

            //rajouter ici les comparaisons et attributions de valeurs du fichier options.txt

            if((param.compare("lang") == 0))
                options->lang = value;

            printf("options->%s = %s\n", param.c_str(), value.toStdString().c_str());
        }
    }
    getOptionStream().close();

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

void FenetrePrincipale::goPlateau(int nbPlayers, std::vector<QString> users)
{
    Game_Controller *g = new Game_Controller(nbPlayers, users);
    FenetrePrincipale::plateau->setGame(g);
    FenetrePrincipale::stack->setCurrentWidget(FenetrePrincipale::plateau);
}

void FenetrePrincipale::goQuit()
{
    getOptionStream().close();
    QApplication::quit();
}

void FenetrePrincipale::changeLangue()
{
    if(!options->tmp_lang.isEmpty() && (options->lang.compare(options->tmp_lang)) != 0)
    {
        options->lang = options->tmp_lang;

        string content = "";

        string fileCopyName = "../test_craig/copy_options.txt";
        ofstream fileCopy;

        getOptionStream().open(OPTIONFILE, std::fstream::in);

        string param; string line; size_t found;
        if(getOptionStream().is_open())
        {
            while (getline(getOptionStream(), line))
            {
                found = line.find_first_of(":");
                param = line.substr(0, found);

                if(param.compare("lang") == 0)
                   line = "lang:" + options->lang.toStdString();

                content.append(line+"\n");
            }
            printf("%s\n", content.c_str());
            fflush(stdout);
        }
        else
        {
            getOptionStream().open(DEFAULTFILE, std::fstream::in);

            while (getline(getOptionStream(), line))
            {
                found = line.find_first_of(":");
                param = line.substr(0, found);

                if(param.compare("lang") == 0)
                   line = "lang:" + options->lang.toStdString();

                content.append(line+"\n");
            }
            printf("%s\n", content.c_str());
            fflush(stdout);
        }
        getOptionStream().close();

        fileCopy.open(fileCopyName, std::fstream::out);
        if(fileCopy.is_open())
            fileCopy << content;

        fileCopy.close();

        int res;
        if((res = remove(OPTIONFILE)) != 0)
            perror("suppression options failed");
        if((res = rename(fileCopyName.c_str(), OPTIONFILE)) != 0)
            perror("rename copy_options failed");
    }
    goHome();
}


void FenetrePrincipale::goReveal(int nbPlayers, vector<QString> users)
{
    Game_Controller *g = new Game_Controller(nbPlayers, users);
    FenetrePrincipale::reveal->setGame(g);
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
