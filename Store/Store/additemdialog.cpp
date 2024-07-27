#include "additemdialog.h"
#include"item.h"
#include <QLineEdit>
#include <QLabel>
#include<QGridLayout>
#include<QCloseEvent>
#include<QPushButton>
#include<QMessageBox>
#include<QComboBox>

AddItemDialog::AddItemDialog(QWidget *parent)
    : QDialog(parent),edtType{new QComboBox},edtItemName{new QLineEdit}
    ,edtAddItem{new QPushButton("Add item")}
{
    setWindowTitle("Add Item");
    setupGUI();
    connect(edtAddItem, &QPushButton::clicked, this, &AddItemDialog::accept);
    // connect(edtDone, &QPushButton::clicked, this, &AddItemDialog::reject);

}

Item AddItemDialog::getItem() const
{
    return Item(edtItemName->text());
}

void AddItemDialog::addCustomer()
{


}

void AddItemDialog::readList()
{

}

void AddItemDialog::writeList()
{

}

void AddItemDialog::setupGUI()
{
    // Setup layout

    QGridLayout*layout(new QGridLayout(this));

    QLabel*lblTop{new QLabel("Complete  the required data")};

    lblTop->setAlignment(Qt::AlignCenter);
    QLabel*lblType{new QLabel("Item Type")};
    QLabel*lblItem{new QLabel("Name of Item")};




    layout->addWidget(lblTop);


    layout->addWidget(lblType,1,0);
    layout->addWidget(edtType,1,1);

    layout->addWidget(lblItem,2,0);
    layout->addWidget(edtItemName,2,1);

    layout->addWidget(edtAddItem,3,1);

    this->setLayout(layout);

    // initialize widgets

    QStringList type =QStringList()<<" "<<"B"<<"M";
    edtType->addItems(type);

}



