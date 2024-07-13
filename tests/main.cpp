#include <iostream>
#include <CurseForgeAPI.hpp>
#include <CurseMod.hpp>
#include <CurseErrors.hpp>

using namespace std;

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <api-key>" << endl;
        return 1;
    }
    string apiKey = argv[1];
    cf::CurseForgeAPI api(apiKey);
    try {
        auto searchQuery = cf::CurseSearchBuilder::Minecraft();
        searchQuery.filterText = "Apple Skin";
        const auto mods = cf::CurseMod::search(searchQuery, api);
        for (const auto &mod : mods) {
            cout << mod.name << endl;
        }
    } catch (const cf::errors::CurseAPIError& e) {
        cout << e.what() << endl;
    } catch (const std::exception& e) {
        cout << e.what() << endl;
    }
    // auto response = api.fetch("/v1/categories");
    // cout << response.dump(4) << endl;
    return 0;
}
