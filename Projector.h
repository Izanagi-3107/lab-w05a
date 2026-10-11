/*
 * Mã sinh viên: 202418984
 * Họ tên: Ngô Ngọc Thái
 */
#ifndef PROJECTOR_H
#define PROJECTOR_H

#include "Device.h"

class Projector : public Device {
private:
    int brightness;
    int lampHours;

public:
    Projector(const std::string& deviceId, const std::string& name,
              int yearOfUse, double purchasePrice, int brightness,
              int lampHours, DeviceStatus status = DeviceStatus::Active);

    double calculateAnnualMaintenanceCost() const override;
    std::string toString() const override;
};

#endif
