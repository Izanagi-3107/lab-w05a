#include "Printer.h"

#include <sstream>
#include <stdexcept>

Printer::Printer(const std::string& deviceId, const std::string& name,
                 int yearOfUse, double purchasePrice, PrinterType printerType,
                 int printedPages, bool colorPrinter, DeviceStatus status)
    : Device(deviceId, name, yearOfUse, purchasePrice, status),
      printerType(printerType), printedPages(printedPages),
      colorPrinter(colorPrinter) {
    if (printerType != PrinterType::Laser && printerType != PrinterType::Inkjet)
        throw std::invalid_argument("Loai may in khong hop le.");
    if (printedPages < 0)
        throw std::invalid_argument("So trang da in khong duoc am.");
}

bool Printer::hasNetworkSupport() const {
    return false;
}

double Printer::calculateAnnualMaintenanceCost() const {
    double cost = getPurchasePrice() * 0.04;
    if (printedPages > 100000)
        cost += 500000;
    if (colorPrinter)
        cost += 300000;
    return cost;
}

std::string Printer::toString() const {
    std::ostringstream out;
    out << "[Printer] " << Device::toString()
        << " | Loai: " << (printerType == PrinterType::Laser ? "Laser" : "Inkjet")
        << " | So trang: " << printedPages
        << " | In mau: " << (colorPrinter ? "Co" : "Khong")
        << " | Ho tro mang: " << (hasNetworkSupport() ? "Co" : "Khong");
    return out.str();
}
