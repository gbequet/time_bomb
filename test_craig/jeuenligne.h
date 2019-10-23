#ifndef JEUENLIGNE_H
#define JEUENLIGNE_H

#include <QWidget>

namespace Ui {
class JeuEnLigne;
}

class JeuEnLigne : public QWidget
{
    Q_OBJECT

public:
    explicit JeuEnLigne(QWidget *parent = nullptr);
    ~JeuEnLigne();

private:
    Ui::JeuEnLigne *ui;
};

#endif // JEUENLIGNE_H
