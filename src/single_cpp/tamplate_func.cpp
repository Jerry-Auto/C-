#include<iostream>
using namespace std;
struct job
{
    char name[40];
    double salary;
    int floor;
};

void Swap(job& a,job&b);

template <typename T>
void Swap(T* a,T* b,int n);

template <typename T>
void Swap(T& a,T&b);

template<> void Swap<job>(job& j1,job& j2);
//template<> void Swap(job&,job&);//也可以


template <typename T>
T Add_to_a(T a,T b);

template void Swap<char>(char&a,char&b);

template <typename T>
void show(T data[]);
void show_job(const job& job);
const int Lim=8;
int main()
{
    
    cout<<"--------------------"<<endl;  
    cout<<"交换int:"<<endl;  
    {int i=10,j=20;
    cout<<"i,j="<<i<<"\t"<<j<<endl;
    cout<<"after swap:"<<endl;  
    Swap(i,j);
    cout<<"i,j="<<i<<"\t"<<j<<endl;
    };
    cout<<"--------------------"<<endl;  
    cout<<"交换double:"<<endl;  
    {double i=10,j=20;
    cout<<"i,j="<<i<<"\t"<<j<<endl;
    cout<<"after swap:"<<endl;  
    Swap(i,j);
    cout<<"i,j="<<i<<"\t"<<j<<endl;
    };
    cout<<"--------------------"<<endl;  
    cout<<"交换数组:"<<endl;  
    {int d1[Lim]={0,7,0,4,1,7,7,6};
    int d2[Lim]={0,7,2,0,1,9,6,9};
    show(d1);
    show(d2);
    Swap(d1,d2,Lim);
    cout<<"after swap:"<<endl;    
    show(d1);
    show(d2);}

    cout<<"--------------------"<<endl;  
    cout<<"交换结构体:"<<endl;  
    {job sue={"susan",10001.5,6};
    job sidney={"sidney",30201.5,10};
    show_job(sue);
    show_job(sidney);
    Swap(sue,sidney);//调用非模板
    Swap<job>(sue,sidney);//调用显示具体化
    cout<<"after swap:"<<endl;  
    show_job(sue);
    show_job(sidney);}

    cout<<"--------------------"<<endl;  
    cout<<"显示实例化处理类型不匹配:"<<endl;  
    {short i=1;
    int j=5;
    //显示实例化
    double c=Add_to_a<double>(i,j);
    cout<<c<<endl;  
    }


    return 0;
}

//优先级最高
void Swap(job& j1,job&j2)
{
    double ts,tf;
    ts=j1.salary;
    j1.salary=j2.salary;
    j2.salary=ts;

    tf=j1.floor;
    j1.floor=j2.floor;
    j2.floor=tf;
}

template <typename T>
void Swap(T& a,T&b)
{
    T temp;
    temp=a;
    a=b;
    b=temp;
}

//模板函数重载
template <typename T>
void Swap(T* a,T* b,int n)
{
    T temp;
    for(int i=0;i<n;++i)
    {
        temp=a[i];
        a[i]=b[i];
        b[i]=temp;
    }
}

//显示具体化，<job>可以不要
template<> void Swap<job>(job& j1,job& j2){
    double ts,tf;
    ts=j1.salary;
    j1.salary=j2.salary;
    j2.salary=ts;

    tf=j1.floor;
    j1.floor=j2.floor;
    j2.floor=tf;
}

template <typename T>
void show(T data[])
{
    
    for(int i=0;i<Lim;++i)
    {
        if(i==2)
        cout<<"/";
        if(i==4)
        cout<<"/";
        cout<<data[i];
    }
    cout<<endl;
}

void show_job(const job& job){
    cout<<job.name<<":\t$"<<job.salary<<"\ton floor:"<<job.floor<<endl;
}

template <typename T>
T Add_to_a(T a,T b){
    return a+b;
}