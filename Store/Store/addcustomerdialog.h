#ifndef ADDCUSTOMERDIALOG_H
#define ADDCUSTOMERDIALOG_H
#include <QDialog>
#include <QObject>
#include<QLineEdit>
#include<QtWidgets>
#include "Customer.h"
//#include"customerlist.h"
class QPushButton;
class QLineEdit;
class QTextEdit;
class QComboBox;
class QDoubleSpinBox;
class QSpinBox;
class CustomerList;

class  Customer;
class AddCustomerDialog : public QDialog
{
    Q_OBJECT
public:
    AddCustomerDialog(QWidget *parent = nullptr);

    Customer getCustomer() const;

private slots:

    void addCustomer();
private:

    void setupGUI();

    QComboBox *edtCust;
    QComboBox *edtItem;
    QSpinBox*edtQuantity;

    QPushButton*edtAddItem;
    QTextEdit*txtEdt;
    QPushButton*edtDone;

   // CustomerList list;
    Customer*customer;

};
#endif // ADDCUSTOMERDIALOG_H
