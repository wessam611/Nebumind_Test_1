#include "table.hpp"

void Table::set_headers(vector<string> headers)
{
    this->headers = headers;
}

vector<string> Table::get_headers()
{
    return headers;
}
void Table::add_row(vector<string> elements)
{
    if (headers.size() == 0)
    {
        cerr << "failed to add row. table headers are not defined." << endl;
        abort;
    }
    if (elements.size() != headers.size())
    {
        cerr << "failed to add row. row size is " << elements.size() << " while headers size is " << headers.size() << endl;
        abort;
    }

    // TODO: assert the type of elements here when handling types of columns
    rows.push_back(elements);
}

int Table::size()
{
    return rows.size();
}

vector<string> Table::get_row(int index)
{
    return rows.at(index);
}

string Table::get_element(int index, string header)
{

    vector<string>::iterator it = find(headers.begin(), headers.end(), header);
    if (it == headers.end())
    {
        cerr << "column " << header << " isn't defined in the table" << endl;
    }
    return rows.at(index).at(it - headers.begin());
}

void Table::set_element(int index, string header, string val)
{

    vector<string>::iterator it = find(headers.begin(), headers.end(), header);
    if (it == headers.end())
    {
        cerr << "column " << header << " isn't defined in the table" << endl;
        abort;
    }
    // TODO: assert the type of val here when handling types of columns
    rows.at(index).at(it - headers.begin()) = val;
}
