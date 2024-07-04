#include "CurseErrors.hpp"

namespace cf::errors {
    inline const char* CurseAPIError::what() const noexcept {
        return message.c_str();
    }

    CurseAPIError::CurseAPIError(string message) : message(move(message)) {}
    NotFoundError::NotFoundError(string for_path) : CurseAPIError("[404] NotFoundError: " + for_path) {}
    InvalidAPIKeyError::InvalidAPIKeyError(string key) : CurseAPIError("[403] Invalid APIKey: " + key) {}
}