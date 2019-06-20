
#include "s2b_3gpp_plugin.h"
#include "s2b_3gpp_provider.h"

#include <daemon.h>

typedef struct private_s2b_3gpp_plugin_t private_s2b_3gpp_plugin_t;

struct private_s2b_3gpp_plugin_t {

    /**
     * Public s2b_3gpp_plugin_t interface.
     */
    s2b_3gpp_plugin_t public;


    s2b_3gpp_provider_t *provider;

};

METHOD(plugin_t, get_name, char*,
       private_s2b_3gpp_plugin_t *this)
{
    return "s2b-3gpp";
}

/**
 * Register listener
 */
static bool plugin_cb(private_s2b_3gpp_plugin_t *this,
                      plugin_feature_t *feature, bool reg, void *cb_data)
{
    if (reg)
    {
        this->provider = s2b_3gpp_provider_create();
        if (this->provider)
        {
            charon->bus->add_listener(charon->bus, &this->provider->listener);
        }
    }
    else
    {
        if (this->provider)
        {
            charon->bus->remove_listener(charon->bus, &this->provider->listener);
            this->provider->destroy(this->provider);
        }
    }
    return TRUE;
}

METHOD(plugin_t, get_features, int,
       private_s2b_3gpp_plugin_t *this, plugin_feature_t *features[])
{
    static plugin_feature_t f[] = {
            PLUGIN_CALLBACK((plugin_feature_callback_t)plugin_cb, NULL),
                PLUGIN_PROVIDE(CUSTOM, "s2b-3gpp"),
    };
    *features = f;
    return countof(f);
}

METHOD(plugin_t, destroy, void, private_s2b_3gpp_plugin_t *this)
{
    this->provider->destroy(this->provider);
    free(this);
}

/*
 * see header file
 */
plugin_t *private_s2b_3gpp_plugin_create()
{
    private_s2b_3gpp_plugin_t *this;

    INIT(this,
         .public = {
                 .plugin = {
                         .get_name = _get_name,
                         .get_features = _get_features,
                         .destroy = _destroy,
                 },
         },
    );

    return &this->public.plugin;
}

