#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<QDateEdit>
#include<QString>
#include "customer.h"
#include "item.h"


class Transaction
{
public:
    Transaction(QString cust,const QDateTime &dateTime, const QString &customerName, const QString &itemType, int quantity);
    QDateTime getDateTime() const;
    QString getCustomerName() const;
    QString getItemType() const;
    int getQuantity() const;
    QString getCustomer() const;

    void setCustomer(const QString &newCustomer);

private:
    QDateTime m_dateTime;
    QString m_customerName;
    QString m_itemType;
    int m_quantity;
    QString customer;
};




#endif // TRANSACTION_H
