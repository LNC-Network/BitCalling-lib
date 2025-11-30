#ifndef BC_NET_H
#define BC_NET_H

#include "bc_core.h"

// UDP Networking and NAT Traversal

void bc_net_init(void);
int bc_net_bind_udp(uint16_t port);

#endif // BC_NET_H
