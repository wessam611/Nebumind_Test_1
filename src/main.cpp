#include <iostream>
#include <string>

#include "file_reader.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    string src, dst;
    FileReader reader;
    vector<string> out_order = {"x", "y" ,"z", "t", "sensor", "tag"};

    if (argc != 3){
        cerr << "expected 2 arguments: src_file_path and dst_file_path" << endl;
        return -1;
    }
    src = argv[1];
    dst = argv[2];

    Table table = reader.read_file(src, LINE);
    table.set_cols_order(out_order);
    reader.write_file(dst, table, CSV);
}