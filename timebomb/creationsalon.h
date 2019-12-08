#ifndef CREATIONSALON_H
#define CREATIONSALON_H

#include <QWidget>

namespace Ui {
class CreationSalon;
}

class CreationSalon : public QWidget
{
    Q_OBJECT

public:
    explicit CreationSalon(QWidget *parent = nullptr);
    ~CreationSalon();

private:
    Ui::CreationSalon *ui;

private slots:
    void unSeulJoueur();
    void unSeulTimer();
    void setNom(QString);
};

#endif // CREATIONSALON_H
