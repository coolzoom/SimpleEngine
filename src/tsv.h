#pragma once

#include "defines.h"
#include "defineTypes.h"
#include "Environment.h"

template<typename Out>
inline void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

inline std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}
namespace utils
{
	class tsv
	{
	public:
		tsv(String path)
		{
			std::string file_content;
			std::ifstream fs;
			// fs.exceptions(std::ifstream::failbit | std::ifstream::badbit);
			fs.open(path.c_str());
			std::stringstream  ss;
			ss << fs.rdbuf();
			fs.close();
			file_content = ss.str();			
			
			rows = split(file_content, LINE_SAPARATOR);
			int i=0;
			for(auto& line : rows)
			{
				if(i == 0 )
				{
					titles= split(line, '\t');
				}
				else
				{	
					cols[i-1] = split(line, '\t');
				}
				i++;
			}
		}

		~tsv()
		{

		}

		void print()
		{

			std::cout  << "rows:" << rows.size() << " cols:" << titles.size() << std::endl;
			for(auto& title : titles)
			{
				std::cout << title << '\t' ;
			}
			std::cout << std::endl;
		}
		String val(int row,int col) 
		{
            if(row <0 || row >= rows.size() || col < 0 || col >= titles.size())return "";
			return cols[row][col];
		}
		std::vector<String> query(int id)
		{
			return cols[id-1];
		}
        std::map<int,std::vector<String>> cols;
		std::vector<String> titles;
        std::vector<String> rows;
	};
};
