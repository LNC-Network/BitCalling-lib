#include "bc_core.h"
#include "bc_net.h"
#include "bc_mesh.h"
#include "bc_rtp.h"
#include "bc_audio.h"
#include "bc_crypto.h"
#include "bc_sim.h"

int main(void) {
    bc_core_init();
    bc_net_init();
    bc_mesh_init();
    bc_rtp_init();
    bc_audio_init();
    bc_crypto_init();
    bc_sim_init();

    bc_log("BitCalling Engine Ready.");
    
    // For now, just run a dummy simulation
    bc_sim_run();

    return 0;
}
