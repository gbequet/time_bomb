#include "jeuenligne.h"
#include "ui_jeuenligne.h"

JeuEnLigne::JeuEnLigne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JeuEnLigne)
{
    ui->setupUi(this);

    connect(ui->retour, SIGNAL(clicked()), parent, SLOT(goHome()));
    connect(ui->creer, SIGNAL(clicked()), parent, SLOT(goCreationSalon()));

    connect(ui->pseudo, SIGNAL(textEdited(QString)), parent, SLOT(recupertaionPseudo(QString)));
}

JeuEnLigne::~JeuEnLigne()
{
    delete ui;
}
