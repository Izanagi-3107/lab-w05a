/*
 * Mã sinh viên: 202418984
 * Họ tên: Ngô Ngọc Thái
 */
#include "Device.h"

#include <cmath>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>

Device::Device(const std::string& deviceId, const std::string& name,
               int yearOfUse, double purchasePrice, DeviceStatus status)
    : deviceId(deviceId), name(name), yearOfUse(yearOfUse),
      purchasePrice(purchasePrice), status(status) {
    if (deviceId.find_first_not_of(" \t\r\n") == std::string::npos)
        throw std::invalid_argument("Ma thiet bi khong duoc rong.");
    if (name.find_first_not_of(" \t\r\n") == std::string::npos)
        throw std::invalid_argument("Ten thiet bi khong duoc rong.");
    if (yearOfUse <= 0 || yearOfUse > getCurrentYear())
        throw std::invalid_argument("Nam dua vao su dung khong hop le.");
    if (!std::isfinite(purchasePrice) || purchasePrice <= 0)
        throw std::invalid_argument("Gia mua phai lon hon 0.");
    setStatus(status);
}

const std::string& Device::getDeviceId() const {
    return deviceId;
}

const std::string& Device::getName() const {
    return name;
}

int Device::getYearOfUse() const {
    return yearOfUse;
}

int Device::getYearsUsed() const {
    return getCurrentYear() - yearOfUse;
}

double Device::getPurchasePrice() const {
    return purchasePrice;
}

DeviceStatus Device::getStatus() const {
    return status;
}

void Device::setStatus(DeviceStatus newStatus) {
    if (newStatus != DeviceStatus::Active &&
        newStatus != DeviceStatus::UnderMaintenance &&
        newStatus != DeviceStatus::Retired)
        throw std::invalid_argument("Trang thai thiet bi khong hop le.");
    status = newStatus;
}

int Device::getCurrentYear() {
    std::time_t now = std::time(nullptr);
    const std::tm* timeInfo = std::localtime(&now);
    if (timeInfo == nullptr)
        throw std::runtime_error("Khong lay duoc nam hien tai.");
    return timeInfo->tm_year + 1900;
}

std::string Device::toString() const {
    std::string statusText;
    switch (status) {
        case DeviceStatus::Active:
            statusText = "Active";
            break;
        case DeviceStatus::UnderMaintenance:
            statusText = "UnderMaintenance";
            break;
        case DeviceStatus::Retired:
            statusText = "Retired";
            break;
    }

    std::ostringstream out;
    out << std::fixed << std::setprecision(0)
        << "Ma: " << deviceId << " | Ten: " << name
        << " | Nam su dung: " << yearOfUse
        << " | Gia mua: " << purchasePrice
        << " | Trang thai: " << statusText;
    return out.str();
}
