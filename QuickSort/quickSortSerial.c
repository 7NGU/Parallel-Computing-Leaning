/*
*
*����:	quickSortSerial.c
*����:	quickSort�㷨����ʵ��
*���ߣ�	LeonWong
*ʱ�䣺2019-06-30
*
*/
#include <stdio.h>
#include <time.h>
#include <omp.h>
#include <stdlib.h>

/*
*���ܣ��������
*
*/
void print(double *x,int n)
{
    int i=0;
    for(;i<n;i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n");
}

/*
*���ܣ�������ŦԪ�ػ�������
*
*/
int partions(double l[],int low,int high)
{
    int middle=low;
    double flag=l[middle];
    while((low<high))
    {
        while(low<high&&l[high]>flag)
            high--;
        while(low<high&&l[low]<=flag)
            low++;
        if(low<high)
        {
            double temp=l[low];
            l[low]=l[high];
            l[high]=temp;
        }
    }
    double tp2=l[high];
    l[high]=l[middle];
    l[middle]=tp2;
    return low;
}

/*
*���ܣ��ݹ��������
*
*/
void qsortMe(double l[],int low,int high)
{
    int prvotloc;
    if(low<high)
    {
        prvotloc=partions(l,low,high);    //����һ������Ľ����Ϊ����
        qsortMe(l,low,prvotloc-1); //�ݹ�������� ��low ��prvotloc-1
        qsortMe(l,prvotloc+1,high); //�ݹ�������� �� prvotloc+1�� high
    }
}

void quicksort(double l[],int n)
{
    qsortMe(l,0,n-1); //��һ����Ϊ���� ���ӵ�һ���ŵ���n��
}

void main()
{
    FILE   *finput;
    finput = fopen("sortData.dat","r");
    if (finput == NULL)
    {
        printf("Data file gauss.dat not found\n");
        return(-1);
    }
    int n;
    fscanf(finput, "%d",&n);
    printf("sacle=%dx\n",n);
    double *ax;
    int j;
    ax=malloc(n*sizeof(double));
    double input;
    for (j=0; j<n; j++)
    {
        fscanf(finput,"%d",&input);
        ax[j] = input;
    }

	clock_t start,end; 
	double time=0;
	start=clock();
    printf("\n");

    quicksort(ax,n);

    end=clock();
	time=(double)(end-start)/CLOCKS_PER_SEC;

	printf("\nThis time quickSortSerial.exe runtime=%lf\n\n",time);
}
