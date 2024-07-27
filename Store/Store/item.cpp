#include "item.h"

Item::Item(const QString &name)
    : m_name(name)
{
}
QString Item::getName() const
{
    return m_name;
}
