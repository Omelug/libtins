/*
 * SAE Dot11Authentication PDU for libtins
 */
#pragma once
#include <tins/dot11/dot11_mgmt.h>
#include <tins/macros.h>
#include <vector>
#include <cstdint>

namespace Tins {
class TINS_API SAEDot11Authentication : public Dot11ManagementFrame {
public:
    static const PDUType pdu_flag = PDU::DOT11_AUTH;
    SAEDot11Authentication(const uint8_t* buffer, uint32_t total_sz);
    uint8_t sae_message_type() const { return sae_message_type_; }
    uint16_t group_id() const { return group_id_; }
    const std::vector<uint8_t>& anti_clogging_token() const { return anti_clogging_token_; }
    const std::vector<uint8_t>& scalar() const { return scalar_; }
    const std::vector<uint8_t>& finite_field_element() const { return finite_field_element_; }
    PDUType pdu_type() const { return pdu_flag; }
    SAEDot11Authentication* clone() const { return new SAEDot11Authentication(*this); }
private:

    uint16_t sae_message_type_;

    struct sae_commit_fixed {
        uint16_t group_id;
        uint8_t scalar[32];
        uint8_t finite_field_element[64];
        //TODO anticlogging token
    };

    std::vector<uint8_t> anti_clogging_token_;

};
} // namespace Tins
