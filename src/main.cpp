#include <iostream>
#include <string>

#include <Eigen/Dense>

#include "file_reader.hpp"

using namespace std;
using namespace Eigen;

void transform(Vector3f &coo, Quaternionf q, Vector3f trans)
{
    coo = q.normalized().toRotationMatrix()*coo + trans;
}

void transform_table_coo(Table &table, Quaternionf q, Vector3f trans)
{
    for (int i = 0; i < table.size(); i++)
    {
        float x = stof(table.get_element(i, "x"));
        float y = stof(table.get_element(i, "y"));
        float z = stof(table.get_element(i, "z"));
        Vector3f coo;
        coo << x, y, z;
        transform(coo, q, trans);
        table.set_element(i, "x", to_string(coo.x()));
        table.set_element(i, "y", to_string(coo.y()));
        table.set_element(i, "z", to_string(coo.z()));
    }
}

int main(int argc, char *argv[])
{
    string src, dst;
    FileReader reader;
    vector<string> out_order = {"x", "y", "z", "t", "sensor", "tag"};
    Quaternionf q(0.707, 0, 0, 0.707);
    Vector3f trans;
    trans << 100, 50, 42;

    if (argc != 3)
    {
        cerr << "expected 2 arguments: src_file_path and dst_file_path" << endl;
        return -1;
    }
    src = argv[1];
    dst = argv[2];

    Table table = reader.read_file(src, LINE);
    transform_table_coo(table, q, trans);
    table.set_cols_order(out_order);
    reader.write_file(dst, table, CSV);
}