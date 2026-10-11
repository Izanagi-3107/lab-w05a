/*
 * Mã sinh viên: 202418984
 * Họ tên: Ngô Ngọc Thái
 */
#ifndef PRINTER_H
#define PRINTER_H

#include "Device.h"

enum class PrinterType {
    Laser,
    Inkjet
};

class Printer : public Device {
private:
    PrinterType printerType;
    int printedPages;
    bool colorPrinter;

public:
    Printer(const std::string& deviceId, const std::string& name,
            int yearOfUse, double purchasePrice, PrinterType printerType,
            int printedPages, bool colorPrinter,
            DeviceStatus status = DeviceStatus::Active);

    virtual bool hasNetworkSupport() const;
    double calculateAnnualMaintenanceCost() const override;
    std::string toString() const override;
};

#endif
