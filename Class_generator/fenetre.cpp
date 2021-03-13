#include "fenetre.h"
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include <QFont>
#include <QFileDialog>
#include <QVBoxLayout>
#include "fenCodeGen.h"

fenetre::fenetre() : QWidget()
{
    setFixedSize(300,500);

    layout = new QFormLayout;

    groupBox1 = new QGroupBox("Class definition", this);
    name = new QLineEdit;
    parent_class = new QLineEdit;
    layout->addRow("Name : ", name);
    layout->addRow("Parent class : ",parent_class);


    layout1 = new QFormLayout;
    groupBox2 = new QGroupBox("Option", this);
    option1 = new QCheckBox("Use pragma once instead of ifndef");
    option2 = new QCheckBox("Generate a constructor");
    option3 = new QCheckBox("Generate a destructor");


    layout1->addWidget(option1);
    layout1->addWidget(option2);
    layout1->addWidget(option3);

    layout2 = new QFormLayout;

    groupBox3 = new QGroupBox("Add a comment", this);
    groupBox3->setCheckable(true);
    groupBox3->setChecked(false);

    author = new QLineEdit;
    creation_Date = new QDateEdit;
    class_role = new QLineEdit;

    layout2->addRow("Author : ", author);
    layout2->addRow("Creation date : ", creation_Date);
    layout2->addRow("Class role : ", class_role);


    layout_Principal = new QVBoxLayout;

    groupBox1->setLayout(layout);
    groupBox1->move(1,1);
    layout_Principal->addLayout(layout);

    groupBox2->setLayout(layout1);
    groupBox2->move(1,100);
    layout_Principal->addLayout(layout1);

    groupBox3->setLayout(layout2);
    groupBox3->move(1,230);
    layout_Principal->addLayout(layout2);

    m_button1 = new QPushButton("Generate !", this);
    m_button1->move(140, 470);

    m_button2 = new QPushButton("Quit ", this);
    m_button2->move(220, 470);

    m_button1->setCursor(Qt::PointingHandCursor);
    m_button2->setCursor(Qt::PointingHandCursor);

    setWindowTitle("Zero Class Generator");
    resize(400,500);

    QObject::connect(m_button1, SIGNAL(clicked()), this, SLOT(ouvrirDialogue()));
    QObject::connect(m_button2, SIGNAL(clicked()), qApp, SLOT(quit()));

}


void fenetre::ouvrirDialogue()
{
   QString code;

   if (groupBox3->isChecked())
   {
       code += "/*\nAuthor : " + author->text() + "\n";
       code += "Creation date : " + creation_Date->text() + "\n";
       code += "Class role " + class_role->text() + "\n*/";
   }

  if(option1->isChecked())
  {
      code+= "\n\n#pragma once\n";
  }
  else
  {
      code += "\n\n#ifndef HEADER_" + name->text().toUpper() + "\n";
      code += "#define HEADER_" + name->text().toUpper() + "\n";
  }

   code +="\n\n\n";

   code += "class " + name->text() + ": public "+ parent_class->text()+ "\n{\n\n";
   code += "    public:\n";

   if(option2->isChecked())
   {
       code+= "    " + name->text() + "();\n";
   }
   if (option3->isChecked())
   {
       code+="    ~" + name->text() + "();\n";
  }

    code+= "\n\n    protected:\n\n\n\n";
    code+= "    private:\n\n\n";

    code += "};\n\n";

    if (option1->isChecked() == 0)
    {
        code+="\n#endif";
    }


    fenCodeGen *window_Code = new fenCodeGen(code, this);
    window_Code->exec();
}


