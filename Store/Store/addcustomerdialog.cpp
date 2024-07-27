#include "addcustomerdialog.h"
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>

AddCustomerDialog::AddCustomerDialog(QWidget *parent):QDialog(parent)
    ,edtCust(new QComboBox),
    edtItem(new QComboBox),edtQuantity(new QSpinBox),
    edtAddItem(new QPushButton("Add Item"))
    ,txtEdt(new QTextEdit),edtDone(new QPushButton("Done"))
{
    setWindowTitle("Add Customer");

    setupGUI();
    connect(edtAddItem, &QPushButton::clicked, this, &AddCustomerDialog::accept);
    connect(edtAddItem, &QPushButton::clicked, this, &AddCustomerDialog::addCustomer);

    connect(edtDone, &QPushButton::clicked, this, &AddCustomerDialog::reject);
}
Customer AddCustomerDialog::getCustomer() const
{
    return  Customer(edtAddItem->text());
}

void AddCustomerDialog::addCustomer()
{
    txtEdt->show();

}

void AddCustomerDialog::setupGUI(){

    // Declare widgets
    QGridLayout *layout(new QGridLayout(this));

    QLabel*lblTop{new QLabel("Complete  the required data")};
    QLabel *lblCustomer(new QLabel("Select the Customer"));
    QLabel *lblItem(new QLabel("Select the item"));
    QLabel *lblType(new QLabel("Item Type"));
    QLabel *lblQuantity(new QLabel("item quantity"));




    // Setup layout
    layout->addWidget(lblTop);
    layout->addWidget(lblCustomer,1,0);
    layout->addWidget(edtCust,1,1);

    layout->addWidget(lblItem,2,0);
    layout->addWidget(edtItem,2,1);

    layout->addWidget(lblType,3,0);


    layout->addWidget(lblQuantity,4,0);
    layout->addWidget(edtQuantity,4,1);
    layout->addWidget(edtAddItem,4,2);

    layout->addWidget(txtEdt,5,0,2,4);
    layout->addWidget(edtDone,7,1,2,1);



    // Initialize widgets
    QStringList listOne = QStringList() <<" " <<"Customer1" << "Customer2" << "Customer3" << "Customer4" ;
    edtCust->addItems(listOne);

    QStringList listTwo = QStringList() <<" " << "Book1" << "Book2"<<"Book3"<< "Magazine1" << "Magazine2"<<"Magazine3" ;
    edtItem->addItems(listTwo);


    edtQuantity->setMaximum(9999);
    edtQuantity->setMinimum(0);

    edtQuantity->setAlignment(Qt::AlignRight);



}



