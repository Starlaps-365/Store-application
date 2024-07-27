#ifndef ITEM_H
#define ITEM_H
#include<QString>

class Item
{
public:
    Item(const QString &name);
    QString getName() const;
private:
    QString m_name;
};


#endif // ITEM_H
