#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;


bool maze_solution_is_correct(string output_file_name, string solution_file_name) {

    //open the files
    ifstream output_file, solution_file;
    output_file.open(output_file_name.c_str());
    solution_file.open(solution_file_name.c_str());

    if (!output_file) {
        cerr<<" output file didnt open successfully ";
        exit(1);
    }

    if (!solution_file) {
        cerr<<" solution file didnt open successfully ";
        exit(1);
    }

    //main logic
    string output;
    getline(output_file,output);

    bool has_solution;
    solution_file>>has_solution;

    string dummy;
    getline(solution_file,dummy);

    //case 1: no solution exists
    if (has_solution == false) {
        return (output == "NO SOLUTION");
    }

    //case 2: a solution exists
    string line;
    vector<string> maze;
    int curr_i, curr_j;
    int i = 0;
    while(getline(solution_file, line)) {
        maze.push_back(line);
        for (int j = 0; j < line.size(); ++j) {
            if (line[j] == 'S') {
                curr_i = i;
                curr_j = j;
            }
        }
        i++;
    }
    maze[curr_i][curr_j] = '$'; //$ means "visited"
    for (int k = 0; k < output.size(); ++k) {
        switch(output[k]) {
            case 'R':
                curr_j++;
                break;
            case 'L':
                curr_j--;
                break;
            case 'U':
                curr_i--;
                break;
            case 'D':
                curr_i++;
                break;
            default:
                return false;
        }

        if (curr_i >= maze.size() || curr_j >= maze[0].size()) {
            return false;
        }

        char curr_cell = maze[curr_i][curr_j];

        if (curr_cell == '#')
            return false;

        if (curr_cell == 'E')
            return true;

        maze[curr_i][curr_j] = '$'; // mark the cell as "visited"

    }

    return false; // if output ends and we haven't yet arrived at 'E'
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr<<" usage : ./a.out <output_file_name> <solution_file_name> ";
        return 1;
    }
    return !maze_solution_is_correct(argv[1], argv[2]);
}

