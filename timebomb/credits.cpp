#include "credits.h"
#include "ui_credits.h"

Credits::Credits(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Credits)
{
    ui->setupUi(this);

    connect(ui->retour, SIGNAL(clicked()), parent, SLOT(goHome()));
}

Credits::~Credits()
{
    delete ui;
}
