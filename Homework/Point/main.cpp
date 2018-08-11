#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;
class Point //定义一个坐标点类
{
public:
    Point(double x, double y);
    double getx() const
    {
        return m_x;
    }
    double gety() const
    {
        return m_y;
    }
    friend ostream& operator<<(ostream& os, const Point& p);

private:
    double m_x;
    double m_y;
};

Point::Point(double x, double y) : m_x(x), m_y(y)
{
}

ostream& operator<<(ostream& os, const Point& p)//重载运算符
{
    os<<"P("<<p.getx()<<","<<p.gety()<<")";
    return os;
}

double Distance(const Point& s, const Point& t)//求解距离
{
    double squarex = ( s.getx() - t.getx() ) * ( s.getx() - t.getx() );
    double squarey = ( s.gety() - t.gety() ) * ( s.gety() - t.gety() );
    return sqrt( squarex + squarey );
}

bool ComparePoint(const Point& p1, const Point& p2)
{
    return (p1.getx() < p2.getx());
}

double EnumShortestPair(const Point * p, int num)
{
    double distance=Distance(p[0], p[1]);
    int start = 0;
    int end = 1;
    for (int i=0; i<num; i++)
    {
        for (int j=i+1; j<num; j++)
        {
            if ( Distance(p[i], p[j]) < distance )
            {
                distance = Distance(p[i], p[j]);
                start = i;
                end = j;
            }
        }
    }
    return distance;
}

double FindShortPairDC(const Point * p, int num)//寻找最近的点
{
    double dL, dR, d, midXVal;
    if (num < 2)
    {
        cout << "Need to input more than 2 points!"<< endl;
        exit(1);
    }
    if (num < 4)
    {
        return EnumShortestPair(p, num);
    }

    int mid = 0;
    mid = (num+1)/2;
    dL = FindShortPairDC(p, mid);
    dR = FindShortPairDC(p+mid, (num-mid));
    d = dL < dR ? dL : dR;

    midXVal = p[mid].getx();

    int stripStart = 0;
    int stripEnd = num-1;
    for (int i=0; i<num-1; i++)
    {
        if ( (p[i].getx() < midXVal-d) && (p[i+1].getx() >= midXVal-d) )
            stripStart = i+1;
        if ( (p[i].getx() <= midXVal+d) && (p[i+1].getx() > midXVal+d) )
            stripEnd = i;
    }
    int start = 0;
    int end = 1;
    for (int i=stripStart; i<stripEnd; i++)
    {
        for (int j=i+1; j<stripEnd; j++)
        {
            if ( Distance(p[i], p[j]) < d )
            {
                d = Distance(p[i], p[j]);
                start = i;
                end = j;
            }
        }
    }
    if (start!=0 || end!=0)
        cout << "The shortest pair is: P" << start+1 << ", P" << end+1 <<""<<endl;

    cout << "the distance is: " << d <<endl;
    return d;
}

void PrintPoints(const Point * p, int num)//打印点
{
    for (int i=0; i<num; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}

int main()
{
    Point p[] = {Point(2,3), Point(4,3), Point(4,6), Point(5,7), Point(4,3)};
    int size = sizeof(p)/sizeof(p[0]);
    PrintPoints(p, size);
    sort(p, p+size, ComparePoint);
    PrintPoints(p, size);
    FindShortPairDC(p, size);
    system("pause");
    return 0;
}

