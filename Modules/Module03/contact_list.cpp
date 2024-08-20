#include "contact_list.h"

contact_list::contact_list(QObject *parent) : QObject(parent)
{

}

contact_list::~contact_list() {
    qDeleteAll(contacts);
    contacts.clear();
}

void contact_list::add_contact(Contact *contact) {
    if(contact) {
        contacts.append(contact);
        emit add_sign(contact);
    }
}

void contact_list::remove_contact(const QString &name) {
    for(int i = 0; i <contacts.size(); i++){
        if(contacts[i]->getName() == name){
            Contact* contact = contacts.takeAt(i);
            emit remove_sign(contact);
            delete contact;
            return;
        }
    }
}

Contact* contact_list::search_contact(const QString &name) const {
    for(Contact *contact : contacts) {
        if(contact->getName() == name) {
            return contact;
        }
    }
    return nullptr;
}

