#include <vector>
#include <iostream>

using namespace std;
enum Color {White, Gray, Black};

void dfsVisit(vector<Color> &nodeColor, vector<int> &preNode,
         int nodeNum, int &count, int m, int n)
{
  nodeColor[nodeNum] = Gray;
  // find neighbor
  int row = nodeNum / n;
  int col = nodeNum % n;
  int upperRow = row - 1;
  int downRow = row + 1;
  int leftCol = col -1;
  int rightCol = col + 1;
  std::vector<int> neighborNodes;
  if ((row-1) >= 0) neighborNodes.push_back((row-1) *n + col);
  if ((col-1) >=0) neighborNodes.push_back(row * n + col -1);
  if ((row+1) < m) neighborNodes.push_back((row + 1) *n + col);
  if ((col+1) < n) neighborNodes.push_back(row* n + col +1);
  for (auto e: neighborNodes) {
    if (nodeColor[e] == White) {
      preNode[e] = nodeNum;
      int node = e;
      if (e == m * n -1) {
        while (node != -1) {
          std::cout << "(" << node/n << "," << node%n << ")";
          node = preNode[node];
        }
        std::cout << endl;
        ++ count;
        return;
      }
      dfsVisit(nodeColor, preNode, e, count, m, n);
    }
  }
  nodeColor[nodeNum] = White;
}

int main(int argc, char *argv[])
{
  int m, n;
  cin >> m >> n;
  vector<Color> nodeColor(m*n, White);
  vector<int> preNode(m*n, -1);
  int count = 0;
  dfsVisit(nodeColor, preNode, 0, count, m, n);
  return 0;
}
