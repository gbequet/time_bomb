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
    (this->tmp_lang.compare(this->lang) != 0)
    ? this->ui->valider_btn->setStyleSheet(
          "QPushButton"
          "{"
              "border-image:url(\":/images/icons/button-confirm-on.png\");"
          "}"

          "QPushButton:hover"
          "{"
              "border-image:url(\":/images/icons/button-confirm-on.png\");"
              "background-color:#73a6a0;"
              "border-radius: 30px;"
          "}")
    : this->ui->valider_btn->setStyleSheet(
          "QPushButton"
          "{"
              "border-image:url(\":/images/icons/button-confirm-off.png\");"
          "}");


    this->ui->lang_en_btn->setStyleSheet(
    "QPushButton"
    "{"
        "border-image:url(\":/images/miscs/flag-english.png\");"
    "}"

    "QPushButton:hover"
    "{"
        "border-image:url(\":/images/miscs/flag-english.png\");"
        "background-color:#73a6a0;"
        "border-radius: 30px;"
    "}");
}

void Options::selectLangueEn()
{
    this->tmp_lang = "en";
    (this->tmp_lang.compare(this->lang) != 0)
    ? this->ui->valider_btn->setStyleSheet(
          "QPushButton"
          "{"
              "border-image:url(\":/images/icons/button-confirm-on.png\");"
          "}"

          "QPushButton:hover"
          "{"
              "border-image:url(\":/images/icons/button-confirm-on.png\");"
              "background-color:#73a6a0;"
              "border-radius: 30px;"
          "}")
    : this->ui->valider_btn->setStyleSheet(
          "QPushButton"
          "{"
              "border-image:url(\":/images/icons/button-confirm-off.png\");"
          "}");



    this->ui->lang_fr_btn->setStyleSheet(
        "QPushButton"
        "{"
            "border-image:url(\":/images/miscs/flag-french.png\");"
        "}"

        "QPushButton:hover"
        "{"
            "border-image:url(\":/images/miscs/flag-french.png\");"
            "background-color:#73a6a0;"
            "border-radius: 30px;"
        "}");
}
