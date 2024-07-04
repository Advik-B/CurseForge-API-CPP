
#ifndef CURSEERRORS_HPP
#define CURSEERRORS_HPP

#include <exception>

namespace cf {
    class CurseError : public std::exception {
    public:
        explicit CurseError(const char *message) : message(message) {}

        const char *what() const noexcept override {
            return message;
        }

    private:
        const char *message;
    };

    class CurseAPIError : public CurseError {
    public:
        explicit CurseAPIError(const char *message) : CurseError(message) {}
    };
    };
} // cf

#endif //CURSEERRORS_HPP
