#include <iostream>
#include <vector>

using namespace std;
#define N_POSSIBLE_MOVES 4

typedef struct {
    vector< vector<char> > content;
    vector< vector<bool> > is_in_current_path;
    int start_i,start_j;
} Maze ;

int delta_i[N_POSSIBLE_MOVES] = {0 , -1,  0, +1};
int delta_j[N_POSSIBLE_MOVES] = {+1,  0, -1,  0};
int move_char_rep[N_POSSIBLE_MOVES] = {'R','U','L','D'};


Maze read_maze() {
    Maze result;

    string line;
    int i = 0;
    while (getline(cin, line)) {
        vector<char> current_row;
        for (int j = 0; j < line.size(); ++j) {
            current_row.push_back(line[j]);
            if (line[j] == 'S') {
                result.start_i = i;
                result.start_j = j;
            }
        }
        result.content.push_back(current_row);
        result.is_in_current_path.push_back(vector<bool>(line.size(), false));
        i++;
    }
    return result;
}

void print_maze(Maze maze) {
    for (int i = 0; i < maze.content.size(); i++) {
        for (int j = 0; j < maze.content[i].size(); ++j) {
            cout<<maze.content[i][j];
        }
        cout<<endl;
    }
    cout<<"start i,j :"<<maze.start_i<<" "<<maze.start_j<<endl;
}

bool can_move_to_cell(Maze maze, int i, int j) {
    if (i >= maze.content.size() || j >= maze.content[0].size()) //out of maze
        return false;
    else if (maze.content[i][j] == '#') //wall
        return false;
    else if (maze.is_in_current_path[i][j]) //already in path
        return false;
    else
        return true;
}

bool solve_maze_rec(Maze maze, string& path, int current_i, int current_j) {
//    cout<<"solve maze rec : "<<current_i<<" "<<current_j<<endl;

    maze.is_in_current_path[current_i][current_j] = true;

    if (maze.content[current_i][current_j] == 'E') {
        return true;
    }

    for (int k = 0; k < N_POSSIBLE_MOVES; ++k) {
        int new_i = current_i + delta_i[k];
        int new_j = current_j + delta_j[k];

        if (!can_move_to_cell(maze,new_i,new_j))
            continue;

        path.push_back(move_char_rep[k]);
        bool found_solution = solve_maze_rec(maze, path, new_i, new_j);
        if (found_solution) {
            return true;
        } else {
            path.erase(path.size() - 1);
        }
    }

    maze.is_in_current_path[current_i][current_j] = false;
    return false;
}

void solve_maze(Maze maze) {
    string path;
    bool maze_has_solution = solve_maze_rec(maze, path, maze.start_i, maze.start_j);
    if (maze_has_solution) {
        cout<<path<<endl;
    } else {
        cout<<"NO SOLUTION"<<endl;
    }
}

int main() {
    Maze maze = read_maze();
    solve_maze(maze);
}