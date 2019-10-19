#ifndef REVEALCARD_H
#define REVEALCARD_H

#include <QWidget>

namespace Ui {
class RevealCard;
}

class RevealCard : public QWidget
{
    Q_OBJECT

public:
    explicit RevealCard(QWidget *parent = nullptr);
    ~RevealCard();

public slots:
    void goHome();

private:
    Ui::RevealCard *ui;
};

#endif // REVEALCARD_H
