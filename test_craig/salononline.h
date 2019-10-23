#ifndef SALONONLINE_H
#define SALONONLINE_H

#include <QWidget>

namespace Ui {
class SalonOnline;
}

class SalonOnline : public QWidget
{
    Q_OBJECT

public:
    explicit SalonOnline(QWidget *parent = nullptr);
    ~SalonOnline();

private:
    Ui::SalonOnline *ui;

private slots:
    void setSalonDe(QString);
};

#endif // SALONONLINE_H
