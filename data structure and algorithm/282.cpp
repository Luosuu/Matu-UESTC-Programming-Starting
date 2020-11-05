#include<iostream>
#include<cassert>

class Pair {
public:
	int first, second;
	Pair(int x=0, int y=0) :first(x), second(y) {};
	Pair operator + (Pair P)
	{
		return Pair(first + P.first, second + P.second);
	}
};

class queue {
private:
	Pair* data;
	int head;
	int end;
public:
	queue(int s) :head(0), end(0) { data = new Pair[s]; };
	~queue() { delete[]data; };
	void push_back(const Pair & v)
	{
		data[end++] = v;
	}
	Pair pop_front()
	{
		return data[head++];
	}
	int size()
	{
		return end - head;
	}
};

const int maxn = 1000;
int board[maxn][maxn];

int main()
{
	using namespace std;

	int n, m, x0, y0, ask;
	cin >> n >> m >> x0 >> y0 >> ask;
	x0--, y0--;
	const int maxstep = m * n + 1;
	queue q(m * n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			board[i][j] = maxstep;

	const Pair dire[] = {
		Pair(-2,-1),
		Pair(-2,1),
		Pair(-1,2),
		Pair(-1,-2),
		Pair(1,2),
		Pair(1,-2),
		Pair(2,1),
		Pair(2,-1)
	};

	board[x0][y0] = 0;
	q.push_back(Pair( x0,y0 ));
	int visited = 1;
	while (q.size() && visited != m * n)
	{
		Pair temp = q.pop_front();
		for (int i = 0; i < 8; i++)
		{
			Pair temp2 = temp + dire[i];
			if (temp2.first < 0 || temp2.first >= n ||
				temp2.second < 0 || temp2.second >= m ||
				board[temp2.first][temp2.second] <= board[temp.first][temp.second] + 1
				)
				continue;
			assert(board[temp2.first][temp2.second] == maxstep);
			board[temp2.first][temp2.second] = board[temp.first][temp.second] + 1;
			visited++;
			q.push_back(temp2);
		}
		//cout << visited << endl;
	}
	
	int x, y;
	for (int i = 0; i < ask; i++)
	{
		cin >> x >> y;
		x--, y--;
		if (board[x][y] != maxstep)
			cout << board[x][y] << endl;
		else
			cout << -1 << endl;
	}
}