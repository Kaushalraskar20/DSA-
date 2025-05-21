#include<iostream>
using namespace std;

class history{
    string sites[5];
    string nextsite[5];
    int top,top1,top2;
    public:
    history(){
        top1=-1;
        top2=-2;
        top=top2;
    }
    void visitedpage(string link){
        if(top1<5){
            top1++;
            sites[top1]=link;
        }
    }
    
    void negativeBack(){
        if(top1<0){
            cout<<"Stack is underflow"<<endl;
        }
         top2++;
            nextsite[top2] = sites[top1];
            top1--;
            cout<< sites[top1] <<endl;
    }
    void viewcurrentpage(){
        cout<<nextsite[top]<<endl;
    }
    void EmptyHist(){
        if(top1<0){
            cout<<"No History ";
        }
        else{
            printHistory1();
        }
    }
    void printHistory1(){
        for (int i =0;i<=top1;i++){
            cout<<sites[i]<<endl;
        }
    }
    void printHistory2(){
        for(int i=0;i<=top2;i++){
            cout<<nextsite[i]<<endl;
        }
    }
};
    int main(){
        history H1;
        H1.visitedpage("Netflix.com");
        H1.visitedpage("YT.com");
        H1.visitedpage("Google.com");
        H1.visitedpage("amazon.com");
        H1.visitedpage("leetcode.in");
        cout<<"resent history"<<endl;
        H1.printHistory1();
        cout<<"nevigated page"<<endl;
        H1.negativeBack();
        cout<<"nevigated page"<<endl;
       H1.negativeBack();
       cout<<"nevigated page"<<endl;
       
       cout<<"history 2"<<endl;
        H1.printHistory2();
        cout<<"current page"<<endl;
        H1.viewcurrentpage();
        cout<<"check the history is empty or not "<<endl;
        H1.EmptyHist();
    }
