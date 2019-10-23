#include "regles.h"
#include "ui_regles.h"

regles::regles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regles)
{
    ui->setupUi(this);

    QMediaPlayer *player = new QMediaPlayer;
    QVideoWidget *videoWidget = new QVideoWidget;

    player->setVideoOutput(videoWidget);
    player->setMedia(QUrl::fromLocalFile(""));

    ui->layoutVideo->addWidget(videoWidget);
    player->play();

    connect(ui->retour, SIGNAL(clicked()), parent, SLOT(goHome()));
}

regles::~regles()
{
    delete ui;
}
