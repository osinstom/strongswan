

#include "s2b_3gpp_provider.h"

#include <utils/debug.h>
#include <daemon.h>

typedef struct private_s2b_3gpp_provider_t private_s2b_3gpp_provider_t;

struct private_s2b_3gpp_provider_t {

    s2b_3gpp_provider_t public;

};

METHOD(listener_t, message, bool,
       private_s2b_3gpp_provider_t *this,
       ike_sa_t *ike_sa, message_t *message, bool incoming, bool plain)
{


    return TRUE;
}


METHOD(s2b_3gpp_provider_t, destroy, void,
       private_s2b_3gpp_provider_t *this)
{
    free(this);
}

s2b_3gpp_provider_t *s2b_3gpp_provider_create()
{
    private_s2b_3gpp_provider_t *this;

    INIT(this,
         .public = {
                 .listener = {
                 .message = _message,
         },
         .destroy = _destroy,
         },
    );

    return &this->public;
}