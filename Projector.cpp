#include "Projector.h"

#include <sstream>
#include <stdexcept>

Projector::Projector(const std::string& deviceId, const std::string& name,
                     int yearOfUse, double purchasePrice, int brightness,
                     int lampHours, DeviceStatus status)
    : Device(deviceId, name, yearOfUse, purchasePrice, status),
      brightness(brightness), lampHours(lampHours) {
    if (brightness <= 0)
        throw std::invalid_argument("Do sang phai lon hon 0.");
    if (lampHours < 0)
        throw std::invalid_argument("So gio su dung bong den khong duoc am.");
}

double Projector::calculateAnnualMaintenanceCost() const {
    double cost = getPurchasePrice() * 0.03;
    if (lampHours > 3000)
        cost += 1500000;
    return cost;
}

std::string Projector::toString() const {
    std::ostringstream out;
    out << "[Projector] " << Device::toString()
        << " | Do sang: " << brightness << " lumen"
        << " | Gio bong den: " << lampHours;
    return out.str();
}
