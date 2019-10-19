#include "revealcard.h"
#include "ui_revealcard.h"

RevealCard::RevealCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RevealCard)
{
    ui->setupUi(this);
}

RevealCard::~RevealCard()
{
    delete ui;
}
