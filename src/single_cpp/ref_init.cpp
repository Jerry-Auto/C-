#include<iostream>
void test(int c,int d);
void show_ref();
int main(int argc, char const *argv[])
{
    using namespace std;

    
    int x=10,y=20;
    int& refx=x;
    cout<<&refx<<"\n";
    cout<<&x<<"\n";    
    int*pt=&refx;
    cout<<pt<<"\n";
    pt=&y;
    cout<<pt<<"\n";
    cout<<&y<<"\n";

    //show_ref();
    //test(x,y);
    return 0;

}

void test(int x,int y)
{
    int z=30;
    if(not(x>y) or y<z){
        std::cout<<"计算正确\n";
    }
    char in;
    std::cin.get(in);
    switch (in)
    {
    case 'a':
        {std::cout<<"right\n";
        std::cout<<"right";}
        break;
    
    default:
        break;
    }
    

}
void show_ref(){
    using namespace std;
    int x=10,y=20,z=30;
    cout<<"x,y,z="<<x<<" "<<y<<" "<<z<<endl;
    int& refx=x;
    cout<<"int & refx=x; refx=="<<refx<<endl;
    refx=y;
    cout<<"refx=y , refx=="<<refx<<endl;
    cout<<"x="<<x<<endl;
    refx=40;
    cout<<"refx=40; refx=="<<refx<<endl;
    cout<<"y="<<y<<endl;
    cout<<"x="<<x<<endl;
    x=50;
    cout<<"x=50; refx=="<<refx<<endl;
    cout<<"y="<<y<<endl;
    cout<<"x="<<x<<endl;
}
