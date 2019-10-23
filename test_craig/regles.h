#ifndef REGLES_H
#define REGLES_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>

namespace Ui {
class regles;
}

class regles : public QWidget
{
    Q_OBJECT

public:
    explicit regles(QWidget *parent = nullptr);
    ~regles();

private:
    Ui::regles *ui;
};

#endif // REGLES_H
