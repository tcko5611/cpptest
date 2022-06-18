#include <vector>
#include <iostream>

using namespace std;
enum Color {White, Gray, Black};

void dfsVisit(vector<vector<Color> >&nodeColor, vector<int> &nodes, int m, int n)
{
  if ( m < 0 || m >= nodeColor.size() || n < 0 || n >= nodeColor[0].size()) return;
  if (nodeColor[m][n] == Gray) return;
  if (m == nodeColor.size()-1 && n == nodeColor[0].size() -1) {
    // ouput path
    int nodeId = m * nodeColor[0].size() + n;
    nodes.push_back(nodeId);
    for (int nodeId : nodes) {
      int row = nodeId / nodeColor[0].size();
      int col = nodeId % nodeColor[0].size();
      cout << "(" << row << "," << col << ") "; 
    }
    cout << endl;
    exit(0);
  }
  int nodeId = m * nodeColor[0].size() + n;
  nodes.push_back(nodeId);
  nodeColor[m][n] = Gray;
  dfsVisit(nodeColor, nodes, m++, n);
  dfsVisit(nodeColor, nodes, m--, n);
  dfsVisit(nodeColor, nodes, m, n++);
  dfsVisit(nodeColor, nodes, m, n--);
  nodes.pop_back();
}

int main(int argc, char *argv[])
{
  int M, N;
  cin >> M >> N;
  vector<vector<Color> > nodeColor(M, vector<Color>(N, White));
  vector<int> nodes;
  int count = 0;
  dfsVisit(nodeColor, nodes, 0, 0);
  return 0;
}
