#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cmath>

#define N 1000
#define FOR(i,n) for(int i=0; i<n; i++)
#define MAX(a,b) ((a>b) ? a : b)
#define DIFF(a,b) (abs(a-b))
#define TEST 1

using namespace std;

typedef struct Item
{
    // item serial number
    int serial_no;
    // item name
    char item_name[100];
    // gross weight
    int gw;
    // volume weight
    int vw;
    // charge weight, max(gw, vw)
    int cw;
    // difference between g & v
    int gv_diff;
};

int max_net_profit;
int total_gw;
int total_vw;
int total_cw;
int total_gv_diff;

const int INF_MAX = 1 << 30;
const int MAX_SIZE = 15;            // Maximum number of solution will print

map < vector <int> ,int > mp;
vector<vector <vector<int> > > store;

int total_items;
Item items[N];

void read_inputs(int total);
void print_inputs(int total);

int ret_ans(vector<int> s);
void store_combination(vector <int> s,int val,vector <vector<int> > pred);
void solve();

int main()
{
#ifdef TEST
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif // TEST

    max_net_profit = total_gw = total_vw = total_cw = total_gv_diff = 0;

    printf("Enter total number of Items: ");
    scanf("%d", &total_items);

    read_inputs(total_items);

    print_inputs(total_items);

    solve();

    return 0;
}


void read_inputs(int total)
{
    char temp[100];
    Item t;

#ifdef TEST
    scanf(" %[^\n]", temp);     // first line, ignore, ignore defination
    scanf(" %[^\n]", temp);     // second line, ignore, -------
#endif

    FOR(i,total)
    {
        scanf("%d %s %d %d", &t.serial_no, t.item_name, &t.gw, &t.vw);
        t.gv_diff = DIFF(t.gw, t.vw);
        t.cw = MAX(t.gw, t.vw);
        items[i] = t;

        total_gw += t.gw;
        total_vw += t.vw;
        total_cw += t.cw;
        total_gv_diff += t.gv_diff;
    }
    max_net_profit = DIFF(total_cw, MAX(total_gw,total_vw));
}

void print_inputs(int total)
{
    Item t;

    printf("\n");

    FOR(i,total)
    {
        t = items[i];
        printf("%d\t%s\t%d\t%d\t%d\t%d\n", t.serial_no, &t.item_name, t.gw, t.vw, t.cw, t.gv_diff);
    }

    printf("\n");
    printf("Total \t gw \t gv \t gc \t gv_diff \t net_profit\n");
    printf("\t %d \t %d \t %d \t %d \t %d\n", total_gw, total_vw, total_cw, total_gv_diff, max_net_profit);
}

void solve()
{
    vector <int> s;
    vector <vector <int> > t,pred;
    for (int i=0;i<total_items;i++) s.push_back(i);
    int ans = ret_ans(s);
    int test = 0;
    cout <<endl<<"The optimum charge cost is: "<<ans<<endl;
    cout<<"The maximum profit is: "<<total_cw - ans<<endl;
    store.clear();
    store_combination(s,ans,pred);
    cout<<"The "<<store.size()<<" best combination(s)s for max profit are: "<<endl<<endl<<endl;
    for (int i=0;i<store.size();i++)
    {
        t = store[i];
        cout<<"\t";
        for (int j=0;j<t.size();j++)
        {
            cout<<"{";
            for (int k=0;k<t[j].size();k++)
            {
                cout<<items[t[j][k]].serial_no;
                if (k != t[j].size()-1) cout<<",";
            }
            cout<<"} ";
        }
        if (t.size()) cout<<endl;
    }
    cout<<endl;
}

int ret_ans(vector<int> s)
{
    if (mp[s])
    {
        return mp[s];
    }
    int ret,a,b,i,j,k,l,m,n,len,c_gw = 0,c_vw = 0;
    len = s.size();
    if (len==1)
    {
        i = s[0] ;
        mp[s] = items[i].cw;
        return items[i].cw;
    }
    if (len < 1)
    {
        return 0;
    }
    ret = 0;
    for (i=0;i<len;i++)
    {
        j = s[i];
        c_gw += items[j].gw;
        c_vw += items[j].vw;
    }
    ret = max(c_gw,c_vw);
    mp[s] = ret;
    vector<int> sf,ss;
    for (i=0;i<len;i++)
    {
        for (j=0;j + i <len;j++)
        {
            sf.clear(); ss.clear();
            for (k=j;k<=j+i;k++)
            {
                sf.push_back(s[k]);
            }
            for (k=0;k<j;k++)
            {
                ss.push_back(s[k]);
            }
            for (k=j+i+1;k<len;k++)
            {
                ss.push_back(s[k]);
            }
            a = ret_ans(sf);
            b = ret_ans(ss);
            ret = min(ret,a+b);
        }
    }
    mp[s] = ret;
    return ret;
}

void store_combination(vector <int> s,int val,vector <vector<int> > pred)
{
    if (store.size() >= MAX_SIZE ) return;
    int ret,i,j,k,a,b,len,c_gw = 0,c_vw = 0;
    len = s.size();
    vector <vector <int> > vt;
    if (len==1)
    {
        vt = pred;
        vt.push_back(s);
        store.push_back(vt);
        return;
    }
    if (len < 1)
    {
        return;
    }
    ret = 0;
    for (i=0;i<len;i++)
    {
        j = s[i];
        c_gw += items[j].gw;
        c_vw += items[j].vw;
    }
    ret = max(c_gw,c_vw);
    if (ret == val)
    {
        vt = pred;
        vt.push_back(s);
        store.push_back(vt);
        if (store.size() >= MAX_SIZE) return;
    }
    vector <int> sf,ss;
    bool flag = 0;
    for (i=0;i<len;i++)
    {
        for (j=0;j + i <len;j++)
        {
            sf.clear(); ss.clear();
            for (k=j;k<=j+i;k++)
            {
                sf.push_back(s[k]);
            }
            for (k=0;k<j;k++)
            {
                ss.push_back(s[k]);
            }
            for (k=j+i+1;k<len;k++)
            {
                ss.push_back(s[k]);
            }
            a = ret_ans(sf);
            b = ret_ans(ss);
            ret = a + b;
            if (ret == val && store.size() < MAX_SIZE)
            {
                vt = pred;
                vt.push_back(sf);
                store_combination(ss,b,vt);
            }
            if (store.size() >= MAX_SIZE) break;
        }
        if (store.size() >= MAX_SIZE) break;
    }
    return ;
}


/*/
6
Item No -  Item Name - Gross Weight[G] - Volume weight[V] - Charge weight,[C=max(G,V)]
----------------------------------------------------------------------------
1 A 15 4
2 B 7 30
3 C 55 21
4 D 7 15
5 E 15 7
6 F 17 70
//*/
