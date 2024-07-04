#include <iostream>
#include <string>
#include <CurseForgeAPI.hpp>
#include <CurseMod.hpp>
#include <CurseErrors.hpp>
// #include "CurseMod.hpp"
using namespace std;


int main() {
    cf::CurseForgeAPI api("$2a$10$evexg5YEn66/ch1BwoJItePBJ.zySowOsp74e3vSFsKNNN7tRtH4u");
    try {
        const auto mod = cf::CurseMod::from_id(1, api);
        cout << mod.name << endl;
    } catch (const cf::errors::CurseAPIError& e) {
        cout << "Mod not found" << endl;
        cout << e.what() << endl;
    }
    // auto response = api.fetch("/v1/categories");
    // cout << response.dump(4) << endl;
    return 0;
}
