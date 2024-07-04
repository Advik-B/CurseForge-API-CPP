#include <iostream>
#include <string>
#include "CurseEngine.hpp"

using namespace std;


int main() {
    cf::CurseForgeAPI api("$2a$10$evexg5YEn66/ch1BwoJItePBJ.zySowOsp74e3vSFsKNNN7tRtH4u");
    auto response = api.fetch("v1/games");
    cout << response.dump(4) << endl;
    return 0;
}
