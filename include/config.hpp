#ifndef CONFIG_PROJECT_H
#define CONFIG_PROJECT_H

#include <string>


class Config {
  private:
    std::string filename;
  public:
    Config(std::string _filename);
    void load_data(std::string filename);
};

#endif
