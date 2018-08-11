#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

int nCount = 0;
int Matrix[100][100];

void chessBoard(int tr, int tc, int dr, int dc, int size);

int main()
{
    cout << "题目：棋盘覆盖问题" << endl;
    int size = 4; //棋盘大小
    int row = 0;  //特殊点的横坐标
    int col = 1;  //特殊点的纵坐标
    memset(Matrix, 0, sizeof(Matrix));

    chessBoard(0, 0, row, col, size);

    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            cout << Matrix[r][c] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}

void chessBoard(int tr, int tc, int dr, int dc, int size)
{
    //tr、tc为棋盘左上角的坐标
    int s, t;
    if (1 == size)
        return;

    s = size / 2; //分割棋盘
    t = ++nCount;

    //覆盖左上角子棋盘
    if (dr < tr + s && dc < tc + s)
    {
        chessBoard(tr, tc, dr, dc, s);
    }
    else
    {
        Matrix[tr + s - 1][tc + s - 1] = t;
        chessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
    }

    //覆盖左下角子棋盘
    if (dr < tr + s && dc >= tc + s)
    {
        chessBoard(tr, tc + s, dr, dc, s);
    }
    else
    {
        Matrix[tr + s - 1][tc + s] = t;
        chessBoard(tr, tc + s, tr + s - 1, tc + s, s);
    }

    //覆盖右上角子棋盘
    if (dr >= tr + s && dc < tc + s)
    {
        chessBoard(tr + s, tc, dr, dc, s);
    }
    else
    {
        Matrix[tr + s][tc + s - 1] = t;
        chessBoard(tr + s, tc, tr + s, tc + s - 1, s);
    }

    //覆盖右下角子棋盘
    if (dr >= tr + s && dc >= tc + s)
    {
        chessBoard(tr + s, tc + s, dr, dc, s);
    }
    else
    {
        Matrix[tr + s][tc + s] = t;
        chessBoard(tr + s, tc + s, tr + s, tc + s, s);
    }
}