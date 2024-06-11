#include <iostream>
#include <cassert>
#include <vector>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rows(r, c) for(int r = 0; r < 8; r++) for(int c = 0; c < 8; c++)

typedef pair<int, int> C;

vector<string> board(8);

vector<C> getDelta(const vector<C>& deltas, int row, int col, int dist){
	vector<C> ans;
	for(const C& delta : deltas)
		for(int i = 1; i <= dist; ++i){
			int nr = row + i * delta.first;
			int nc = col + i * delta.second;
			if(nr < 0 || nc < 0 || nr >= 8 || nc >= 8) continue;
			if(islower(board[row][col]) == islower(board[nr][nc]) && isalpha(board[nr][nc])) break;
			ans.emplace_back(nr, nc);
			if(deltas.size() == 4 && isalpha(board[nr][nc])) break;
		}
	return ans;
}

vector<C> bishop = { {-1, -1}, {1, -1}, {-1, 1}, {1, 1} };
vector<C> rook = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
vector<C> knight = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2} };

vector<C> getPawn(int row, int col){
	vector<C> possible;
	int dx = isupper(board[row][col]) ? -1 : 1;
	if(row == (isupper(board[row][col]) ? 0 : 7)){
		vector<C> b = getDelta(bishop, row, col, 8),
		       r = getDelta(rook, row, col, 8),
		       n = getDelta(knight, row, col, 1);
		possible.insert(possible.begin(), all(b));
		possible.insert(possible.begin(), all(r));
		possible.insert(possible.begin(), all(n));
	} else {
		if(board[row+dx][col] == '.'){
			possible.emplace_back(row+dx, col);
			if(row+dx+dx < 8 && row+dx+dx >= 0 && board[row+dx+dx][col] == '.'){
				possible.emplace_back(row+dx+dx, col);
			}
		}
		if(col && isupper(board[row][col]) ? islower(board[row+dx][col-1]) :
						     isupper(board[row+dx][col-1])) possible.emplace_back(row+dx, col-1);
		if(col != 7 && isupper(board[row][col]) ? 
						     islower(board[row+dx][col+1]) :
						     isupper(board[row+dx][col+1])) possible.emplace_back(row+dx, col+1);
	}
	return possible;
}

vector<C> getMoves(int row, int col){
	char piece = toupper(board[row][col]);
	if(piece == 'Q'){
		vector<C> bishops = getDelta(bishop, row, col, 8);
		vector<C> rooks = getDelta(rook, row, col, 8);
		bishops.insert(bishops.begin(), all(rooks));
		return bishops;
	} 
	else if(piece == 'R') return getDelta(rook, row, col, 8);
	else if(piece == 'B') return getDelta(bishop, row, col, 8);
	else if(piece == 'K'){
		vector<C> bishops = getDelta(bishop, row, col, 1);
		vector<C> rooks = getDelta(rook, row, col, 1);
		bishops.insert(bishops.begin(), all(rooks));
		return bishops;
	} 
	else if(piece == 'N') return getDelta(knight, row, col, 1);
	else if(piece == 'P') return getPawn(row, col);
	assert(false && "Bad piece");
}

bool isThreatened(char piece){
	int theRow, theCol;
	rows(row, col)
		if(board[row][col] == piece) theRow = row, theCol = col;
	rows(row, col)
		if(board[row][col] != '.' && islower(board[row][col]) != islower(piece))
			for(const C& move : getMoves(row, col))
				if(move.first == theRow && move.second == theCol) return true;
	return false;
}

#define domove(move, piece, newpiece, r, c) { \
	board[move.first][move.second] = piece; \
	board[r][c] = newpiece; }

int main() {
	for(int i = 0; i < 8; ++i) cin >> board[i];
	rows(row, col){
		char piece = board[row][col];
		if(piece == '.' || islower(piece)) continue;
		for(const C& move : getMoves(row, col)){
			char orig = board[move.first][move.second];
			domove(move, piece, '.', row, col);
			if(!isThreatened('K') && isThreatened('k')){
				rows(row1, col1){
					char piece1 = board[row1][col1];
					if(piece1 == '.' || isupper(piece1)) continue;
					for(const C& move1 : getMoves(row1, col1)){
						char orig1 = board[move1.first][move1.second];
						domove(move1, piece1, '.', row1, col1);
						if(!isThreatened('k')){
							domove(move1, orig1, piece1, row1, col1);
							goto nextMove;
						}
						domove(move1, orig1, piece1, row1, col1);
					}
				}
				cout << (char)(col+'a') << (char)(7-row+'1') << (char)(move.second+'a') << (char)(7-move.first+'1') << endl;

			}
nextMove:
			domove(move, orig, piece, row, col);
		}
	}
}
