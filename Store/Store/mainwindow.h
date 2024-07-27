#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QList>
#include<QTreeView>
#include<QtWidgets>
#include<QStandardItemModel>
#include"transaction.h"

class Customer;
class Item;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void recordTransaction();
    void populateTransaction();
    void addItem();
    void addCustomer();

    void newFile();
    void open();
    void about();

    void showHelp();
    void showAbout();

private:
    QTreeView *m_transactionsTreeView;

    QList<QStandardItem*>prepareRow(const QString &first,const QString&second,const QString&third);
    QStandardItemModel *m_transactionsModel;
    QList<Transaction*> m_transactions;
    QList<Customer*> m_customers;
    QList<Item*> m_items;

    QComboBox *custNameBox;
    QComboBox *selectItemComboBox;
    QLabel *itemLabel;
    QComboBox *itemComboBox;
    QSpinBox *quantitySpinBox;

    QPushButton*ItemAdd;
    QPlainTextEdit*txtEdit;


};
#endif // MAINWINDOW_H
