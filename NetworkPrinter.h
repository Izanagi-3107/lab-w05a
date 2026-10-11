/*
 * Mã sinh viên: 202418984
 * Họ tên: Ngô Ngọc Thái
 */
#ifndef NETWORK_PRINTER_H
#define NETWORK_PRINTER_H

#include "Printer.h"
#include "INetworkable.h"

class NetworkPrinter : public Printer, public INetworkable {
private:
    std::string ipAddress;

public:
    NetworkPrinter(const std::string& deviceId, const std::string& name,
                   int yearOfUse, double purchasePrice, PrinterType printerType,
                   int printedPages, bool colorPrinter,
                   DeviceStatus status = DeviceStatus::Active);

    bool hasNetworkSupport() const override;
    std::string toString() const override;
    const std::string& getIpAddress() const override;
    void connect(const std::string& ipAddress) override;
    void disconnect() override;
    bool isConnected() const override;
};

#endif
