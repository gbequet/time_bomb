#include "options.h"
#include "ui_options.h"

QString Options::lang;

Options::Options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);

    connect(ui->retour_btn, SIGNAL(clicked()), parent, SLOT(goHome()));
    connect(ui->annuler_btn, SIGNAL(clicked()), parent, SLOT(goHome()));
    connect(ui->valider_btn, SIGNAL(clicked()), parent, SLOT(changeLangue()));

    connect(ui->lang_fr_btn, SIGNAL(clicked()), this, SLOT(selectLangueFr()));
    connect(ui->lang_en_btn, SIGNAL(clicked()), this, SLOT(selectLangueEn()));
}

Options::~Options()
{
    delete ui;
}

void Options::selectLangueFr()
{
    this->tmp_lang = "fr";

    this->ui->lang_en_btn->setStyleSheet("border-image:url(\":/images/miscs/flag-english.png\")");
}

void Options::selectLangueEn()
{
    this->tmp_lang = "en";

    this->ui->lang_fr_btn->setStyleSheet("border-image:url(\":/images/miscs/flag-french.png\")");
}
