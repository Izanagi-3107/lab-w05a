/*
 * Mã sinh viên: 202418984
 * Họ tên: Ngô Ngọc Thái
 */
#include "Computer.h"

#include <sstream>
#include <stdexcept>

Computer::Computer(const std::string& deviceId, const std::string& name,
                   int yearOfUse, double purchasePrice, int ramGB,
                   const std::string& processor, bool dedicatedGpu,
                   DeviceStatus status)
    : Device(deviceId, name, yearOfUse, purchasePrice, status),
      ramGB(ramGB), processor(processor), dedicatedGpu(dedicatedGpu) {
    if (ramGB <= 0)
        throw std::invalid_argument("Dung luong RAM phai lon hon 0.");
    if (processor.find_first_not_of(" \t\r\n") == std::string::npos)
        throw std::invalid_argument("Loai bo xu ly khong duoc rong.");
}

double Computer::calculateAnnualMaintenanceCost() const {
    double rate = 0.05;
    if (dedicatedGpu)
        rate += 0.02;
    if (getYearsUsed() > 5)
        rate += 0.01;
    return getPurchasePrice() * rate;
}

std::string Computer::toString() const {
    std::ostringstream out;
    out << "[Computer] " << Device::toString()
        << " | RAM: " << ramGB << " GB"
        << " | CPU: " << processor
        << " | GPU roi: " << (dedicatedGpu ? "Co" : "Khong")
        << " | IP: " << (isConnected() ? ipAddress : "Chua ket noi");
    return out.str();
}

const std::string& Computer::getIpAddress() const {
    return ipAddress;
}

void Computer::connect(const std::string& newIpAddress) {
    if (isConnected())
        throw std::logic_error("Thiet bi dang ket noi mang.");
    if (newIpAddress.find_first_not_of(" \t\r\n") == std::string::npos)
        throw std::invalid_argument("Dia chi IP khong duoc rong.");
    ipAddress = newIpAddress;
}

void Computer::disconnect() {
    ipAddress.clear();
}

bool Computer::isConnected() const {
    return !ipAddress.empty();
}
