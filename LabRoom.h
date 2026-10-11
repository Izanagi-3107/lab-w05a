#ifndef LAB_ROOM_H
#define LAB_ROOM_H

#include "Device.h"

#include <vector>

class LabRoom {
private:
    std::string roomId;
    std::string name;
    int capacity;
    std::vector<Device*> devices;

public:
    LabRoom(const std::string& roomId, const std::string& name, int capacity);

    const std::string& getRoomId() const;
    const std::string& getName() const;
    int getCapacity() const;
    const std::vector<Device*>& getDevices() const;

    void addDevice(Device* device);
    bool removeDevice(const std::string& deviceId);
    Device* findDevice(const std::string& deviceId) const;
    double calculateAnnualMaintenanceCost() const;
    std::vector<Device*> getDevicesRequiringMaintenance() const;
    void displayDevices() const;
};

#endif
