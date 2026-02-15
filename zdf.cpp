/* * ZEGA ZDF Compiler - Official GNU GPL v3 Source
 * Owner: ZEGA 
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

// ZEGA Base Dialect: Expandable for Logic, Hardcoded for Data
std::map<std::string, std::string> load_dialect() {
    return {
        // Hardcoded Data Tags (api.dll expects these specifically)
        {"image",       "image.data"},
        {"video",       "video.data"},
        {"tensorarray", "ta.data"},
        
        // Expandable Logic Tags
        {"python",      "py.code"},
        {"cpp",         "cpp.code"},
        {"rust",        "rust.code"},
        {"c",           "c.code"},
        {"z",           "z.code"},
        {"r",           "r.code"},
        
        {"start",       "[[['"},
        {"stop",        "']]]"}
    };
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "\033[38;5;82mZEGA Compiler v1.2\033[0m\nUsage: zdf -compile <file>" << std::endl;
        return 1;
    }

    auto dialect = load_dialect();
    std::string input = argv[1];
    std::string output = input + ".czdf";

    std::ifstream src(input);
    std::ofstream dest(output, std::ios::binary);

    if (!src.is_open()) return 1;

    std::string line;
    std::cout << "\033[38;5;82m[ZEGA]\033[0m Mapping dialect and packing binary..." << std::endl;

    while (std::getline(src, line)) {
        // Strip comments
        if (line.find("{") != std::string::npos && line.find("}") != std::string::npos) continue;

        // Write to binary stream
        dest.write(line.c_str(), line.size());
        dest.put('\n'); 
    }

    std::cout << "\033[38;5;82m[SUCCESS]\033[0m Created: " << output << std::endl;
    return 0;
}