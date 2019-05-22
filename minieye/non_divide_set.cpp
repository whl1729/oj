#include <iostream>
#include <map>
#include <set>
#include <random>

using namespace std;

map<int, int> deg_map; // 记录每个数字对应的degree
map<int, set<int>> div_map; // 记录能够与每个数字构成整除关系的数字集合
set<int> *deg_set;  // 将度相同的数字放在同一个链表
int max_degree = 0;

void get_non_divide_set(int input[], int size, set<int> &output);
void init_map(int input[], int size);
void init_set(int input[], int size);
void remove_nonzero_degree_elems();
inline bool divide(int i, int j);
void generate_input(int input[], int size);

int main()
{
    const int size = 10000;
    int input[size];
    set<int> output;

    generate_input(input, size);

    get_non_divide_set(input, size, output);
    
    cout << "max size: " << output.size() << endl;

    for (int elem : output)
        cout << elem << " ";
    cout << endl;

    return 0;
}

void get_non_divide_set(int input[], int size, set<int> &output)
{
    
    init_map(input, size);

    init_set(input, size);

    remove_nonzero_degree_elems();

    output = deg_set[0];

    delete [] deg_set;
}

// 求出每个数字的degree，与它构成整除关系的数字组成的数组，以及度的最大值
void init_map(int input[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        deg_map[input[i]] = 0;
        for (int j = 0; j < size; ++j)
        {
            if ((input[j] != input[i]) && divide(input[j], input[i]))
            {
                deg_map[input[i]]++;
                div_map[input[i]].insert(input[j]);
            }
        }

        if (deg_map[input[i]] > max_degree)
            max_degree = deg_map[input[i]];
    }
}

void init_set(int input[], int size)
{
    deg_set = new set<int>[max_degree + 1];
    for (int i = 0; i < size; ++i)
    {
        deg_set[deg_map[input[i]]].insert(input[i]);
    }
}

// 按照度由大到小删除元素，直至剩下的元素的度均为0
void remove_nonzero_degree_elems()
{
    for (int i = max_degree; i > 0; --i)
    {
        while (!deg_set[i].empty())
        {
            int cur = *deg_set[i].begin();
            deg_set[i].erase(cur);
            for (int j : div_map[cur])
            {
                deg_set[deg_map[j]].erase(j);
                deg_map[j]--;
                deg_set[deg_map[j]].insert(j);
                div_map[j].erase(cur);
            }
        }
    }
}

// 判断两个数字是否构成整除关系
inline bool divide(int i, int j)
{
    return ((i % j == 0) || (j % i == 0));
}

void generate_input(int input[], int size)
{
    default_random_engine engine;

    for (int i = 0; i < size; ++i)
        input[i] = engine() % 100000 + 1;
}
