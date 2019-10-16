#include "home.h"
#include "ui_home.h"
#include "credits.h"

home::home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);

    connect(ui->power, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(ui->credits, SIGNAL(clicked()), this, SLOT(goCredit()));
}

home::~home()
{
    delete ui;
}


void home::goCredit()
{
    (new Credits())->showFullScreen();
    delete this;
}
