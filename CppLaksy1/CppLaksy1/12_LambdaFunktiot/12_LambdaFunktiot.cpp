#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void laskeHP(int &hp)
{
    hp = (hp > 100) ? hp - 100 : 0;
}

struct LaskeHP
{
    void operator()(int &hp) const
    {
        hp = (hp > 100) ? hp - 100 : 0;
    }
};

int main()
{
    vector<int> hitpoints = { 150, 50, 700, 425, 335};
    // a.
    for_each(hitpoints.begin(), hitpoints.end(), laskeHP);
    // b.
    for_each(hitpoints.begin(), hitpoints.end(), LaskeHP());
    // c.
    for_each(hitpoints.begin(), hitpoints.end(), [](int &hp)
    {
        hp = (hp > 100) ? hp - 100 : 0;
    });
    // d.
    auto namedLambda = [](int &hp)
    {
        hp = (hp > 100) ? hp - 100 : 0;
    };
    for_each(hitpoints.begin(), hitpoints.end(), namedLambda);
    sort(hitpoints.begin(), hitpoints.end(), [](int a, int b)
    {
        return a > b;
    });
    for (const auto &hp : hitpoints)
    {
        cout << hp << " ";
    }
    return 0;
}