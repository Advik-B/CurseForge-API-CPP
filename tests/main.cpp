#include <iostream>
#include <CurseForgeAPI.hpp>
#include <CurseMod.hpp>
#include <CurseErrors.hpp>
// #include "CurseMod.hpp"
using namespace std;


int main() {
    cf::CurseForgeAPI api("$2a$10$evexg5YEn66/ch1BwoJItePBJ.zySowOsp74x3vSFsKNNN7tRtH4u");
    try {
        const auto mod = cf::CurseMod::from_id(238222, api);
        cout << mod.name << endl;
        cout << mod.authors[0].name << endl;
    } catch (const cf::errors::CurseAPIError& e) {
        cout << e.what() << endl;
    }
    // auto response = api.fetch("/v1/categories");
    // cout << response.dump(4) << endl;
    return 0;
}
