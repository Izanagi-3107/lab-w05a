/*
 * Mã sinh viên: 202418984
 * Họ tên: Ngô Ngọc Thái
 */
#include "Computer.h"
#include "LabRoom.h"
#include "NetworkPrinter.h"
#include "Projector.h"

#include <exception>
#include <iomanip>
#include <iostream>
#include <vector>

void displayMaintenanceList(const LabRoom& room) {
    std::cout << "\nThiet bi can bao tri cua phong " << room.getRoomId() << ":\n";
    std::vector<Device*> devices = room.getDevicesRequiringMaintenance();
    if (devices.empty()) {
        std::cout << "Khong co.\n";
        return;
    }
    for (Device* device : devices)
        std::cout << device->getDeviceId() << " - " << device->getName() << '\n';
}

int main() {
    try {
        std::cout << std::fixed << std::setprecision(0) << std::boolalpha;
        int year = Device::getCurrentYear();

        Computer computer1("C001", "Dell OptiPlex", year - 3, 20000000,
                           16, "Intel Core i5", false);
        Computer computer2("C002", "HP Workstation", year - 6, 30000000,
                           32, "Intel Core i7", true);
        Printer printer1("PR001", "Canon LBP", year - 2, 5000000,
                         PrinterType::Laser, 50000, false);
        NetworkPrinter printer2("PR002", "Epson EcoTank", year - 4, 8000000,
                                PrinterType::Inkjet, 120001, true);
        Projector projector("PJ001", "Epson Projector", year - 2, 15000000,
                            3500, 3501, DeviceStatus::UnderMaintenance);

        LabRoom room1("A101", "Phong lap trinh", 3);
        room1.addDevice(&computer1);
        room1.addDevice(&computer2);
        room1.addDevice(&printer1);

        {
            LabRoom room2("B202", "Phong da phuong tien", 2);
            room2.addDevice(&printer2);
            room2.addDevice(&projector);

            std::cout << "=== THU THEM TRUNG MA ===\n";
            Computer duplicate("C001", "May tinh khac", year, 10000000,
                               8, "Intel Core i3", false);
            try {
                room1.addDevice(&duplicate);
            } catch (const std::exception& e) {
                std::cout << e.what() << '\n';
            }

            std::cout << "\n=== DANH SACH THIET BI ===\n";
            room1.displayDevices();
            room2.displayDevices();

            std::cout << "\nTong bao tri A101: "
                      << room1.calculateAnnualMaintenanceCost() << " VND\n";
            std::cout << "Tong bao tri B202: "
                      << room2.calculateAnnualMaintenanceCost() << " VND\n";

            displayMaintenanceList(room1);
            displayMaintenanceList(room2);

            std::cout << "\n=== KET NOI QUA INetworkable ===\n";
            std::vector<INetworkable*> networkDevices = {
                &computer1, &computer2, &printer2
            };
            for (std::size_t i = 0; i < networkDevices.size(); ++i) {
                networkDevices[i]->connect("192.168.1." + std::to_string(10 + i));
                std::cout << "IP: " << networkDevices[i]->getIpAddress()
                          << " | Da ket noi: " << networkDevices[i]->isConnected()
                          << '\n';
            }

            std::cout << "\nThu ket noi lai khi dang ket noi:\n";
            try {
                networkDevices[0]->connect("192.168.1.99");
            } catch (const std::exception& e) {
                std::cout << e.what() << '\n';
            }

            std::cout << "\nNgat ket noi:\n";
            for (INetworkable* device : networkDevices) {
                device->disconnect();
                std::cout << "Da ket noi: " << device->isConnected()
                          << " | IP: [" << device->getIpAddress() << "]\n";
            }

            std::cout << "\nThu dia chi IP rong:\n";
            try {
                printer2.connect("");
            } catch (const std::exception& e) {
                std::cout << e.what() << '\n';
            }

            std::cout << "\n=== THU NULL VA PHONG DAY ===\n";
            try {
                room1.addDevice(nullptr);
            } catch (const std::exception& e) {
                std::cout << e.what() << '\n';
            }

            Computer extra("C003", "May tinh du phong", year, 10000000,
                           8, "Intel Core i3", false);
            try {
                room1.addDevice(&extra);
            } catch (const std::exception& e) {
                std::cout << e.what() << '\n';
            }

            std::cout << "\n=== TIM VA XOA THIET BI ===\n";
            Device* found = room1.findDevice("C001");
            if (found != nullptr)
                std::cout << "Tim thay: " << found->toString() << '\n';
            std::cout << "Tim ma khong ton tai: "
                      << (room1.findDevice("NONE") == nullptr) << '\n';
            std::cout << "Xoa PR001: " << room1.removeDevice("PR001") << '\n';
            std::cout << "Xoa lai PR001: " << room1.removeDevice("PR001") << '\n';
            std::cout << "May in van ton tai: " << printer1.getName() << '\n';
            room1.addDevice(&printer1);

            std::cout << "\nKet thuc pham vi cua phong B202.\n";
        }

        std::cout << "Sau khi huy phong B202, thiet bi van ton tai:\n";
        std::cout << printer2.toString() << '\n';
        std::cout << projector.toString() << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Loi: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
