#include <iostream>
#include <vector>
#include <unistd.h>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
std::vector<std::string> valutesNames;
std::vector<std::vector<double>> valutes(34);

void finish(int temp) {
    std::cout << "---Средние значения валют за время работы программы:---\n\n";
    for (int i = 0; i < valutes.size(); i++) {
        double sum = 0;
        for (int j = 0; j < valutes[i].size(); j++)
            sum += valutes[i][j];
        std::cout << valutesNames[i] << ": " << sum / valutes[i].size() << " руб.\n";
    }
    std::cout << "\n---Медианные значения валют за время работы программы:---\n\n";
    for (int i = 0; i < valutes.size(); i++) {
        std::sort(valutes[i].begin(), valutes[i].end());
        if (valutes[i].size() % 2 != 0)
            std::cout << valutesNames[i] << ": " << valutes[i][(int) (valutes[i].size() / 2) - 1] << " руб.\n";
        else
            std::cout << valutesNames[i] << ": "
                      << (valutes[i][(int) (valutes[i].size() / 2)] + valutes[i][(int) (valutes[i].size() / 2) - 1]) / 2
                      << " руб.\n";
    }

    std::exit(0);
}

void fillNames(std::string file) {
    auto JsonData = json::parse(file);
    for (auto&[key, value]: JsonData["Valute"].items()) {
        valutesNames.push_back(value["Name"].get<std::string>());
    }
}

void parser(std::string file) {
    auto JsonData = json::parse(file);
    int counter = 0;
    for (auto&[key, value]: JsonData["Valute"].items()) {
        valutes[counter].push_back(value["Value"].get<double>() / value["Nominal"].get<int>());
        counter += 1;
        std::cout << key << " " << value["Name"].get<std::string>() << ": "
                  << value["Value"].get<double>() / value["Nominal"].get<int>() << " руб.\n";
    }
    std::cout << "\n";
}

static size_t writeFunction(void *data, size_t size, size_t number, void *buffer) {
    ((std::string *) buffer)->append((char *) data, size * number);
    return size * number;
}

int main() {
    CURL *curl;
    std::string readBuffer;
    const std::string url("https://www.cbr-xml-daily.ru/daily_json.js");
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 15);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    curl_easy_perform(curl);
    fillNames(readBuffer);
    curl_easy_cleanup(curl);
    while (true) {
        curl_easy_perform(curl);
        parser(readBuffer);
        signal(SIGTERM, finish);
        sleep(10);
    }
}