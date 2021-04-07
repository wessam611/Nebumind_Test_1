#include <iostream>
#include <fstream>

#include "table.hpp"

using namespace std;


enum FileType{LINE,CSV};
/*
    FileReader class for handling reading and writing .line and .csv
    file while storing the data
*/
class FileReader{

public:
    Table read_file(string path, FileType=LINE);
    void write_file(string path, Table, FileType=CSV);
private:
    vector<string> get_headers(string line, FileType=LINE);
    vector<string> get_row(string line, FileType=CSV);
};