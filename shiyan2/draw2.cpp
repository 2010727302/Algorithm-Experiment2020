#include<bits/stdc++.h>
#define debug(a) cout<<#a<<"="<<a<<endl

using namespace std;

// 判断节点是否可以着上指定颜色
bool isSafe(int node, int color, vector<vector<int>>& graph, vector<int>& colors) {
    for (int i = 0; i < graph[node].size(); i++) {
        int adjNode = graph[node][i];
        if (colors[adjNode] == color) {
            return false;
        }
    }
    return true;
}

// 回溯函数
bool backtrack(int node, int numColors, vector<vector<int>>& graph, vector<int>& colors) {
    if (node == graph.size()) {  // 所有节点都已经着色
        return true;
    }
    for (int i = 1; i <= numColors; i++) {  // 枚举当前节点的颜色
        if (isSafe(node, i, graph, colors)) {  // 如果可以着上颜色i
            colors[node] = i;
            if (backtrack(node + 1, numColors, graph, colors)) {  // 递归到下一个节点
                return true;  // 如果找到了可行解，直接返回
            }
            colors[node] = 0;  // 回溯
        }
    }
    return false;  // 找不到可行解
}

// 主函数
void graphColoring(vector<vector<int>>& graph, int numColors) {
    vector<int> colors(graph.size(), 0);
    if (backtrack(0, numColors, graph, colors)) {  // 从第一个节点开始着色
        cout << "可行解：";
        for (int i = 0; i < colors.size(); i++) {
            cout << colors[i] << " ";
        }
        cout << endl;
    } else {
        cout << "找不到可行解" << endl;
    }
}

int main() {
    // 构造输入的无向图
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2, 3, 4}, {0, 1, 3}, {0, 1, 2, 4}, {1, 3}};
    int numColors = 4;  // 设定颜色数为4
    graphColoring(graph, numColors);
    return 0;
}

