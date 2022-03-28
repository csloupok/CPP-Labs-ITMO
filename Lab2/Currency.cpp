#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>



int main() {
    CURL *curl = curl_easy_init();
    if (curl) {
        std::cout << "kek";
    }
}