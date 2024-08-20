#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include <QString>

class Contact : public QObject
{
    Q_OBJECT

private:
    QString name;
    QString number;
    QString email;
    QString nickname;

public:
    // Constructor with default arguments
    explicit Contact(QObject *parent = nullptr,
                     const QString &nName = "",
                     const QString &nNumber = "",
                     const QString &nEmail = "",
                     const QString &nNickname = "");

    // Getter and Setter methods
    QString getName() const;
    void setName(const QString &eName);

    QString getNumber() const;
    void setNumber(const QString &eNumber);

    QString getEmail() const;
    void setEmail(const QString &eEmail);

    QString getNickname() const;
    void setNickname(const QString &eNickname);

signals:
    // Signals (if any) would be declared here
};

#endif // CONTACT_H
