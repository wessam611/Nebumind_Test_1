#include "file_reader.hpp"

Table FileReader::read_file(string path, FileType file_type)
{
    Table table;
    string line;
    ifstream file(path);
    if (file.is_open())
    {
        getline(file, line);
        table.set_headers(get_headers(line, file_type));
        if (file_type == LINE)
            table.add_row(get_row(line, file_type));
        while (getline(file, line))
        {
            table.add_row(get_row(line, file_type));
        }
        file.close();
    }
    else
    {
        cerr << "failed to open file " << path << endl;
        abort;
    }
    return table;
}

void FileReader::write_file(string path, Table table, FileType file_type)
{
    string buf;
    ofstream file(path);
    if (file.is_open())
    {
        switch (file_type)
        {
        case CSV:
            // using ; as delimiter

            for (string header : table.get_headers())
            {
                buf += header + ";";
            }
            buf[buf.size() - 1] = '\n';
            for (int i = 0; i < table.size(); i++)
            {
                for (string element : table.get_row(i))
                {
                    buf += element + ";";
                }
                buf[buf.size() - 1] = '\n';
            }
            file << buf;
            break;
        case LINE:
            // TODO
            break;
        }
    }
    else
    {
        cerr << "failed to open file " << path << endl;
        abort;
    }
    file.close();
}

vector<string> FileReader::get_headers(string line, FileType file_type)
{
    vector<string> headers;
    switch (file_type)
    {
    case CSV:
        // TODO
        break;
    case LINE:
        string curr = "";
        bool reading_header = true;
        for (char c : line)
        {
            if (reading_header)
            {
                if (c == '=')
                {
                    headers.push_back(curr);
                    curr = "";
                    reading_header = false;
                }
                else
                {
                    curr += c;
                }
            }
            else
            {
                if (c == ' ' || c == ',')
                {
                    reading_header = true;
                }
            }
        }
        break;
    }
    return headers;
}

vector<string> FileReader::get_row(string line, FileType file_type)
{
    vector<string> elements;
    switch (file_type)
    {
    case CSV:
        // TODO
        break;
    case LINE:
        string curr = "";
        bool reading_element = false;
        for (char c : line)
        {
            if (reading_element)
            {
                if (c == ',' || c == ' ')
                {
                    elements.push_back(curr);
                    curr = "";
                    reading_element = false;
                }
                else
                {
                    curr += c;
                }
            }
            else
            {
                if (c == '=')
                {
                    reading_element = true;
                }
            }
        }
        if (reading_element)
            elements.push_back(curr);
        break;
    }
    return elements;
}