#include "motorhelper.h"
#include <QDebug>

MotorHelper::MotorHelper(QObject *parent) : QObject(parent)
{
    int err;
    auto motorSvc = IMotor::getService();
    if(motorSvc == nullptr) {
        qDebug() << "Can't open Motor HW Module, error:" << err;
        return;
    }

    err = motorSvc->init();
    m_hasMotor = true;
    emit hasMotorChanged();
}

MotorHelper::~MotorHelper()
{

}

bool MotorHelper::popUpMotor()
{
    if(!m_hasMotor)
    {
        qDebug() << "Device has no motor";
        return false;
    } else {
        auto status = motorSvc->getMotorStatus();
        if(status == 1 || status == 13) {
            motorSvc->popupMotor(1);
        }
    }

    return true;
}

bool MotorHelper::takeBackMotor()
{
    if(!m_hasMotor)
    {
        qDebug() << "Device has no motor";
        return false;
    } else {
        motorSvc->takebackMotor(1);
    }

    return true;
}

bool MotorHelper::hasMotor()
{
    return m_hasMotor;
}
