#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QWidget>
#include <QLCDNumber>
#include <QSlider>
#include <QPushButton>
#include <QProgressBar>
#include <QLineEdit>
#include <QCheckBox>
#include <QDateEdit>
#include <QGroupBox>
#include <QGridLayout>
#include <QFormLayout>

class fenetre: public QWidget // On hérite de QWidget (IMPORTANT)
{
    Q_OBJECT

    public:
    fenetre();

    public slots:
    //void changerLargeur(int largeur);
    //void changeHeight(int Height);
    void ouvrirDialogue();

    //signals:
    //void agrandissementMax();


    private:
    QPushButton *m_button1;
    QPushButton *m_button2;
    QFormLayout *layout;
    QFormLayout *layout1;
    QFormLayout *layout2;
    QLineEdit *name;
    QLineEdit *parent_class;
    QCheckBox *option1;
    QCheckBox *option2;
    QCheckBox *option3;
    QCheckBox *check;
    QLineEdit *author;
    QDateEdit *creation_Date;
    QLineEdit *class_role;
    QGroupBox *groupBox1;
    QGroupBox *groupBox2;
    QGroupBox *groupBox3;
    QVBoxLayout *layout_Principal;


};

#endif // FENETRE_H
