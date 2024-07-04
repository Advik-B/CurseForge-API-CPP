#include <iostream>
#include <string>
#include <CurseForgeAPI.hpp>
#include <CurseMod.hpp>
// #include "CurseMod.hpp"
using namespace std;


int main() {
    cf::CurseForgeAPI api("$2a$10$evexg5YEn66/ch1BwoJItePBJ.zySowOsp74e3vSFsKNNN7tRtH4u");
    const auto mod = cf::CurseMod::from_id(1, api);
    // auto response = api.fetch("/v1/categories");
    // cout << response.dump(4) << endl;
    return 0;
}
