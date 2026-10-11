#ifndef INETWORKABLE_H
#define INETWORKABLE_H

#include <string>

class INetworkable {
public:
    virtual ~INetworkable() = default;
    virtual const std::string& getIpAddress() const = 0;
    virtual void connect(const std::string& ipAddress) = 0;
    virtual void disconnect() = 0;
    virtual bool isConnected() const = 0;
};

#endif
