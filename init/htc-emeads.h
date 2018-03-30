// EMEA | MID: 2PZC30000 | CID: HTC__001, HTC__M27, HTC__002, HTC__034, HTC__J15, HTC__A07
static bool is_variant_emeads(std::string bootcid) {
    if (bootcid == "HTC__001") return true;
    if (bootcid == "HTC__M27") return true;
    if (bootcid == "HTC__J15") return true;
    if (bootcid == "HTC__A07") return true;
    if (bootcid == "HTC__034") return true;
    if (bootcid == "HTC__002") return true;
    if (bootcid == "11111111") return true;
    return false;
}

static const char *htc_emeads_properties =
    "ro.product.model=HTC U11\n"
    "ro.ril.vmail.50502=+61411000321,YES OPTUS,+61411000212,Virgin Mobile\n"
    "ro.ril.vmail.50503=+61411000121\n"
    "ro.ril.vmail.50501=+61101\n"
    "ro.ril.vmail.50506=+61430005333\n"
    "ro.ril.vmail.53001=+6421700700,vodafone NZ,+64298500500,TelstraClear\n"
    "ro.ril.vmail.53005=+6483083210\n"
    "ro.ril.vmail.53024=+64222022002\n"
    "ro.ril.vmail.51000=*88\n"
    "ro.ril.vmail.51011=888\n"
    "ro.ril.vmail.51089=222\n"
    "ro.ril.vmail.51099=*922\n"
    "ro.ril.vmail.51021=+62816122\n"
    "ro.ril.vmail.51001=+62816122\n"
    "ro.ril.vmail.51003=122\n"
    "ro.ril.vmail.51007=*88\n"
    "ro.ril.vmail.51010=222\n"
    "ro.ril.vmail.51028=*88\n"
    "ro.ril.vmail.51051=*88\n"
    "ro.ril.vmail.51009=*88\n"
    "ro.ril.enable.pre_r8fd=1\n"
    "ro.ril.hsxpa=4\n"
    "ro.ril.hsdpa.category=24\n"
    "ro.ril.hsupa.category=6\n"
    "ro.ril.disable.cpc=1\n"
    "ro.product.model=MSM8998 for arm64\n"
    "ro.product.device=htc_ocndugl\n"
    "ro.build.product=htc_ocndugl\n"
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
    "telephony.lteOnCdmaDevice=1\n"
    "persist.radio.VT_CAM_INTERFACE=2\n"
    "telephony.lteOnCdmaDevice=0\n"
    "persist.radio.fill_eons=1\n"
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
    "persist.radio.sap_silent_pin=1\n"
    "persist.radio.multisim.config=dsds\n"
;
