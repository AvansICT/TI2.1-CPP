#include <iostream>
#include <string>

long double operator"" _km(long double x) {
    return x * 1000.0; // km naar meter
}

long double operator"" _m(long double x) {
    return x; // al in meters
}

long double operator"" _cm(long double x) {
    return x / 100.0; // cm naar meter
}

std::string operator"" _tag(const char* str, std::size_t) {
    return std::string("<") + str + ">";
}

// String literal operator die een HTML-tag genereert
std::string operator"" _html(const char* str, std::size_t) {
    return std::string("<") + str + ">\n</" + str + ">";
}

int main() {
    std::cout << "Literals!\n";
    std::cout << __DATE__ << " " << __TIME__ << std::endl; // log date and time of compilation, not runtime
 
    auto afstand = 3.5_km + 20.0_m + 15.0_cm;
    std::cout << "Afstand in meters: " << afstand << " m\n";

    std::string s = "title"_tag;
    std::cout << s << std::endl;

    std::string head = "head"_html;
    std::string title = "title"_html;

    std::cout << "<html>\n";
    std::cout << head << "\n";
    std::cout << title << "\n";
    std::cout << "</html>\n";
}


