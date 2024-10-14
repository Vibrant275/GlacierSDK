#include <string>
#include <vector>

struct AppConfig {
    std::string appName;
    std::string package;
    std::vector<std::string> platforms;
};


//class AppConfig {
//private:
//    std::string appName;
//    std::string package;
//    std::vector<std::string> platforms;
//
//public:
//    const std::string &getAppName() const {
//        return appName;
//    }
//
//    void setAppName(const std::string &appName) {
//        AppConfig::appName = appName;
//    }
//
//    const std::string &getPackage() const {
//        return package;
//    }
//
//    void setPackage(const std::string &aPackage) {
//        package = aPackage;
//    }
//
//    const std::vector<std::string> &getPlatforms() const {
//        return platforms;
//    }
//
//    void setPlatforms(const std::vector<std::string> &platforms) {
//        AppConfig::platforms = platforms;
//    }
//};
