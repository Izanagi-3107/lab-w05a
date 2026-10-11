#include "NetworkPrinter.h"

#include <stdexcept>

NetworkPrinter::NetworkPrinter(const std::string& deviceId, const std::string& name,
                               int yearOfUse, double purchasePrice,
                               PrinterType printerType, int printedPages,
                               bool colorPrinter, DeviceStatus status)
    : Printer(deviceId, name, yearOfUse, purchasePrice, printerType,
              printedPages, colorPrinter, status) {
}

bool NetworkPrinter::hasNetworkSupport() const {
    return true;
}

std::string NetworkPrinter::toString() const {
    return Printer::toString() + " | IP: " +
           (isConnected() ? ipAddress : "Chua ket noi");
}

const std::string& NetworkPrinter::getIpAddress() const {
    return ipAddress;
}

void NetworkPrinter::connect(const std::string& newIpAddress) {
    if (isConnected())
        throw std::logic_error("Thiet bi dang ket noi mang.");
    if (newIpAddress.find_first_not_of(" \t\r\n") == std::string::npos)
        throw std::invalid_argument("Dia chi IP khong duoc rong.");
    ipAddress = newIpAddress;
}

void NetworkPrinter::disconnect() {
    ipAddress.clear();
}

bool NetworkPrinter::isConnected() const {
    return !ipAddress.empty();
}
