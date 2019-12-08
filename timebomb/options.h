#ifndef OPTIONS_H
#define OPTIONS_H

#include <QWidget>
#include <QTranslator>
#include <QInputDialog>

namespace Ui {
class Options;
}

class Options : public QWidget
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = nullptr);
    ~Options();

public:
    static QString lang;
    QString tmp_lang;


private slots:
    void selectLangueFr();
    void selectLangueEn();

private:
    Ui::Options *ui;
};

#endif // OPTIONS_H
