
#ifndef CURSEFILEHASH_HPP
#define CURSEFILEHASH_HPP

#include <string>
#include "CurseHashAlgo.hpp"

namespace cf {

using std::string;

class CurseFileHash {
    string value;
    CurseHashAlgo algo;
};

} // cf

#endif //CURSEFILEHASH_HPP
