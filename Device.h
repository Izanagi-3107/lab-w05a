/*
 * Mã sinh viên: 202418984
 * Họ tên: Ngô Ngọc Thái
 */
#ifndef DEVICE_H
#define DEVICE_H

#include <string>

enum class DeviceStatus {
    Active,
    UnderMaintenance,
    Retired
};

class Device {
private:
    const std::string deviceId;
    std::string name;
    int yearOfUse;
    double purchasePrice;
    DeviceStatus status;

public:
    Device(const std::string& deviceId, const std::string& name,
           int yearOfUse, double purchasePrice,
           DeviceStatus status = DeviceStatus::Active);
    virtual ~Device() = default;

    const std::string& getDeviceId() const;
    const std::string& getName() const;
    int getYearOfUse() const;
    int getYearsUsed() const;
    double getPurchasePrice() const;
    DeviceStatus getStatus() const;
    void setStatus(DeviceStatus status);

    static int getCurrentYear();
    virtual double calculateAnnualMaintenanceCost() const = 0;
    virtual std::string toString() const;
};

#endif
