#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Table class for saving headers and content of a table
*/
class Table{
public:
    void set_headers(vector<string>);
    vector<string> get_headers();
    void add_row(vector<string>);
    int size();
    vector<string> get_row(int);
    string get_element(int, string header);
    void set_element(int, string header, string val);
    void set_cols_order(vector<string> headers_order);
private:
    vector<string> headers;
    vector<vector<string>> rows;
};