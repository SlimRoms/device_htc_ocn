/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <android-base/logging.h>
#include <android-base/properties.h>

#include "vendor_init.h"
#include "property_service.h"

/* Device specific properties */
#include "htc-aus.h"
#include "htc-sprint.h"
#include "htc-eeuk.h"
#include "htc-emea.h"
#include "htc-emeads.h"
#include "htc-asiads.h"
#include "htc-indiads.h"
#include "htc-chinads.h"
#include "htc-unlocked.h"

using android::base::GetProperty;
using android::init::property_set;

void property_override(char const prop[], char const value[]) {
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void property_override_dual(char const system_prop[], char const vendor_prop[],
    char const value[])
{
    property_override(system_prop, value);
    property_override(vendor_prop, value);
}

static void load_properties(const char *original_data)
{
    char *data;
    char *key, *value, *eol, *sol, *tmp;

    if ((data = (char *) malloc(strlen(original_data)+1)) == NULL) {
        LOG(ERROR) << "Out of memory!" <<std::endl;
        return;
    }

    strcpy(data, original_data);

    sol = data;
    while ((eol = strchr(sol, '\n'))) {
        key = sol;
        *eol++ = 0;
        sol = eol;

        while (isspace(*key)) key++;
        if (*key == '#') continue;

        tmp = eol - 2;
        while ((tmp > key) && isspace(*tmp)) *tmp-- = 0;

        value = strchr(key, '=');
        if (!value) continue;
        *value++ = 0;

        tmp = value - 2;
        while ((tmp > key) && isspace(*tmp)) *tmp-- = 0;

        while (isspace(*value)) value++;

        property_override(key, value);
    }

    free(data);
}

void vendor_load_properties()
{
    std::string platform;
    std::string bootmid;
    std::string bootcid;

    platform = GetProperty("ro.board.platform","");
    if (platform != ANDROID_TARGET)
        return;

    bootmid = GetProperty("ro.boot.mid","");
    bootcid = GetProperty("ro.boot.cid","");

    LOG(INFO) << "Found bootcid " << bootcid << " bootmid " << bootmid << std::endl;

    if (bootmid == "2PZC10000") {
        property_override_dual("ro.product.device", "ro.vendor.product.device", "htc_ocnuhl");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "HTC U11");
        if (bootcid == "EVE__001") {
           // property_override_dual("ro.product.name", "ro.vendor.product.name", "");
            //property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "");
            load_properties(htc_eeuk_properties);
        } else if (bootcid == "HTC__039" || bootcid == "OPTUS001" || bootcid == "VODAP021" ) {
            property_override_dual("ro.product.name", "ro.vendor.product.name", "ocnuhl_00710");
            load_properties(htc_aus_properties);
        } else {
            property_override_dual("ro.product.name", "ro.vendor.product.name", "ocndugl_00401");
            property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "htc/ocndugl_00401/htc_ocndugl:8.0.0/OPR6.170623.013/1002308.19:user/release-keys");
            load_properties(htc_emea_properties);
        }
    } else if (bootmid == "2PZC20000") {
        property_override_dual("ro.product.device", "ro.vendor.product.device", "htc_ocnuhljapan");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "601HT");
        //property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "");
        //load_properties(htc_japan_properties);
        /*
         *   TODO: get their properties
         */
    } else if (bootmid == "2PZC30000") {
        property_override_dual("ro.product.device", "ro.vendor.product.device", "htc_ocndugl");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "HTC_U-3u");
        if (bootcid == "HTC__060") {
            //property_override_dual("ro.product.name", "ro.vendor.product.name", "");
           // property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "");
            load_properties(htc_indiads_properties);
        } else if (bootcid == "HTC__621"){
          //  property_override_dual("ro.product.name", "ro.vendor.product.name", "");
           // property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "");
            load_properties(htc_asiads_properties);
        } else {
           // property_override_dual("ro.product.name", "ro.vendor.product.name", "");
          //  property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "");
            load_properties(htc_emeads_properties);
        }
    } else if (bootmid == "2PZC40000") {
        property_override_dual("ro.product.device", "ro.vendor.product.device", "htc_ocndtwl");
       // property_override_dual("ro.product.name", "ro.vendor.product.name", "");
       // property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "");
        load_properties(htc_chinads_properties);
    } else if (bootmid == "2PZC50000") {
        // TODO: Don't forget T-mobile variant
        property_override_dual("ro.product.device", "ro.vendor.product.device", "htc_ocnwhl");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "HTC U11");
        if (bootcid == "BS_US001") {
            property_override_dual("ro.product.name", "ro.vendor.product.name", "ocnwhl_00617");
            property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "htc/ocnwhl_00617/htc_ocnwhl:8.0.0/OPR6.170623.013/1011554.7:user/release-keys");
            load_properties(htc_unlocked_properties);
        } else {
            property_override_dual("ro.product.name", "ro.vendor.product.name", "ocnwhl_00651");
            property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "htc/ocnwhl_00651/htc_ocnwhl:8.0.0/OPR6.170623.013/1002308.10:user/release-keys");
            load_properties(htc_sprint_properties);
        }
    }
}

