#ifndef JEULOCAL_H
#define JEULOCAL_H

#include <QWidget>

namespace Ui {
class JeuLocal;
}

class JeuLocal : public QWidget
{
    Q_OBJECT

public:
    explicit JeuLocal(QWidget *parent = nullptr);
    ~JeuLocal();

public slots:
    void goHome();
    void goReveal();

private:
    Ui::JeuLocal *ui;
};

#endif // JEULOCAL_H