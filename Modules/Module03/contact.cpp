#include "contact.h"

Contact::Contact(QObject *parent, const QString &nName, const QString &nNumber, const QString &nEmail, const QString &nNickname)
    : QObject(parent), name(nName), number(nNumber), email(nEmail), nickname(nNickname) {
}

QString Contact::getName() const {
    return name;
}

void Contact::setName(const QString &eName) {
    name = eName;
}

QString Contact::getNumber() const {
    return number;
}

void Contact::setNumber(const QString &eNumber) {
    number = eNumber;
}

QString Contact::getEmail() const {
    return email;
}

void Contact::setEmail(const QString &eEmail) {
    email = eEmail;
}

QString Contact::getNickname() const {
    return nickname;
}

void Contact::setNickname(const QString &eNickname) {
    nickname = eNickname;
}
