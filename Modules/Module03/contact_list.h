#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H

#include <QObject>
#include <QList>
#include "contact.h"

class contact_list : public QObject
{
    Q_OBJECT
private:
    QList<Contact*> contacts;

public:
    explicit contact_list(QObject *parent = nullptr);
    ~contact_list();

    void add_contact(Contact* contact);
    void remove_contact(const QString& name);
    Contact* search_contact(const QString& name) const;

signals:
    void add_sign(Contact* contact);
    void remove_sign(Contact* contact);
};

#endif // CONTACT_LIST_H
