#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include <math.h>

using namespace std;

#define k 3          //������
#define n 2        //����ά��
#define size 30     //���ݴ�С
////////////////////����洢�ṹ//////////////////////////////
typedef struct {
    double d[n];
    double distance[k];
} Data;
typedef struct {
    Data center[k];  // ����������
    int cluster[k][size]; //������
    int cluster_num[k];
    // ������һ�����ݵı��
    Data old_center[k];
    int isend[k][n]; //�����������Ƿ���ȱ�ʾֵ
    int is;
} Tdata;

////////��������//////////////////////////////

void input_data();

void Init_center();

void calculate_distance();

double Euclid(int x, int y);

void new_cluster();

void new_center();

void output_info();

void comp();

Data data[size];
Tdata td;

///////////////��������////////////////////////
void Init() {
    char name1[50];
    ifstream infile;
    cout << "����Ҫ�򿪵��ļ���*.txt" << endl;
    cin >> name1;
    infile.open(name1, ios::in);
    if (infile.fail()) {
        cout << "error open!" << endl;
    }
    for (int i = 0; i < size; i++)
        for (int j = 0; j < n; j++) {
            infile >> data[i].d[j];
        }

    cout << "the data are:" << endl;
    for (int i = 0; i < size; i++) {           //���Ҫ���������
        for (int j = 0; j < n; j++) {
            cout << data[i].d[j] << "  ";
        }
        cout << endl;
    }
    infile.close();//�ر��ļ�
}

//////////////��ʼ������//////////////////////////////
void Init_center() {
    for (int i = 0; i < k; i++) {
        cout << "��ʼ����" << i + 1 << ":" << endl;
        for (int j = 0; j < n; j++) {
            td.center[i].d[j] = data[i].d[j];
            cout << td.center[i].d[j] << "  ";
        }
        cout << endl;
    }
}


///////�������ݵ�K�����ĵ�ŷ����¾���//////////

void calculate_distance() {
    int i, j;
    for (i = 0; i < size; i++)
        for (j = 0; j < k; j++) {
            data[i].distance[j] = Euclid(i, j);   //i��ʾ�ڼ�������j��ʾ����ڼ�������
        }
}

//////////����һ�����鵽���ĵ�ŷ����þ���//////////////
double Euclid(int x, int y) {
    double distance = 0;
    for (int i = 0; i < n; i++) {
        distance += pow((data[x].d[i] - td.center[y].d[i]), 2);
    }
    distance = sqrt(distance);
    return distance;
}

//////////�����ݽ��дع���///////////////////
void new_cluster() {
    int i, j;
    double min;
    for (i = 0; i < k; i++)      //��ʼ�����
        td.cluster_num[i] = 0;
    for (i = 0; i < size; i++) {
        int index = 0;              //�ҳ���С��ŷ����¾�����
        min = data[i].distance[0];
        for (j = 1; j < k; j++) {     // ɸѡ������ŷ�������С��ֵ
            if (data[i].distance[j] < min) {
                min = data[i].distance[j];
                index = j;
            }
        }
        //���ִؼ�
        td.cluster[index][td.cluster_num[index]++] = i;
    }
}

///////////��������///////////////////////////////
void new_center() {
    int i, j, m;
    double sum;


    for (i = 0; i < k; i++)
        for (j = 0; j < n; j++) {
            sum = 0;
            td.old_center[i].d[j] = td.center[i].d[j];
            for (m = 0; m < td.cluster_num[i]; m++) {
                // ��i���صĵ�jά�����������ݺ�
                sum += data[td.cluster[i][m]].d[j];
            }
            // ȡƽ�����õ��µĴ�����
            td.center[i].d[j] = sum / td.cluster_num[i];
        }
}

////////�Ƚ�����////////////////////////

void comp() {
    int i, j, m = 0;
    new_center();
    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {

            if (td.old_center[i].d[j] != td.center[i].d[j]) td.isend[i][n] = 0;
            else td.isend[i][n] = 1;
        }
    }
    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            td.is = td.isend[i][n] * td.is;
        }
    }
    if (td.is == 0)td.is = 1;
    else td.is = 0;

}
////����������/////////////////

void output_info() {
    int i, j, m;

    for (i = 0; i < k; i++) {

        cout << "����" << i + 1 << ":" << endl;
        for (m = 0; m < n; m++)
            cout << td.center[i].d[m] << "  ";
        cout << endl;

        cout << "����" << i + 1 << ":" << endl;
        for (j = 0; j < td.cluster_num[i]; j++) {
            for (m = 0; m < n; m++) {

                cout << data[td.cluster[i][j]].d[m] << "  ";
            }
            cout << endl;
        }
    }
}

int main() {
    int count = 0;
    Init();
    Init_center();
    td.is = 1;

    while (td.is) {
        calculate_distance();
        new_cluster();

        count++;
        cout << "______________________________________________________" << endl;
        cout << "��" << count << "�ξ��ࣺ" << endl;
        output_info();
        comp(); //�Ƚ�����
    }

    system("PAUSE ");
    return 0;
}