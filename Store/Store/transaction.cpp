#include "transaction.h"

Transaction::Transaction( QString cust,const QDateTime &dateTime, const QString &customerName, const QString &itemType, int quantity)
    : customer(cust),m_dateTime(dateTime), m_customerName(customerName), m_itemType(itemType), m_quantity(quantity)
{
}
QDateTime Transaction::getDateTime() const
{
    return m_dateTime;
}
QString Transaction::getCustomerName() const
{
    return m_customerName;
}
QString Transaction::getItemType() const
{
    return m_itemType;
}

int Transaction::getQuantity() const
{
    return m_quantity;
}

QString Transaction::getCustomer() const
{
    return customer;
}

void Transaction::setCustomer(const QString &newCustomer)
{
    customer = newCustomer;
}
