#include "bc_net.h"

void bc_net_init(void) {
    bc_log("[NET] Networking Initialized");
}

int bc_net_bind_udp(uint16_t port) {
    bc_log("[NET] Binding UDP port %d", port);
    return 0; // Success
}
