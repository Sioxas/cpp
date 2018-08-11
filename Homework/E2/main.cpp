#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;
class Sales_n
{
public:
    string serial;
    int market;
    char date[10];
    int sn;
    int id;
    float num;
    float price;
};

int main()
{
    char name1[50],name2[50];
    ifstream infile;
    cout<<"输入实验一中经过预处理的数据文件：fl2.txt"<<endl;
    cin>>name1;
    infile.open(name1,ios::in);
    /*string contents;*/
    if(infile.fail())
        cout << "error open!" << endl;
    cout<<"输入实验二要保存的存有数据立方体的文件名：cube3.txt"<<endl;
    cin>>name2;
    ofstream outfile;
    outfile.open(name2,ios::out);
    if(!outfile)
    {
        cout<<"open eror!"<<endl;
        exit(1);
    }
    Sales_n sal[10000];
    int sal_size=0;
    int i=sal_size;
    float total[3][10][5]={0};
    while(!infile.eof())
    {
        infile >> sal[sal_size].serial >> sal[sal_size].market >> sal[sal_size].date>> sal[sal_size].sn>> sal[sal_size].id>> sal[sal_size].num>> sal[sal_size].price;
        cout<<"i: "<<i<<endl;
        for (int k=0;k<3;k++)   //此for循环默认店号是从1019连续增加的3个整数
        {
            int Km=1019+k;
//            cout<<"Km: "<<Km<<endl;
            if (sal[i].market==Km)
            {
                char p= sal[i].date[7];
                if(sal[i].id/100==10010 )
                {
                    switch(p)
                    {
                        case '3':total[k][0][0]+=sal[i].num*sal[i].price;break;
                        case '4':total[k][1][0]+=sal[i].num*sal[i].price;break;
                        case '5':total[k][2][0]+=sal[i].num*sal[i].price;break;
                        case '6':total[k][3][0]+=sal[i].num*sal[i].price;break;
                        case '7':total[k][4][0]+=sal[i].num*sal[i].price;break;
                        case '8':total[k][5][0]+=sal[i].num*sal[i].price;break;
                        case '9':total[k][6][0]+=sal[i].num*sal[i].price;break;
                    }
                }
                if(sal[i].id/100==10020 )
                {
                    switch(p)
                    {
                        case '3':total[k][0][1]+=sal[i].num*sal[i].price;break;
                        case '4':total[k][1][1]+=sal[i].num*sal[i].price;break;
                        case '5':total[k][2][1]+=sal[i].num*sal[i].price;break;
                        case '6':total[k][3][1]+=sal[i].num*sal[i].price;break;
                        case '7':total[k][4][1]+=sal[i].num*sal[i].price;break;
                        case '8':total[k][5][1]+=sal[i].num*sal[i].price;break;
                        case '9':total[k][6][1]+=sal[i].num*sal[i].price;break;
                    }
                }
                if(sal[i].id/100==10030)
                {
                    switch(p)
                    {
                        case '3':total[k][0][2]+=sal[i].num*sal[i].price;break;
                        case '4':total[k][1][2]+=sal[i].num*sal[i].price;break;
                        case '5':total[k][2][2]+=sal[i].num*sal[i].price;break;
                        case '6':total[k][3][2]+=sal[i].num*sal[i].price;break;
                        case '7':total[k][4][2]+=sal[i].num*sal[i].price;break;
                        case '8':total[k][5][2]+=sal[i].num*sal[i].price;break;
                        case '9':total[k][6][2]+=sal[i].num*sal[i].price;break;
                    }
                }
                else if(sal[i].id/100==10088)
                {
                    switch(p)
                    {
                        case '3':total[k][0][3]+=sal[i].num*sal[i].price;break;
                        case '4':total[k][1][3]+=sal[i].num*sal[i].price;break;
                        case '5':total[k][2][3]+=sal[i].num*sal[i].price;break;
                        case '6':total[k][3][3]+=sal[i].num*sal[i].price;break;
                        case '7':total[k][4][3]+=sal[i].num*sal[i].price;break;
                        case '8':total[k][5][3]+=sal[i].num*sal[i].price;break;
                        case '9':total[k][6][3]+=sal[i].num*sal[i].price;break;
                    }
                }
            }
        }
        if (sal_size<5000)
        {
            sal_size++;
            i=sal_size;
        }
        else
        {
            sal_size=0;
            i=sal_size;
        }
        //cout<<"sal_size++="<<sal_size<<endl;
    }
    //sal.clear();//?????????????

    if (outfile)
    {
        for (int kk=0;kk<3;kk++)
        {
            cout<<"kk"<<kk<<endl;
            cout<<"销售日期"<<'\t'<<"10010油 "<<"10020面制品 "<<"10030米和粉 "<<"10088粮油类赠品 "<<endl;
            int j = 20030413;//
            for (int i=0;i<7;++i)
            {
                outfile<<" "<< total[kk][i][0]<<'\t'<<total[kk][i][1]<<'\t'<<total[kk][i][2]<<'\t'<<total[kk][i][3]<<'\t'<<endl;
                cout<<j<<" "<< total[kk][i][0]<<'\t'<<total[kk][i][1]<<'\t'<<total[kk][i][2]<<'\t'<<total[kk][i][3]<<'\t'<<endl;
                j++;
            }
        }
    }
    else
        cerr<<"无法打开文件！"<<endl;

    float total2[3][10]={0};
    ifstream infile2("cube3.txt",ios::in);
    int m=0;
    while(!infile2.eof())
    {
        infile2 >> total2[m][0] >> total2[m][1] >>total2[m][2]>>total2[m][3];
        m++;
    }
    if(infile2.fail())
    {
        cout << "error open!" << endl;
    }
    float sum=0.0;
    for(int i=0;i<7;++i)
    {
        sum+=total2[i][2];
    }
    cout<<"2020号商铺10010油类商品14日销售额为："<<total2[1][0]<<endl;
    cout<<"2020号商铺10030米和粉类商品销售总额为："<<sum<<endl;
    infile.close();//关闭文件
    outfile.close();//关闭文件
    system( "PAUSE ");
}
