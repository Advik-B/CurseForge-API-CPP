
#ifndef CURSEFILEMODULE_HPP
#define CURSEFILEMODULE_HPP

#include <string>
#include <nlohmann/json.hpp>

namespace cf {
using std::string;
using json = nlohmann::json;
class CurseFileModule {
public:
    string name;
    int64_t fingerprint = 0;

    static CurseFileModule from_json(const json &data);

};

} // cf

#endif //CURSEFILEMODULE_HPP
