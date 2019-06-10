
#ifndef S2B_3GPP_PROVIDER_H
#define S2B_3GPP_PROVIDER_H

#include <bus/listeners/listener.h>

typedef struct s2b_3gpp_provider_t s2b_3gpp_provider_t;

struct s2b_3gpp_provider_t {

    /**
     * Implements a listener.
     */
     listener_t listener;

     void (*destroy)(s2b_3gpp_provider_t *this);

};

/**
 * Create a S2b 3GPP provider instance.
 */
s2b_3gpp_provider_t *s2b_3gpp_provider_create();

#endif //S2B_3GPP_PROVIDER_H
