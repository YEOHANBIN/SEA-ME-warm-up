#include "contact_list.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

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

bool contact_list::save_file(const QString &filePath){
    QFile file(filePath);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qWarning() << "Faild to open file for writing:" << filePath;
        return false;
    }

    QTextStream out(&file);
    for(Contact* contact:contacts){
        out << contact->getName() << "\t" << contact->getNumber() << "\t" << contact->getEmail() << "\t" << contact->getNickname() << "\n";
    }

    file.close();
    return true;
}

bool contact_list::load_file(const QString &filePath){
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qWarning() << "Failed to open file for reading:" << filePath;
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()){
        QString line = in.readLine();
        QStringList parts = line.split("\t");
        if(parts.size() == 4){
            Contact* contact = new Contact(this, parts[0], parts[1], parts[2], parts[3]);
            add_contact(contact);
        }
    }

    file.close();
    return true;
}

const QList<Contact*>& contact_list::getContacts() const{
    return contacts;
}
