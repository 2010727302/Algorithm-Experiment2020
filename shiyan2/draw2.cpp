#include<bits/stdc++.h>
#define debug(a) cout<<#a<<"="<<a<<endl

using namespace std;

// �жϽڵ��Ƿ��������ָ����ɫ
bool isSafe(int node, int color, vector<vector<int>>& graph, vector<int>& colors) {
    for (int i = 0; i < graph[node].size(); i++) {
        int adjNode = graph[node][i];
        if (colors[adjNode] == color) {
            return false;
        }
    }
    return true;
}

// ���ݺ���
bool backtrack(int node, int numColors, vector<vector<int>>& graph, vector<int>& colors) {
    if (node == graph.size()) {  // ���нڵ㶼�Ѿ���ɫ
        return true;
    }
    for (int i = 1; i <= numColors; i++) {  // ö�ٵ�ǰ�ڵ����ɫ
        if (isSafe(node, i, graph, colors)) {  // �������������ɫi
            colors[node] = i;
            if (backtrack(node + 1, numColors, graph, colors)) {  // �ݹ鵽��һ���ڵ�
                return true;  // ����ҵ��˿��н⣬ֱ�ӷ���
            }
            colors[node] = 0;  // ����
        }
    }
    return false;  // �Ҳ������н�
}

// ������
void graphColoring(vector<vector<int>>& graph, int numColors) {
    vector<int> colors(graph.size(), 0);
    if (backtrack(0, numColors, graph, colors)) {  // �ӵ�һ���ڵ㿪ʼ��ɫ
        cout << "���н⣺";
        for (int i = 0; i < colors.size(); i++) {
            cout << colors[i] << " ";
        }
        cout << endl;
    } else {
        cout << "�Ҳ������н�" << endl;
    }
}

int main() {
    // �������������ͼ
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2, 3, 4}, {0, 1, 3}, {0, 1, 2, 4}, {1, 3}};
    int numColors = 4;  // �趨��ɫ��Ϊ4
    graphColoring(graph, numColors);
    return 0;
}

