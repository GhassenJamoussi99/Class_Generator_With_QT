#include <QApplication>
#include <QPushButton>
#include <QIcon>
#include "fenetre.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
 /*
    // Création d'un widget qui servira de fenêtre
    QWidget fenetre;
    fenetre.setFixedSize(300, 150);
    // Création du bouton, ayant pour parent la "fenêtre"
    QPushButton bouton("zab !", &fenetre);
    // Personnalisation du bouton
    bouton.setFont(QFont("Comic Sans MS", 20 , QFont::Bold , true));
    bouton.setCursor(Qt::PointingHandCursor);
    QIcon foo("Icons/zebi.png");
    bouton.setIcon(foo);
    bouton.move(0,0);
    // Affichage de la fenêtre
    fenetre.show();
 */
   // m_bouton = new QPushButton("Quitter",&fenetre);

    fenetre  m_fenetre;
    m_fenetre.show();

    return app.exec();
}
