#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<unordered_map>
#include"Digit.h"
using namespace std;
typedef pair<int, string> PIS;
unordered_map <string, int> dist;
unordered_map <string, pair<string, char>> pre;
priority_queue<PIS, vector<PIS>, greater<PIS>> heap;
string ed = "12345678x";
int dx[4] = { -1 , 0 , 1 , 0 }, dy[4] = { 0 , 1 , 0 , -1 };
char op[] = "urdl";
int f(string state)//求估值函数,这里是曼哈顿距离

{

    int res = 0;

    for (int i = 0; i < 9; i++)

    {

        if (state[i] != 'x')

        {
            int t = state[i] - '1';

            res += abs(t / 3 - i / 3) + abs(t % 3 - i % 3);

        }

    }
    return res;

}
string bfs(string start)

{

    heap.push({ f(start) , start });

    dist[start] = 0;



    while (heap.size())

    {

        auto t = heap.top();

        heap.pop();

        cout << "当前节点：state " << t.second << "  估值：" << t.first << endl;

        string state = t.second;

        int step = dist[state];//记录到达state的实际距离

        if (state == ed) break;//如果到达终点就break



        int k = state.find('x');

        int x = k / 3, y = k % 3;



        string source = state;//因为在下面state会变，所以留一个备份

        for (int i = 0; i < 4; i++)

        {

            int a = x + dx[i], b = y + dy[i];

            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(state[x * 3 + y], state[a * 3 + b]);
                if (!dist.count(state) || dist[state] > step + 1)
                {

                    dist[state] = step + 1;

                    pre[state] = { source, op[i] };

                    heap.push({ dist[state] + f(state), state });
                }
                swap(state[x * 3 + y], state[a * 3 + b]);//因为要多次交换，所以要恢复现场
            }
        }
    }
    string res;

    while (ed != start)

    {

        res += pre[ed].second;

        ed = pre[ed].first;

    }

    reverse(res.begin(), res.end());

    return res;

}



void getdigit()

{

    string start, seq;

    for (int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        start += c;
        if (c != 'x') seq += c;
    }

    int cnt = 0;

    for (int i = 0; i < 8; i++)
        for (int j = i + 1; j < 8; j++)
            if (seq[i] > seq[j])
                cnt++;
    if (cnt % 2) puts("unsolvable");
    else cout << bfs(start) << endl;
}

