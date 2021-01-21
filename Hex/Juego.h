#ifndef JUEGO_H
#define JUEGO_H

#include <QMainWindow>

namespace Ui {
class Juego;
}

class Juego : public QMainWindow
{
    Q_OBJECT

public:
    explicit Juego(QWidget *parent = 0);
    ~Juego();

private:
    Ui::Juego *ui;
};

#endif // JUEGO_H
