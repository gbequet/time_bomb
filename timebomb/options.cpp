#include "options.h"
#include "ui_options.h"

QString Options::lang;

Options::Options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);

    this->ui->valider_btn->setEnabled(false);

    connect(ui->retour_btn, SIGNAL(clicked()), parent, SLOT(goHome()));
    connect(ui->annuler_btn, SIGNAL(clicked()), parent, SLOT(goHome()));
    connect(ui->valider_btn, SIGNAL(clicked()), parent, SLOT(changeLangue()));
    connect(ui->valider_btn, SIGNAL(clicked()), this, SLOT(resetUi()));
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

    if (this->tmp_lang.compare(this->lang, Qt::CaseInsensitive) != 0)
    {
        this->ui->valider_btn->setStyleSheet(
                  "QPushButton"
                  "{"
                      "border-image:url(\":/images/icons/button-confirm-on.png\");"
                  "}");
        this->ui->valider_btn->setEnabled(true);

        this->ui->lang_fr_btn->setStyleSheet(
        "QPushButton"
        "{"
            "border-image:url(\":/images/miscs/flag-french.png\");"
        "}");

        this->ui->lang_en_btn->setStyleSheet(
        "QPushButton"
        "{"
            "border-image:url(\":/images/miscs/flag-english-off.png\");"
        "}"

        "QPushButton:hover"
        "{"
            "background-color:#73a6a0;"
            "border-radius: 30px;"
        "}");
    }
    else
    {
        this->ui->lang_fr_btn->setStyleSheet(
            "QPushButton"
            "{"
                "border-image:url(\":/images/miscs/flag-french.png\");"
            "}");

        this->ui->lang_en_btn->setStyleSheet(
        "QPushButton"
        "{"
            "border-image:url(\":/images/miscs/flag-english-off.png\");"
        "}"

        "QPushButton:hover"
        "{"
            "background-color:#73a6a0;"
            "border-radius: 30px;"
        "}");

        this->ui->valider_btn->setStyleSheet(
        "QPushButton"
        "{"
            "border-image:url(\":/images/icons/button-confirm-off.png\");"
        "}");
        this->ui->valider_btn->setEnabled(false);
    }
}

void Options::selectLangueEn()
{
    this->tmp_lang = "en";
    if(this->tmp_lang.compare(this->lang) != 0)//si change de langue
    {
        this->ui->valider_btn->setStyleSheet(
        "QPushButton"
        "{"
            "border-image:url(\":/images/icons/button-confirm-on.png\");"
        "}");


        this->ui->lang_fr_btn->setStyleSheet(
            "QPushButton"
            "{"
                "border-image:url(\":/images/miscs/flag-french-off.png\");"
            "}"

            "QPushButton:hover"
            "{"
                "background-color:#73a6a0;"
                "border-radius: 30px;"
            "}");

        this->ui->lang_en_btn->setStyleSheet(
        "QPushButton"
        "{"
            "border-image:url(\":/images/miscs/flag-english.png\");"
        "}");
        this->ui->valider_btn->setEnabled(true);
    }
    else
    {
        this->ui->lang_fr_btn->setStyleSheet(
            "QPushButton"
            "{"
                "border-image:url(\":/images/miscs/flag-french-off.png\");"
            "}"

            "QPushButton:hover"
            "{"
                "background-color:#73a6a0;"
                "border-radius: 30px;"
            "}");

        this->ui->lang_en_btn->setStyleSheet(
        "QPushButton"
        "{"
            "border-image:url(\":/images/miscs/flag-english.png\");"
        "}");

        this->ui->valider_btn->setStyleSheet(
        "QPushButton"
        "{"
            "border-image:url(\":/images/icons/button-confirm-off.png\");"
        "}");
        this->ui->valider_btn->setEnabled(false);
    }
}

void Options::resetUi()
{
    if(this->lang.compare("fr",Qt::CaseInsensitive) == 0)
    {
        this->ui->lang_fr_btn->setStyleSheet(
                  "QPushButton"
                  "{"
                      "border-image:url(\":/images/miscs/flag-french.png\");"
                  "}");

        this->ui->lang_en_btn->setStyleSheet(
                  "QPushButton"
                  "{"
                      "border-image:url(\":/images/miscs/flag-english-off.png\");"
                  "}"

                  "QPushButton:hover"
                  "{"
                      "background-color:#73a6a0;"
                      "border-radius: 30px;"
                  "}");
    }
    else
    {
        this->ui->lang_fr_btn->setStyleSheet(
                  "QPushButton"
                  "{"
                      "border-image:url(\":/images/miscs/flag-french-off.png\");"
                  "}"

                  "QPushButton:hover"
                  "{"
                      "background-color:#73a6a0;"
                      "border-radius: 30px;"
                  "};");

        this->ui->lang_en_btn->setStyleSheet(
                  "QPushButton"
                  "{"
                      "border-image:url(\":/images/miscs/flag-english.png\");"
                  "}");
    }


    this->ui->valider_btn->setStyleSheet(
    "QPushButton"
    "{"
        "border-image:url(\":/images/icons/button-confirm-off.png\");"
    "}");
    this->ui->valider_btn->setEnabled(false);
}
