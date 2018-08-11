#include <iostream>
#include <string>
using namespace std;

class Foo
{
  public:
    int t;

  private:
    size_t u;
};

class Bar
{
  public:
    Bar(string n)
    {
        name = n;
    }
    string getName()
    {
        return name;
    }

  private:
    string name;
};

int main()
{
    Foo foo = Foo();
    Bar bar = Bar("baba");
    cout << bar.getName() << endl;
    system("pause");
    return 0;
}
