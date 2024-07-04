
#include "CurseFileModule.hpp"

namespace cf {
CurseFileModule CurseFileModule::from_json(const json &data) {
    CurseFileModule module;
    module.name = data["name"];
    module.fingerprint = data["fingerprint"];
    return module;
}
}