
#include "CurseFileHash.hpp"

namespace cf {
    CurseFileHash CurseFileHash::from_json(const json &data) {
        CurseFileHash hash;
        hash.value = data["value"];
        hash.algo = static_cast<CurseHashAlgo>(data["algo"]);
        return hash;
    }
} // cf