#include <tins/dot11/sae_dot11_auth.h>
#include <tins/memory_helpers.h>
#include <cstring>

using Tins::Memory::InputMemoryStream;
namespace Tins {
SAEDot11Authentication::SAEDot11Authentication(const uint8_t* buffer, uint32_t total_sz)
    : Dot11ManagementFrame(buffer, total_sz),
      sae_message_type_(0), (0) {
    InputMemoryStream stream(buffer, total_sz);
    read(buffer, sae_message_type_);





} // namespace Tins
