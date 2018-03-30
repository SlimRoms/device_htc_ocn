/* Gen_Unlock_1.11.617.1: BS_US001 */
static bool is_variant_unlocked(std::string bootcid) {
    if (bootcid == "BS_US001") return true;
    return false;
}

static const char *htc_unlocked_properties =
    "ro.build.product=htc_ocnwhl\n"
    "ro.product.device=htc_ocnwhl\n"
    "ro.product.model=HTC u11\n"
    "ro.product.model=MSM8998 for arm64\n"
    "persist.radio.NETWORK_SWITCH=2\n"
    "persist.rild.nitz_plmn=\n"
    "persist.rild.nitz_long_ons_0=\n"
    "persist.rild.nitz_long_ons_1=\n"
    "persist.rild.nitz_long_ons_2=\n"
    "persist.rild.nitz_long_ons_3=\n"
    "persist.rild.nitz_short_ons_0=\n"
    "persist.rild.nitz_short_ons_1=\n"
    "persist.rild.nitz_short_ons_2=\n"
    "persist.rild.nitz_short_ons_3=\n"
    "ril.subscription.types=NV,RUIM\n"
    "telephony.lteOnCdmaDevice=0\n"
    "persist.radio.fill_eons=1\n"
    "persist.igps.sensor=on\n"
    "persist.radio.apm_sim_not_pwdn=0\n"
    "persist.radio.apm_mdm_not_pwdn=1\n"
    "persist.radio.cs_srv_type=1\n"
    "persist.radio.snapshot_timer=0\n"
    "persist.radio.data_ltd_sys_ind=1\n"
    "persist.radio.VT_ENABLE=1\n"
    "persist.radio.VT_HYBRID_ENABLE=1\n"
    "persist.radio.ROTATION_ENABLE=1\n"
    "persist.radio.RATE_ADAPT_ENABLE=1\n"
    "persist.radio.videopause.mode=1\n"
    "ro.telephony.default_network=9\n"
;
