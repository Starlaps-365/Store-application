#include "mainwindow.h"
#include<QtWidgets>
#include"customer.h"
#include "item.h"
#include "addcustomerdialog.h"
#include "additemdialog.h"
#include<QLabel>
#include<QPushButton>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QSpinBox>
#include<QStatusBar>
#include<QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),m_transactionsTreeView{new QTreeView}
{
    setWindowTitle("Store Application");
    resize(800,600);


    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QMenu *editMenu = menuBar()->addMenu(tr("&Add"));
    QMenu *restoreMenu=menuBar()->addMenu("&Restore");
    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    // Create actions for the menus
    QAction *newAction = new QAction(tr("&Add"), this);
    QAction *openAction = new QAction(tr("&Open"), this);
    QAction *saveAction = new QAction(tr("&Save"), this);
    QAction *exitAction = new QAction(tr("&Exit"), this);
    QAction *helpAction =new QAction(tr("Help"),this);

  //  fileMenu->addAction(newAction);

    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
    helpMenu->addAction(helpAction);

    editMenu->addAction(newAction);
    // Create toolbar
    QToolBar *toolbar = addToolBar(tr("Main Toolbar"));
    toolbar->addAction(newAction);
    toolbar->addAction(openAction);
    toolbar->addAction(saveAction);
    // Create status bar
    QStatusBar *statusBar = this->statusBar();
    statusBar->showMessage(tr("Ready"));


    m_transactionsModel = new QStandardItemModel(this);
   m_transactionsModel->setHorizontalHeaderLabels(QStringList() << tr("Transaction ") << tr("Type") << tr("Quality"));
    m_transactionsTreeView->setModel(m_transactionsModel);

    setCentralWidget(m_transactionsTreeView);

  connect(newAction, &QAction::triggered, this, &MainWindow::addItem);
  connect(helpAction, &QAction::triggered, this, &MainWindow::showAbout);
   connect(newAction, &QAction::triggered, this, &MainWindow::recordTransaction);
  connect(newAction, &QAction::triggered, this, &MainWindow::populateTransaction);



}

MainWindow::~MainWindow()
{
}

void MainWindow::recordTransaction()
{
    // Create a dialog to record a transaction
    QDialog dialog(this);
    dialog.setWindowTitle(tr("Shop"));
    // Create input fields and buttons in the dialog
   // QLabel *customerLabel = new QLabel(tr("Customer:"));
    QLabel*lblTop{new QLabel(" \t \t \t Complete the required data")};



    QLabel*custLable=new QLabel("Select the customer");
    custNameBox=new QComboBox;

    QLabel*selectItem=new QLabel("Select the Item");
    selectItemComboBox = new QComboBox;


    QLabel *itemLabel = new QLabel(tr("Item Type"));
    itemComboBox = new QComboBox;


    QLabel *quantityLabel = new QLabel(tr("Quantity:"));
    QSpinBox *quantitySpinBox = new QSpinBox;

    ItemAdd=new QPushButton("AddItem");
    txtEdit=new QPlainTextEdit;

    QPushButton *recordButton = new QPushButton(tr("Done"));



    QStringList cName=QStringList()<<" "<<"Customer1"<<"Customer2"<<"Customer3"<<"Customer 4";
    custNameBox->addItems(cName);


    QStringList type=QStringList()<<" "<<"B"<<"M";
    itemComboBox->addItems(type);


    QStringList cust=QStringList()<<" "<<"Book1"<<"Book2"<<"Book3"<<"Book4"<<"Magazine1"<<"Magazine2"<<"Magazine 3";
    selectItemComboBox->addItems(cust);
   // edtCust->addItems(cust);

    for (const Customer *customer : m_customers) {
        selectItemComboBox->addItem(customer->getName());
       // edtCust->addItem(customer->getName());
    }

    for (const Item *item : m_items) {
        itemComboBox->addItem(item->getName());
    }

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(lblTop);


    layout->addWidget(custLable,1,0);
    layout->addWidget(custNameBox,1,1);

    layout->addWidget(selectItem,2,0);
    layout->addWidget(selectItemComboBox,2,1);


    layout->addWidget(itemLabel,3,0);
    layout->addWidget(itemComboBox,3,1);


    layout->addWidget(quantityLabel,4,0);
    layout->addWidget(quantitySpinBox,4,1);
    layout->addWidget(ItemAdd,4,2);
    layout->addWidget(txtEdit,5,0,2,4);


    layout->addWidget(recordButton,7,1,2,1);
    dialog.setLayout(layout);





   connect(recordButton, &QPushButton::clicked, [&]() {
        QString custName=custNameBox->currentText();
        QString customerName = selectItemComboBox->currentText();
        QString itemType = itemComboBox->currentText();
        int quantity = quantitySpinBox->value();
        Transaction *transaction = new Transaction(custName,QDateTime::currentDateTime(), customerName, itemType, quantity);
        m_transactions.append(transaction);
        dialog.accept();
    });

    dialog.exec();

}

void MainWindow::populateTransaction()
{

    m_transactionsModel->setHorizontalHeaderLabels(QStringList() << tr("Transaction ") << tr("Type") << tr("Quality"));
    m_transactionsModel->clear();
    for (const Transaction *transaction : m_transactions) {

        QList<QStandardItem*>customer;
        customer.append(new QStandardItem(transaction->getCustomer()));
        m_transactionsModel->appendRow(customer);

        QList<QStandardItem*> items;
        items.append(new QStandardItem(transaction->getDateTime().toString()));
        customer.first()->appendRow(items);
        m_transactionsModel->appendRow(customer);

        QList<QStandardItem*>terms;
       terms.append(new QStandardItem(transaction->getCustomerName()));
        terms.append(new QStandardItem(transaction->getItemType()));
        terms.append(new QStandardItem(QString::number(transaction->getQuantity())));

        items.first()->appendRow(terms);
       m_transactionsModel->appendRow(terms);




}


}
QList<QStandardItem*>MainWindow::prepareRow(const QString &first,const QString &second
                                              ,const QString &third ){

QList<QStandardItem*>rowItems;
rowItems<<new QStandardItem(first);
rowItems<<new QStandardItem(second);
rowItems<<new QStandardItem(third);

return rowItems;
}

void MainWindow::addItem()
{
AddItemDialog dialog(this);
if (dialog.exec() == QDialog::Accepted) {
       Item  item = dialog.getItem();
    //   m_items.append(item);
       // Update the item list in the GUI
}

}
void MainWindow::showHelp()
{
QMessageBox::information(this, "Help", "This is the help dialog.");
}

void MainWindow::showAbout()
{
QMessageBox::about(this, "About", "Store Application\nVersion 1.0");
}

void MainWindow::addCustomer()
{

/*AddCustomerDialog dialog(this);
if (dialog.exec() == QDialog::Accepted) {
       Customer customer = dialog.getCustomer();
      // m_customers.append(customer);
}*/

}

void MainWindow::newFile()
{

}

void MainWindow::open()
{

}

void MainWindow::about()
{

}
