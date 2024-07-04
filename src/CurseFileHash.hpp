
#ifndef CURSEFILEHASH_HPP
#define CURSEFILEHASH_HPP

#include <string>
#include "CurseHashAlgo.hpp"
#include <nlohmann/json.hpp>

namespace cf {

using std::string;
using json = nlohmann::json;

class CurseFileHash {
public:
    string value;
    CurseHashAlgo algo;
    static CurseFileHash from_json(const json &data);
};

} // cf

#endif //CURSEFILEHASH_HPP
