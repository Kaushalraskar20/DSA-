#include<iostream>
using namespace std;

class Song{
    public:
    string Title;
    Song* nextSong;

    Song(){
        Title = " ";
        nextSong = NULL;
    }
    Song(string newTitle){
        Title = newTitle;
        nextSong = NULL;
    }
};
class Playlist{
    public:
    Song *firstSong = NULL;
    void  addSongAtFirst(string newTitle );
    void  addSongAtLast(string newTitle );
    void  addSongBet(string newTitle, int key);
    void  removeSongAtFirst( );
    void  removeSongAtLast();
    void  removeSongBet(int key);
    void  print();
};

void Playlist::addSongAtFirst(string newTitle ){
    Song *newSong = new Song(newTitle);
    if(firstSong == NULL){
        cout<<"List is Empty"<<endl;
        firstSong = newSong;
        return;
    }
    newSong->nextSong = firstSong;
    firstSong = newSong;
}
void Playlist::addSongAtLast(string newTitle ){
    Song* newSong = new Song(newTitle);
    Song* temp = firstSong;
    while(temp->nextSong != NULL){
        temp = temp->nextSong;
    }
    temp->nextSong = newSong;
}
void Playlist::addSongBet(string newTitle, int key){
    int pos=0;
    Song *newSong = new Song(newTitle);
    Song* temp = firstSong;
    while((pos+1) != key){
        temp = temp->nextSong;
        pos++;
    }
    newSong->nextSong = temp->nextSong;
    temp->nextSong = newSong;

}

void Playlist::removeSongAtFirst(){
    Song* temp = firstSong;
    firstSong = temp->nextSong;
    free(temp);
}
void Playlist::removeSongAtLast(){
    Song* last2nd = firstSong;
    while(last2nd->nextSong->nextSong != NULL){
        last2nd = last2nd->nextSong;
    }
    Song* temp = last2nd->nextSong;
    last2nd->nextSong = NULL;
    free(temp);
}
void Playlist::removeSongBet(int key){
    int pos = 0;
    Song* songAtpos = firstSong;

    while((pos+1) != key){
        if(key == 0){
            removeSongAtFirst();
            return;
        }
        songAtpos = songAtpos->nextSong; 
        pos++; 
    }
    Song* temp = songAtpos->nextSong;
    songAtpos->nextSong = songAtpos->nextSong->nextSong;
    free(temp);
}

void Playlist::print(){
    Song *temp = firstSong;
    while(temp != NULL){
        cout << temp->Title <<" --> ";
        temp = temp->nextSong;
    }
    cout<<"NULL"<<endl;
}

int main() {
    Playlist list;
    list.addSongAtFirst("Tu Janne Na");
    list.addSongAtFirst("Shape of you");
    list.addSongAtLast("Mera Mann");
    list.addSongAtLast("Tumhare hi rahenge hum");
    list.addSongBet("Khoobsurat", 2);
    list.removeSongAtFirst();
    list.removeSongAtLast();
    list.removeSongBet(1);
    cout<<"Songs are: "<<endl;
    list.print();
    cout<<endl;
    return 0;
}