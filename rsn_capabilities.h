struct SeparatedRSNCapabilities {
    bool pre_authentication;
    bool no_pairwise;
    uint8_t ptksa_replay_counter;
    uint8_t gtksa_replay_counter;
    bool management_frame_protection_required;
    bool management_frame_protection_capable;
    // ...add more fields as needed...
};

class RSNCapabilities {
public:
    // ...existing code...

    SeparatedRSNCapabilities separate_capabilities() const {
        SeparatedRSNCapabilities caps;
        uint16_t val = /* get RSN capabilities value from your class */;
        caps.pre_authentication = val & 0x0001;
        caps.no_pairwise = val & 0x0002;
        caps.ptksa_replay_counter = (val >> 2) & 0x3;
        caps.gtksa_replay_counter = (val >> 4) & 0x3;
        caps.management_frame_protection_required = val & 0x0040;
        caps.management_frame_protection_capable = val & 0x0080;
        // ...add more fields as needed...
        return caps;
    }

    // ...existing code...
};
