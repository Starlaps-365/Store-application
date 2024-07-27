#ifndef ADDITEMDIALOG_H
#define ADDITEMDIALOG_H
#include <QDialog>
#include <QObject>
#include<QLineEdit>
#include<QtWidgets>
class Item;
class QPushButton;
class QLineEdit;
class QComboBox;
class shopInput;

class AddItemDialog : public QDialog
{
    Q_OBJECT
public:
    AddItemDialog(QWidget *parent = nullptr);
    Item getItem() const;

private slots:
    void addCustomer();
    void readList();
    void writeList();

private:

    void setupGUI();
        //QLineEdit *m_nameLineEdit;

    QComboBox*edtType;
    QLineEdit*edtItemName;
    QPushButton*edtAddItem;


};


#endif // ADDITEMDIALOG_H
