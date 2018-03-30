// EMEA | MID: 2PZC10000 | CID: HTC__001, HTC__M27, HTC__002, HTC__034, HTC__J15, HTC__A07
static bool is_variant_emea(std::string bootcid) {
    if (bootcid == "HTC__001") return true;
    if (bootcid == "HTC__M27") return true;
    if (bootcid == "HTC__002") return true;
    if (bootcid == "HTC__034") return true;
    if (bootcid == "HTC__J15") return true;
    if (bootcid == "HTC__A07") return true;
    if (bootcid == "11111111") return true;
    return false;
}

static const char *htc_emea_properties =
    "ro.product.model=HTC U11\n"
    "ro.ril.vmail.23415=1571,BT,121,VDF UK\n"
    "ro.ril.vmail.27203=171\n"
    "ro.ril.vmail.65502=181\n"
    "ro.ril.vmail.27211=171\n"
    "ro.ril.vmail.65510=100\n"
    "ro.ril.vmail.22299=4133,3ITA\n"
    "ro.ril.vmail.23410=901,O2 UK,905,TESCO,443,giffgaff\n"
    "ro.ril.vmail.22201=41901,I TIM\n"
    "ro.ril.vmail.22210=42020,Vodafone IT\n"
    "ro.ril.vmail.22288=4200,I WIND\n"
    "ro.ril.vmail.20801=888\n"
    "ro.ril.vmail.20810=123\n"
    "ro.ril.vmail.20826=777\n"
    "ro.ril.vmail.42403=161\n"
    "ro.ril.vmail.23003=+420608989899\n"
    "ro.ril.enable.dtm=0\n"
    "ro.ril.enable.pre_r8fd=1\n"
    "ro.ril.show.all.plmn=1\n"
    "ro.ril.esm.blacklist=22601,26806,26801,21403,42502,25007,25054,25027\n"
    "ro.ril.hsxpa=4\n"
    "ro.ril.hsdpa.category=24\n"
    "ro.ril.hsupa.category=6\n"
    "ro.ril.disable.cpc=0\n"
    "persist.radio.NETWORK_SWITCH=2\n"
    "ro.product.model=MSM8998 for arm64\n"
    "ro.product.device=htc_ocnuhl\n"
    "ro.build.product=htc_ocnuhl\n"
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
;
