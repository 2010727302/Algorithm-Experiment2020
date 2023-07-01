#include <bits/stdc++.h>
using namespace std;
class goods
{
public:
    int id;
    int weight;
    int price;
    float d;
};
class qnode
{
public:
    qnode *parent;
    int lchild;
    int upprofit;
    int profit;
    int weight;
    int lev;
};
struct cmp
{
    bool operator()(qnode *&a, qnode *&b) const
    {
        return a->upprofit < b->upprofit;
    }
};
bool cmp2(const goods &a, const goods &b)
{
    return a.d >= b.d;
}
int n;
int c;
int cw;
int cp;
int bestp;
goods obj[100];
int bestx[100];
void input()
{
	cout << "输入物品个数：";
	cin >> n;
	cout << "输入背包容量：";
	cin >> c;
	cout << "输入物品信息：（重量w 价值w）" << endl;
    for(int i = 1; i <= n; ++i)
    {
     scanf("%d %d", &obj[i].price, &obj[i].weight);
     obj[i].id = i;
     obj[i].d = 1.0 * obj[i].price / obj[i].weight;
    }
 
    sort(obj + 1, obj + n + 1, cmp2);
//    for(int i = 1; i <= n; ++i)
//        cout << obj[i].d << " ";
//    cout << endl << "input Complete" << endl;
}
int Bound(int i)
{
    int tmp_cleft = c - cw;
    int tmp_cp = cp;
    while(tmp_cleft >= obj[i].weight && i <= n)
    {
        tmp_cleft -= obj[i].weight;
        tmp_cp += obj[i].price;
        i++;
    }
    if(i <= n)
    {
        tmp_cp += tmp_cleft * obj[i].d;
    }
    return tmp_cp;
}
void addnode(priority_queue<qnode *, vector<qnode *>, cmp> &q, qnode *E, int up, int wt, int curp, int i, int ch)
{
    qnode *p = new qnode;
    p->parent = E;
    p->lchild = ch;
    p->weight = wt;
    p->upprofit = up;
    p->profit = curp;
    p->lev = i + 1;
    q.push(p);
    cout << "加入点的信息为 " << endl;
    cout << "p->lev = " << p->lev << " p->upprofit = " << p->upprofit << " p->weight =  " << p->weight << " p->profit =  " << p->profit << endl;
}
void backpack()
{
    priority_queue<qnode *, vector<qnode *>, cmp > q; // 大顶堆
    qnode *pa = NULL;
    cw = cp = bestp = 0;
    int i = 1;
    int up = Bound(1); //Bound(i)函数计算的是i还未处理时候的上限值
    while(i != n + 1)
    {
        int wt = cw + obj[i].weight;
        if(wt <= c)
        {
            if(bestp < cp + obj[i].price)
                bestp = cp + obj[i].price;
            addnode(q, pa, up, cw + obj[i].weight, cp + obj[i].price, i, 1);
        }
        up = Bound(i + 1); //注意这里 up != up - obj[i].price而且 up >= up - obj[i].price
        if(up >= bestp) //注意这里必须是大于等于
        {
            addnode(q, pa, up, cw, cp, i, 0);
        }
        pa = q.top();
        q.pop();
        cw = pa->weight;
        cp = pa->profit;
        up = pa->upprofit;
        i = pa->lev;
    }
    for(int j = n; j > 0; --j)
    {
        bestx[obj[pa->lev - 1].id] = pa->lchild;
        pa = pa->parent;
    }
}
void output()
{
    printf("最优装入量为 %d\n", bestp);
    printf("装入的物品为 \n");
    for(int i = 1; i <= n; ++i)
        if(bestx[i] == 1)
          printf("%d ", i);
}
int main()
{
    input();
    backpack();
    output();
}
//4 10
//40 4
//42 7
//25 5
//12 3

