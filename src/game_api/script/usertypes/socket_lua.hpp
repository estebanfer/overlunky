#pragma once

#include "sockpp/udp_socket.h"
#include "sol/sol.hpp"
#include <sol/forward.hpp>
#include <string>
#include <vector>

class UdpServer
{
  public:
    UdpServer(std::string host, in_port_t port, sol::function cb);
    std::string host;
    in_port_t port;
    sol::function cb;
    sockpp::udp_socket sock;
};

namespace NSocket
{
void register_usertypes(sol::state& lua);
};