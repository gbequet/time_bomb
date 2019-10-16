#include "credits.h"
#include "ui_credits.h"
#include "home.h"

Credits::Credits(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Credits)
{
    ui->setupUi(this);

    connect(ui->retour, SIGNAL(clicked()), this, SLOT(goHome()));
}

Credits::~Credits()
{
    delete ui;
}

void Credits::goHome()
{
    (new home())->showFullScreen();
    delete this;
}
