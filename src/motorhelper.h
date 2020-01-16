#ifndef MOTORHELPER_H
#define MOTORHELPER_H

#include <QObject>
#include <vendor/xiaomi/hardware/motor/1.0/IMotor.h>

class MotorHelper : public QObject
{
    Q_OBJECT
public:
    explicit MotorHelper(QObject *parent = 0);
    ~MotorHelper();

    Q_PROPERTY(bool hasMotor READ hasMotor NOTIFY hasMotorChanged)
    Q_INVOKABLE bool popUpMotor();
    Q_INVOKABLE bool takeBackMotor();

    bool hasMotor();

signals:
    void hasMotorChanged();

private:
    bool m_hasMotor = false;
};

#endif // MOTORHELPER_H
