#include <QCoreApplication>
#include <vector>
#include <iostream>
/*
 * ���� �� ������ ��אַ㣮�쭮� ������, ����� �����६���� ����� �������訬� � ᢮�� ��ப� � �������訬�
 * � ᢮�� �⮫�� ��� �������. �������� � �⤥���� ��ப�� ����樨 ᥤ����� �祪 ? ����� ��ப� � �⮫��
 * ���� ���� - ������⢮ ��ப � �⮫�殢 ��ன ���� - ᠬ� �����
*/

using std::vector;
using std:cout;

#define Print(M){for (unsigned j=0;j<nr;j++) {for (unsigned i=0;i<nc;i++) printf("%d ",Matr[i][j]);printf("\n");}}

void test_matr()
{
    vector<unsigned> max_r;
    vector<int> min_r,max_c,min_c;
    int **Matr;
    unsigned nc,nr;
    printf("Enter nc & nr\n");
    scanf("%d %d",&nc,&nr);
    Matr=new int*[nc];
    for (unsigned i=0;i<nc;i++) Matr[i]=new int[nr];
    printf("Enter Matr\n");
    for (unsigned j=0;j<nr;j++) for (unsigned i=0;i<nc;i++) scanf("%d",&Matr[i][j]);
    Print(Matr);
    for (unsigned j=0;j<nr;j++) // ��� ��� ��ப
    {
        unsigned pmin=0,pmax=0;
        int min=Matr[0][j],max=Matr[0][j];
        for (unsigned i=1;i<nc;i++)     // �� �ᥬ ��������
            if (min>Matr[i][j]) {min=Matr[i][j];pmin=i;}
            else
            if (max<Matr[i][j]) {max=Matr[i][j];pmax=i;}
        max_r.push_back(max); max_c.push_back(pmax);
        min_r.push_back(min); min_c.push_back(pmin);
        
    }
    // output
    for (unsigned j=0;j<nr;j++) printf("%d %d %d\n",j,max_r[j],max_c[j]);
    cout<<"\n";
    for (unsigned j=0;j<nr;j++) printf("%d %d %d\n",j,min_r[j],min_c[j]);



}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test_matr();

    return a.exec();
}
