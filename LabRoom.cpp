/*
 * Mã sinh viên: 202418984
 * Họ tên: Ngô Ngọc Thái
 */
#include "LabRoom.h"

#include <iostream>
#include <stdexcept>

LabRoom::LabRoom(const std::string& roomId, const std::string& name, int capacity)
    : roomId(roomId), name(name), capacity(capacity) {
    if (roomId.find_first_not_of(" \t\r\n") == std::string::npos)
        throw std::invalid_argument("Ma phong khong duoc rong.");
    if (name.find_first_not_of(" \t\r\n") == std::string::npos)
        throw std::invalid_argument("Ten phong khong duoc rong.");
    if (capacity <= 0)
        throw std::invalid_argument("Suc chua phai lon hon 0.");
}

const std::string& LabRoom::getRoomId() const {
    return roomId;
}

const std::string& LabRoom::getName() const {
    return name;
}

int LabRoom::getCapacity() const {
    return capacity;
}

const std::vector<Device*>& LabRoom::getDevices() const {
    return devices;
}

void LabRoom::addDevice(Device* device) {
    if (device == nullptr)
        throw std::invalid_argument("Khong the them thiet bi null.");
    if (findDevice(device->getDeviceId()) != nullptr)
        throw std::invalid_argument("Ma thiet bi da ton tai trong phong.");
    if (devices.size() >= static_cast<std::size_t>(capacity))
        throw std::logic_error("Phong da du suc chua.");
    devices.push_back(device);
}

bool LabRoom::removeDevice(const std::string& deviceId) {
    for (auto it = devices.begin(); it != devices.end(); ++it) {
        if ((*it)->getDeviceId() == deviceId) {
            devices.erase(it);
            return true;
        }
    }
    return false;
}

Device* LabRoom::findDevice(const std::string& deviceId) const {
    for (Device* device : devices) {
        if (device->getDeviceId() == deviceId)
            return device;
    }
    return nullptr;
}

double LabRoom::calculateAnnualMaintenanceCost() const {
    double total = 0;
    for (Device* device : devices)
        total += device->calculateAnnualMaintenanceCost();
    return total;
}

std::vector<Device*> LabRoom::getDevicesRequiringMaintenance() const {
    std::vector<Device*> result;
    for (Device* device : devices) {
        if (device->getStatus() == DeviceStatus::UnderMaintenance ||
            device->getYearsUsed() > 5)
            result.push_back(device);
    }
    return result;
}

void LabRoom::displayDevices() const {
    std::cout << "\nPhong " << roomId << " - " << name
              << " (" << devices.size() << "/" << capacity << ")\n";
    if (devices.empty()) {
        std::cout << "Phong chua co thiet bi.\n";
        return;
    }
    for (Device* device : devices) {
        std::cout << device->toString() << '\n';
        std::cout << "Chi phi bao tri: "
                  << device->calculateAnnualMaintenanceCost() << " VND\n";
    }
}
