#include "revealcard.h"
#include "ui_revealcard.h"
#include "home.h"

RevealCard::RevealCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RevealCard)
{
    ui->setupUi(this);

    connect(ui->home, SIGNAL(clicked()), this, SLOT(goHome()));
}

RevealCard::~RevealCard()
{
    delete ui;
}

void RevealCard::goHome()
{
    (new home())->show();
    delete this;
}
