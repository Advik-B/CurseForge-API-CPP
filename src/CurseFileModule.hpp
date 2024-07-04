
#ifndef CURSEFILEMODULE_HPP
#define CURSEFILEMODULE_HPP

#include <string>

namespace cf {
using std::string;
class CurseFileModule {
    string name;
    int64_t fingerprint = 0;
};

} // cf

#endif //CURSEFILEMODULE_HPP
