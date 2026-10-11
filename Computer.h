#ifndef COMPUTER_H
#define COMPUTER_H

#include "Device.h"
#include "INetworkable.h"

class Computer : public Device, public INetworkable {
private:
    int ramGB;
    std::string processor;
    bool dedicatedGpu;
    std::string ipAddress;

public:
    Computer(const std::string& deviceId, const std::string& name,
             int yearOfUse, double purchasePrice, int ramGB,
             const std::string& processor, bool dedicatedGpu,
             DeviceStatus status = DeviceStatus::Active);

    double calculateAnnualMaintenanceCost() const override;
    std::string toString() const override;
    const std::string& getIpAddress() const override;
    void connect(const std::string& ipAddress) override;
    void disconnect() override;
    bool isConnected() const override;
};

#endif
