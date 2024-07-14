# Curseforge API (C++)

[cfapi]: https://wow.curseforge.com/api
[cfapi-docs]: https://wow.curseforge.com/api/docs
[python-cfapi]: https://github.com/Advik-B/CurseForge-API/

This is a no-compromise CurseForge API wrapper for C++. It is a re-write of [Curseforge API][python-cfapi] which is also maintained & actively developed by me.

This project is still in development, and is not yet ready for production use.

## Features

- Simple and easy to use
- Caches responses from the API to disk for faster response times
- Allows direct access to the API via the `fetch` method
- Allows exporting of the objects to DICT, JSON, or YAML
- Can directly parse a manifest file from a curseforge modpack

## Installation

> Todo

## Usage

```c++
#include <iostream>
#include <CurseForgeAPI.hpp>
#include <CurseMod.hpp>

using namespace std;

int main() {
    cf::CurseForgeAPI api("<api-key-here>"); 
    // You can get an API key from https://console.curseforge.com/
    // (You need to be logged in to get an API key)
    const auto mod = cf::CurseMod::from_id(238222, api);
    cout << mod.name << std; // Just Enough Items (JEI)
    cout << mod.authors[0].name << endl; // mezz
    return 0;
}

```

### Error Handling

All errors are defined in the `cf::errors` namespace. Inside [CurseErrors.hpp](include/CurseErrors.hpp)

You can catch them like this:
```c++
#include <CurseErrors.hpp>

try {
    const auto mod = cf::CurseMod::from_id(10, api); // This mod does not exist
    cout << mod.name << endl;
    cout << mod.authors[0].name << endl;
} catch (cf::errors::CurseAPIError &e) {
    cout << "An error occurred: " << e.what() << endl;
}
```

        

## TODO

- [x] Implement the export methods
- [ ] Implement the cache
- [x] Implement the fetch method
- [x] Deal with the download URL being a null value
- [x] Implement the search method
- [x] Wrap the ENTIRE API
- [x] Rename the classes so they have a `Curse` prefix

## FAQ
- **Q:** Why did you make this?
- **A:** I wanted to make a C++ version of the Python API wrapper I made, for performance reasons.
---
- **Q:** Why not use the Python API wrapper?
- **A:** Calling python from C++ is a bit slow innit?
---
- **Q:** Your API key is exposed in the code!
- **A:** 🤫 I know. And its been revoked.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
