#ifndef FENCODEGEN_H
#define FENCODEGEN_H
#include <QtGui>
#include <QDialog>
#include <QTextEdit>
#include <QPushButton>

class fenCodeGen : public QDialog
{
    public:
        fenCodeGen(QString &code, QWidget *parent);

    private:
        QTextEdit *codeGenere;
        QPushButton *fermer;
};

#endif // FENCODEGEN_H
