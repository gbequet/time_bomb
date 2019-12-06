#ifndef JEULOCAL_H
#define JEULOCAL_H

#include <vector>
#include <QWidget>
#include "ui_jeulocal.h"

namespace Ui {
class JeuLocal;
}

class JeuLocal : public QWidget
{
    Q_OBJECT

public:
    explicit JeuLocal(QWidget *parent = nullptr);
    ~JeuLocal();

private slots:
    void unSeulJoueur();
    std::vector<QString> getUsers();
    int getNbPlayer();

private:
    Ui::JeuLocal *ui;
    int nb_player;
    std::vector<QString> players;
};

#endif // JEULOCAL_H
